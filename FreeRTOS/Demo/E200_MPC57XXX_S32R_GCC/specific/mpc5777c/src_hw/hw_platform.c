/*-----------------------------------------------------------
 *
 *  Copyright 2018 NXP
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/
 * or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 *----------------------------------------------------------*/

#include "hw_platform.h"

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
    uint32_t core_ID;
    GET_CORE_ID(core_ID);
    if ((vectorNum >= HWINTC_INTERRUPTS) || (OSINTCInputBit(vectorNum) == 0U))
    {
        /* INTC input with given number is not implemented */
        return;
    }

    /* Set the function pointer in the ISR Handler table */
    OSInterruptsHandlerTable[vectorNum] = handlerFn;

    /* select Core0 as interrupt destination and set the priority */
    HWINTC_PSR(vectorNum) = HWINTC_SET_PRC_SEL(core_ID) | Priority;

}


void OS_PlatformInit(void)
{
    unsigned int i;
    uint32_t core_ID;
    GET_CORE_ID(core_ID);
    /* clean interrupt controller */
    for (i=0; i<HWINTC_INTERRUPTS; i++)
    {
        OSInterruptsHandlerTable[ i ] = OS_UnusedInterruptHandler;
        OS_DisableINTCInput(i);
    }

    HWINTC_MCR = HWINTC_MCR & HWINTC_MCR_HVEN_SW(core_ID); /* clear HVEN - software mode */

    HWINTC_IACKR(core_ID) = 0x0U; /* set INTC ISR vector table base addr to 0x0000000 as we don't use this field */

    HWINTC_CPR(core_ID) = 0x0; /* current priority level set to 0x0 */

    HWINTC_IACKR(core_ID) = (uint32_t)&OSInterruptsHandlerTable;
}

void prvPortTimerSetup(void* paramF, uint32_t tick_interval)
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
#define STM_BASE            0xFC068000
#define WRITE_STM_REG(offset, value)        { *(volatile uint32_t*)(STM_BASE + (offset)) = (uint32_t)(value); }
#define READ_STM_REG(offset)                *(volatile uint32_t*)(STM_BASE + (offset))

void stmOpen(uint32_t delta, uint32_t channel)
{
    WRITE_STM_REG(0, 2);    // freeze in debugging mode;
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
