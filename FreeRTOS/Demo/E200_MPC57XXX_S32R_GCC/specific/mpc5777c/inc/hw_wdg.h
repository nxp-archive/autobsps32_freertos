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

#ifndef HW_WDG_H
#define HW_WDG_H

#include "hw_typedefs.h"
#include "hw_base.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /*****Watchdog *****/
    #define HWSWT_BASE_ADDR(coreId)     (HWSWT0_BASE_ADDR + (coreId << 14U)) /* Core0 -> SWT0 */
    #define SWT_SR_R(coreId)  HWREG32(HWSWT_BASE_ADDR(coreId) + 0x10U)
    #define SWT_CR_R(coreId)  HWREG32(HWSWT_BASE_ADDR(coreId))

    /* Access the WatchDog for the other cores */
    #define HWWatchdogDisable(coreId) do { \
            SWT_SR_R(coreId) = 0xc520;     \
            SWT_SR_R(coreId) = 0xd928;     \
            SWT_CR_R(coreId) = 0xFF00010A; \
    } while (0)

#ifdef __cplusplus
}
#endif

#endif  /* HW_WDG_H */

