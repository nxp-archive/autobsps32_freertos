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

#ifndef __CPUDEFS_H__
#define __CPUDEFS_H__

#ifdef __cplusplus
extern "C"
{
#endif

    #define LED0                         68U
    #define LED1                         69U
    #define LED2                         70U

    #define HWINTC_INTERRUPTS    (512U)

    /* INTC has some unimplemented inputs (the registers PSR, PRC_SEL are not
       implemented for these inputs). Following array contains bit set where
       each bit corresponds to an INTC input with number of the bit.
       If the value of bit is 1 - INTC input is implemented, 0 - INTC input is
       not implemented */
    #define AVAL_INTC_TABLE { \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /*   0.. 63 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /*  64..127 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 128..191 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 192..255 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 256..319 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 320..383 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 384..447 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff  /* 448..511 */ \
    }

    /* Definition is used in FreeRTOSConfig.h */
    #define configCPU_CLOCK_HZ                         ((unsigned portLONG ) 4000000 )
    /* RaceRunner skinny specific: pit channel to use 0-3 */
    #define configUSE_PIT_CHANNEL                     3
    #define MAX_PIT_CHANNEL                           3

#ifdef __cplusplus
}
#endif

#endif/*__CPUDEFS_H__*/
