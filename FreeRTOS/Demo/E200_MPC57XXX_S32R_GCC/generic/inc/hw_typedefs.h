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

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /* hw register access macros */
    #define HWREG32(address) (*(volatile unsigned int   *)(address)) /* 32-bit register */
    #define HWREG16(address) (*(volatile unsigned short *)(address)) /* 16-bit register */
    #define HWREG8(address)  (*(volatile unsigned char  *)(address)) /*  8-bit register */

    typedef volatile signed char vint8_t;
    typedef volatile unsigned char vuint8_t;

    typedef volatile signed short vint16_t;
    typedef volatile unsigned short vuint16_t;

    typedef volatile signed int vint32_t;
    typedef volatile unsigned int vuint32_t;

#ifdef __cplusplus
}
#endif

#endif
