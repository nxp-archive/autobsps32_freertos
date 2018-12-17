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

#ifndef HW_BASE_H
#define HW_BASE_H

#include "cpudefs.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /* peripheral base addresses */
    #define HWINTC_BASE_ADDR   (0xFFF48000UL)
    #define HWPIT_BASE_ADDR    (0xC3FF0000UL)
    #define HWSWT0_BASE_ADDR   (0xFFF38000UL)
    #define HWSIU_BASE_ADDR    (0xC3F90000UL)
    #define HWPLLDIG_BASE_ADDR (0xFFE74000UL)


#ifdef __cplusplus
}
#endif

#endif  /* HW_BASE_H */

