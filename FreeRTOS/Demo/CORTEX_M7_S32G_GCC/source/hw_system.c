/*
 * Copyright 2019 NXP.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#include <hw_system.h>

unsigned long SystemCoreClock = 100000000UL;

#define BASE_ADDRESS_MC_ME      0x40088000u
#define MC_ME_CTL_KEY           *(volatile unsigned int*)(BASE_ADDRESS_MC_ME + 0x000u)
#define MC_ME_PRTN0_PCONF       *(volatile unsigned int*)(BASE_ADDRESS_MC_ME + 0x100u)
#define MC_ME_PRTN0_PUPD        *(volatile unsigned int*)(BASE_ADDRESS_MC_ME + 0x104u)

/*
 * system initialization : system clock, interrupt router ...
 */
void SystemInit(void)
{

    #if defined(OS_FOR_VDK)
    /* SWT4 is not available in the FPGA thus it can be disabled */
    volatile swt_t * SWT4 = (volatile swt_t *)SWT4_BASE;
    #endif

    /* route all interrupts to cores */
    IR_ROUTE_ALL_2_CPU( IR_ROUTE_2_CPU3 | IR_ROUTE_2_CPU2 | IR_ROUTE_2_CPU1 | IR_ROUTE_2_CPU0);

    /* Disable SWT_4 - enabled at reset by default */
    #if defined(OS_FOR_VDK)
    /* SWT4 is not available in the FPGA thus it can be disabled */
        SWT4->SR = SWT_UNLOCK_SEQ1_U32;
        SWT4->SR = SWT_UNLOCK_SEQ2_U32;
        SWT4->CR = SWT4->CR & ~SWT_WDG_ENABLED_U32;
    #endif

    /* enable clock for both FTMs */
    MC_ME_PRTN0_PUPD = 0x1; /* PCUD */
    MC_ME_PRTN0_PCONF = 0x1; /* PCE */
    MC_ME_CTL_KEY = 0x5AF0;
    MC_ME_CTL_KEY = 0xA50F;


}


/*
 * if needed
 */
void SetPLL(void)
{


}
