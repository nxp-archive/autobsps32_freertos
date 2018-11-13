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

#ifndef PLATFORM_H
#define PLATFORM_H

#include "hw_clock.h"
#include "hw_gpio.h"
#include "hw_intc.h"
#include "hw_pit.h"
#include "hw_wdg.h"

#ifdef __cplusplus
extern "C" {
#endif

    #define GetSPR(dest, spr)    __asm__ volatile ("mfspr %0, %1" : "=r" (dest) : "i" (spr))
    #define SetSPR(spr, src)     __asm__ volatile ("mtspr %0, %1" : : "i" (spr), "r" (src))

    #define GET_CORE_ID(result)     GetSPR(result,286)
    #define OSMSYNC  asm("msync\n")

    /* interrupt handlers type */
    typedef void(*OSInterruptHandlerPtr)(void);
    /* for unused/unexpected interrupts */
    void prvPortTimerSetup(void* paramF, uint32_t tick_interval);
    void resetTimer(void);
    void OS_UnusedInterruptHandler(void);
    void OS_InstallInterruptHandler(OSInterruptHandlerPtr handlerFn, unsigned int vectorNum, unsigned char Priority);
    void OS_DisableINTCInput (unsigned int vectorNum);
    void OS_PlatformInit(void);
    void stmOpen(uint32_t, uint32_t);
    void stmUpdate(uint32_t, uint32_t);

#ifdef __cplusplus
}
#endif

#endif /* PLATFORM_H */
