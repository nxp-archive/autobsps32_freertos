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
#ifndef GENERIC_TIMER_H
#define GENERIC_TIMER_H

#include <access_macros.h>

/* timer support routines */
#define SYSTYMER_GET_CNTFRQ __MRC(15, 0, 14, 0, 0)
#define SYSTYMER_SET_CNTFRQ(val) __MCR(15, 0, (val), 14, 0, 0)
#define SYSTIMER_GET_CNTPCT __MRRC(15, 0, 14)
#define SYSTIMER_GET_CNTKCTL __MRC(15, 0, 14, 1, 0)
#define SYSTIMER_SET_CNTKCTL(val) __MCR(15, 0, (val), 14, 1, 0)
#define SYSTIMER_GET_CNTP_TVAL __MRC(15, 0, 14, 2, 0)
#define SYSTIMER_SET_CNTP_TVAL(val) __MCR(15, 0, (val), 14, 2, 0)
#define SYSTIMER_GET_CNTP_CTL __MRC(15, 0, 14, 2, 1)
#define SYSTIMER_SET_CNTP_CTL(val) __MCR(15, 0, (val), 14, 2, 1)
#define SYSTIMER_GET_CNTV_TVAL __MRC(15, 0, 14, 3, 0)
#define SYSTIMER_SET_CNTV_TVAL(val) __MCR(15, 0, (val), 14, 3, 0)
#define SYSTIMER_GET_CNTV_CTL __MRC(15, 0, 14, 3, 1)
#define SYSTIMER_SET_CNTV_CTL(val) __MCR(15, 0, (val), 14, 3, 1)
#define SYSTIMER_GET_CNTVCT __MRRC(15, 1, 14)
#define SYSTIMER_GET_CNTP_CVAL __MRRC(15, 2, 14)
#define SYSTIMER_SET_CNTP_CVAL(val, val2) __MCRR(15, 2, (val), (val2), 14)
#define SYSTIMER_GET_CNTV_CVAL __MRRC(15, 3, 14)
#define SYSTIMER_SET_CNTV_CVAL(val, val2) __MCRR(15, 3, (val), (val2), 14)
#define SYSTIMER_GET_CNTVOFF __MRRC(15, 4, 14)
#define SYSTIMER_SET_CNTVOFF(val, val2) __MCRR(15, 4, (val), (val2), 14)
#define SYSTIMER_GET_CNTHCTL __MRC(15, 4, 14, 1, 0)
#define SYSTIMER_SET_CNTHCTL(val) __MCR(15, 4, (val), 14, 1, 0)
#define SYSTIMER_GET_CNTHP_TVAL __MRC(15, 4, 14, 2, 0)
#define SYSTIMER_SET_CNTHP_TVAL(val) __MCR(15, 4, (val), 14, 2, 0)
#define SYSTIMER_GET_CNTHP_CTL __MRC(15, 4, 14, 2, 1)
#define SYSTIMER_SET_CNTHP_CTL(val) __MCR(15, 4, (val), 14, 2, 1)
#define SYSTIMER_GET_CNTHP_CVAL __MRRC(15, 6, 14)
#define SYSTIMER_SET_CNTHP_CVAL(val, val2) __MCRR(15, 6, (val), (val2), 14)

/*
CNTP_CTL, Counter-timer Physical Timer Control register fields
*/
#define ENABLE                  (1 << 0)
#define IMASK                   (1 << 1)
#define ISTATUS                 (1 << 2)

extern void vUpdateTimer(void);
extern void prvSetupTimerInterrupt(void);

#endif /* GENERIC_TIMER_H */