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
#include <stdint.h>
#include "generic_timer.h"
#include "gicv3.h"
#include "FreeRTOSConfig.h"

extern void SysTick_Handler(void);
extern void vInitInterruptTable(int, void*);

#define TIMER_INT_ID        30

void vUpdateTimer(void)
{
    uint64_t cnt_val = SYSTIMER_GET_CNTPCT;
    uint32_t val, val2;
    cnt_val += (uint64_t)OS_TICK;
    val = cnt_val;
    val2 = (cnt_val >> 32);
    SYSTIMER_SET_CNTP_CVAL(val, val2);
}

void prvSetupTimerInterrupt(void)
{
    uint64_t cnt_val = SYSTIMER_GET_CNTPCT;
    uint32_t val, val2;
    cnt_val += (uint64_t)OS_TICK;
    val = cnt_val;
    val2 = (cnt_val >> 32);
    SYSTIMER_SET_CNTP_CVAL(val, val2);
    vInitInterruptTable(TIMER_INT_ID, SysTick_Handler);
    SYSTIMER_SET_CNTP_CTL(SYSTIMER_GET_CNTP_CTL | ENABLE);
    vGicEnableInterrupt(TIMER_INT_ID, 1);
}