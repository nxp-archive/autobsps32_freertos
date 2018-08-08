/*
 *
 * Copyright 2018 NXP
 *
 * File:        arm_cm4.c
 * Purpose:     Generic high-level routines for ARM Cortex M4 processors
 *
 * Notes:
 */

#include "common.h"

/***********************************************************************/
/*
 * Configures the ARM system control register for STOP (deep sleep) mode
 * and then executes the WFI instruction to enter the mode.
 *
 * Parameters:
 * none
 *
 * Note: Might want to change this later to allow for passing in a parameter
 *       to optionally set the sleep on exit bit.
 */

void stop (void)
{
    /* Set the SLEEPDEEP bit to enable deep sleep mode (STOP) */
    FSL_SCB->SCR |= FSL_SCB_SCR_SLEEPDEEP_MASK;

    /* WFI instruction will start entry into STOP mode */
    asm("WFI");
}
/***********************************************************************/
/*
 * Configures the ARM system control register for WAIT (sleep) mode
 * and then executes the WFI instruction to enter the mode.
 *
 * Parameters:
 * none
 *
 * Note: Might want to change this later to allow for passing in a parameter
 *       to optionally set the sleep on exit bit.
 */

void wait (void)
{
    /* Clear the SLEEPDEEP bit to make sure we go into WAIT (sleep) mode instead
     * of deep sleep.
     */
    FSL_SCB->SCR &= ~FSL_SCB_SCR_SLEEPDEEP_MASK;

    /* WFI instruction will start entry into WAIT mode */
    asm("WFI");
}
/***********************************************************************/
/*
 * Change the value of the vector table offset register to the specified value.
 *
 * Parameters:
 * vtor     new value to write to the VTOR
 */

void write_vtor (int vtor)
{
    /* Write the VTOR with the new value */
    FSL_SCB->VTOR = vtor;
}
/***********************************************************************/
/*
 * Initialize the NVIC to enable the specified IRQ.
 *
 * NOTE: The function only initializes the NVIC to enable a single IRQ.
 * Interrupts will also need to be enabled in the ARM core. This can be
 * done using the EnableInterrupts macro.
 *
 * Parameters:
 * irq    irq number to be enabled (the irq number NOT the vector number)
 */

void enable_irq (int irq)
{
    int div;

    /* Determine which of the NVICISERs corresponds to the irq */
    div = irq/32;

    switch (div)
    {
        case 0x0:
            FSL_NVIC->ICPR[0] = 1 << (irq%32);
            FSL_NVIC->ISER[0] = 1 << (irq%32);
            break;
        case 0x1:
            FSL_NVIC->ICPR[1] = 1 << (irq%32);
            FSL_NVIC->ISER[1] = 1 << (irq%32);
            break;
        case 0x2:
            FSL_NVIC->ISER[2] = 1 << (irq%32);
            FSL_NVIC->ISER[2] = 1 << (irq%32);
            break;
    }
}
/***********************************************************************/
/*
 * Initialize the NVIC to disable the specified IRQ.
 *
 * NOTE: The function only initializes the NVIC to disable a single IRQ.
 * If you want to disable all interrupts, then use the DisableInterrupts
 * macro instead.
 *
 * Parameters:
 * irq    irq number to be disabled (the irq number NOT the vector number)
 */

void disable_irq (int irq)
{
    int div;

    /* Determine which of the NVICICERs corresponds to the irq */
    div = irq / 32;

    switch (div)
    {
        case 0x0:
            FSL_NVIC->ICER[0] = 1 << (irq%32);
            break;
        case 0x1:
            FSL_NVIC->ICER[1] = 1 << (irq%32);
            break;
        case 0x2:
            FSL_NVIC->ICER[2] = 1 << (irq%32);
            break;
    }
}
/***********************************************************************/
/*
 * Initialize the NVIC to set specified IRQ priority.
 *
 * NOTE: The function only initializes the NVIC to set a single IRQ priority.
 * Interrupts will also need to be enabled in the ARM core. This can be
 * done using the EnableInterrupts macro.
 *
 * Parameters:
 * irq    irq number to be enabled (the irq number NOT the vector number)
 * prio   irq priority. 0-15 levels. 0 max priority
 */

void set_irq_priority (int irq, int prio)
{
    /*irq priority pointer*/
    uint8 *prio_reg;

    /* Determine which of the NVICIPx corresponds to the irq */
    prio_reg = (uint8 *)(((uint32)&FSL_NVIC->IP[0]) + irq);
    /* Assign priority to IRQ */
    *prio_reg = ( (prio&0xF) << (8 - ARM_INTERRUPT_LEVEL_BITS) );
}
/***********************************************************************/
