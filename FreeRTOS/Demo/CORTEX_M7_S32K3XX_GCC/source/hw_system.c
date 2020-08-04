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

unsigned long SystemCoreClock = 24000000UL;


/*================================================================================================*/
/**
* @brief Sys_GetCoreID
* @details Function used to get the ID of the currently executing thread
*/
/*================================================================================================*/
uint32_t Sys_GetCoreID(void)
{
    return (MSCM->CPXNUM & MSCM_CPXNUM_CPN_MASK);
}

/*
* system initialization : system clock, interrupt router ...
*/
void SystemInit(void)
{
    uint32_t i;
    uint32_t coreMask;
    uint32_t coreId = Sys_GetCoreID();

    switch(coreId)
    {
        case CM7_0:
            coreMask = (1UL << MSCM_IRSPRC_M7_0_SHIFT);
            break;
        case CM7_1:
            coreMask = (1UL << MSCM_IRSPRC_M7_1_SHIFT);
            break;
        default:
            coreMask = 0UL;
            break;
    }

    /* Configure MSCM to enable/disable interrupts routing to Core processor */
    for (i = 0; i < MSCM_IRSPRC_COUNT; i++) 
    {
        MSCM->IRSPRC[i] |= coreMask;
    }

}

/*
* if needed
*/
void SetPLL(void)
{

}
