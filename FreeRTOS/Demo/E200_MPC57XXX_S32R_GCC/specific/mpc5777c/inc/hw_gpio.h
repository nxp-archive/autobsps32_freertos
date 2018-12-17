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

#ifndef HW_GPIO_H
#define HW_GPIO_H

#include "hw_typedefs.h"
#include "hw_base.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /***** GPIO *****/
    #define SIU_PCR(n) HWREG16(HWSIU_BASE_ADDR + 0xD6U + (n << 1U))
    #define SIU_GPDO(n) HWREG8(HWSIU_BASE_ADDR + 0x64B + (n))
    #define OBE 0x0200

    #define SetGPIO(n)    SIU_GPDO(n)  = 0x1       /* set pin GPIO_NUM */
    #define ClrGPIO(n)    SIU_GPDO(n)  = 0x0       /* reset pin GPIO_NUM */
    #define ToogleGPIO(n) SIU_GPDO(n) ^= 0x1       /* toogle pin GPIO_NUM */

    #define InitGPIO(n)                 \
            SIU_PCR(n) = OBE;           \
            ClrGPIO(n)


#ifdef __cplusplus
}
#endif

#endif  /* HW_GPIO_H */

