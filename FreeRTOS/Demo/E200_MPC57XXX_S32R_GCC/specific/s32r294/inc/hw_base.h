/*-----------------------------------------------------------
 *
 *  Copyright 2020 NXP
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

#ifndef HW_BASE_H
#define HW_BASE_H

#include "cpudefs.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /* peripheral base addresses */
    #define HWGCM_BASE_ADDR    (0xFFFB0000UL)
    #define HWGPIO_BASE_ADDR   (0xFFFC0000UL)
    #define HWINTC_BASE_ADDR   (0xFC040000UL)
    #define HWME_BASE_ADDR     (0xFFFB8000UL)
    #define HWPIT_BASE_ADDR    (0xFFF84000UL)
    #define HWRGM_BASE_ADDR    (0xFFFA8000UL)
    #define HWSWT0_BASE_ADDR   (0xFC050000UL)

#ifdef __cplusplus
}
#endif

#endif  /* HW_BASE_H */
