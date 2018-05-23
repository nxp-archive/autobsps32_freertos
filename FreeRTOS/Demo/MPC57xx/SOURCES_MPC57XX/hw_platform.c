/*==================================================================================================
*
*   (c) Copyright 2015 Freescale Semiconductor Inc.
*   Copyright 2017-2018 NXP
*   
*   This program is free software; you can redistribute it and/or modify it under
*   the terms of the GNU General Public License (version 2) as published by the
*   Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.
*
*   ***************************************************************************
*   >>!   NOTE: The modification to the GPL is included to allow you to     !<<
*   >>!   distribute a combined work that includes FreeRTOS without being   !<<
*   >>!   obliged to provide the source code for proprietary components     !<<
*   >>!   outside of the FreeRTOS kernel.                                   !<<
*   ***************************************************************************
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*   
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
==================================================================================================*/

#include "hw_platform.h"
#include "hw_intc.h"
#include "FreeRTOS.h"
#include "cpudefs.h"

/* Macro to calculate bit value for given INTC input */
#define OSINTCInputBit(n) ( (unsigned int)(OsINTCInputs[(n)/8U] >> ((n)%8U)) & 0x1U )


OSInterruptHandlerPtr OSInterruptsHandlerTable[ HWINTC_INTERRUPTS ] __attribute__ ((aligned (4096)));


/* INTC has some unimplemented inputs (the registers PSR, PRC_SEL are not
   implemented for these inputs). Following array contains bit set where
   each bit corresponds to an INTC input with number of the bit.
   If the value of bit is 1 - INTC input is implemented, 0 - INTC input is
   not implemented */

const unsigned char OsINTCInputs[ HWINTC_INTERRUPTS ] = AVAL_INTC_TABLE;



void OS_UnusedInterruptHandler(void)
{
    while(1);
}


/******************************************************************************
 * Function:    OSDisableINTCInput
 * Description: Disables INTC input if implemented
 * Returns:     none
 * Notes:
 ******************************************************************************/
void OS_DisableINTCInput (unsigned int vectorNum)
{
    
    if ((vectorNum >= HWINTC_INTERRUPTS) || (OSINTCInputBit(vectorNum) == 0U))
    {
        /* INTC input with given number is not implemented */
        return;
    }
    
    HWINTC_SET_PSRX(vectorNum,0x0); /* prio level 0 */

    return;
}


/**
 * This function can be used to install an interrupt handler for a given
 * interrupt vector. It will also set the Priority Status Register for the
 * source to the one given
 */

void OS_InstallInterruptHandler(OSInterruptHandlerPtr handlerFn, unsigned int vectorNum, unsigned char Priority)
{

    if ((vectorNum >= HWINTC_INTERRUPTS) || (OSINTCInputBit(vectorNum) == 0U))
    {
        /* INTC input with given number is not implemented */
        return;
    }

    /* Set the function pointer in the ISR Handler table */
    OSInterruptsHandlerTable[vectorNum] = handlerFn;

    /* select Core0 as interrupt destination and set the priority */
    HWINTC_PSR(vectorNum) = (short unsigned int)((short unsigned int)0x8000 | (short unsigned int)Priority);
    
}




void OS_PlatformInit(void)
{
    unsigned int i;

    /* clean interrupt controller */
    for (i=0; i<HWINTC_INTERRUPTS; i++)
    {
        OSInterruptsHandlerTable[ i ] = OS_UnusedInterruptHandler;
        OS_DisableINTCInput(i);
    }

    HWINTC_MCR = HWINTC_MCR & 0xFFFFFFF0UL; /* clear HVEN0 - software mode */
    
    HWINTC_IACKR = 0x0U; /* set INTC ISR vector table base addr to 0x0000000 as we don't use this field */
    
    HWINTC_CPR = 0x0; /* current priority level set to 0x0 */
    
	HWINTC_IACKR = (uint32_t)&OSInterruptsHandlerTable;
}

void prvPortTimerSetup(OSInterruptHandlerPtr paramF, uint32_t tick_interval)
{
  OS_InstallInterruptHandler(paramF, HWPIT_GET_INTID(configUSE_PIT_CHANNEL), 1 /* priority */);

  HWPIT_MCR = HWPIT_MCR_FRZ; /* freeze bit on - stop while debugging */

  // PIT_LDVAL : tick period
  HWPIT_LDVAL(configUSE_PIT_CHANNEL) = tick_interval;

  // PIT_RTI_TCTRL: start channel, enable IRQ
  HWPIT_TCTRL(configUSE_PIT_CHANNEL) = HWPIT_TCTRL_TEN | HWPIT_TCTRL_TIE; 

}

void resetTimer(void)
{
	// clear PIT channel IRQ flag
	HWPIT_TFLG(configUSE_PIT_CHANNEL) = HWPIT_TFLG_TIF;
}


/** System timer module */
#define STM_BASE			0xFC068000
#define WRITE_STM_REG(offset, value)		{ *(volatile uint32_t*)(STM_BASE + (offset)) = (uint32_t)(value); }
#define READ_STM_REG(offset)				*(volatile uint32_t*)(STM_BASE + (offset))

void stmOpen(uint32_t delta, uint32_t channel)
{
	WRITE_STM_REG(0, 2);	// freeze in debugging mode;
	WRITE_STM_REG(16 + 16 * channel, 1); // enable channel
	WRITE_STM_REG(16 + 16 * channel + 4, 1); // clear interrupt
	WRITE_STM_REG(16 + 16 * channel + 8, delta);
	WRITE_STM_REG(0, 3);
}

void stmUpdate(uint32_t delta, uint32_t channel)
{
	uint32_t val = READ_STM_REG(16 + 16 * channel + 8);
	WRITE_STM_REG(16 + 16 * channel + 8, delta + val);
	WRITE_STM_REG(16 + 16 * channel + 4, 1);
}
