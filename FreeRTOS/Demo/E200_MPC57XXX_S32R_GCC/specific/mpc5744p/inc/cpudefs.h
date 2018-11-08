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

    #define LED0                         43U
    #define LED1                         44U
    #define LED2                         45U

    #define HWRGM_FES_OFFSET             0x300U
    #define HWRGM_FES_DEFAULT            0x0000
    #define CGM_SC_DC0_3_OFFSET          0x07E8U
    #define CGM_SC_DC0_3_DEFAULT         0x80010000

    #define ME_RUN_PC_OFFSET             0x80U
    #define ME_RUN_PC_DEFAULT            0x000000FE

    #define ME_MCTL_OFFSET               0x4U
    #define ME_MCTL_KEY_DEFAULT          0x30005AF0
    #define ME_MCTL_INVERTED_KEY_DEFAULT 0x3000A50F

    #define MC_ME_CCTL_OFFSET            0x1C6U
    #define MC_ME_CADDR_OFFSET           0x1E4U


    #define HWINTC_INTERRUPTS    (1024U)

    /* INTC has some unimplemented inputs (the registers PSR, PRC_SEL are not
       implemented for these inputs). Following array contains bit set where
       each bit corresponds to an INTC input with number of the bit.
       If the value of bit is 1 - INTC input is implemented, 0 - INTC input is
       not implemented */
    #define AVAL_INTC_TABLE { \
        0xff, 0xff, 0x00, 0x00, 0xf1, 0x00, 0xf0, 0xff, /*   0.. 63 */ \
        0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, /*  64..127 */ \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, /* 128..191 */ \
        0x00, 0x00, 0x00, 0x0f, 0x3c, 0x00, 0x7c, 0xf8, /* 192..255 */ \
        0xf8, 0xf0, 0xe1, 0xc3, 0x07, 0x00, 0x00, 0x00, /* 256..319 */ \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, /* 320..383 */ \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 384..447 */ \
        0xe0, 0x7f, 0x00, 0x60, 0x00, 0x03, 0x77, 0x77, /* 448..511 */ \
        0x00, 0xff, 0xe7, 0xff, 0xfc, 0x1f, 0x00, 0xfc, /* 512..575 */ \
        0xc0, 0x0f, 0x3c, 0xfc, 0xfb, 0xe9, 0x0f, 0x7f, /* 576..639 */ \
        0x08, 0x80, 0xff, 0xdf, 0xff, 0x0f, 0x00, 0xf0, /* 640..703 */ \
        0xff, 0xf7, 0xff, 0x17, 0x00, 0x00, 0x00, 0x00, /* 704..765 */ \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 704..765 */ \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 704..765 */ \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 766..829 */ \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 830..893 */ \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 894..957 */ \
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 956..1021 */ \
        0x00                                            /* 1022..1023 */ \
    }

    /* Definition is used in FreeRTOSConfig.h */
    #define configCPU_CLOCK_HZ                         ((unsigned portLONG ) 4000000 )
    /* Calypso specific: pit channel to use 0-15 */
    #define configUSE_PIT_CHANNEL                     3
    #define MAX_PIT_CHANNEL                           3

#ifdef __cplusplus
}
#endif

#endif/*__CPUDEFS_H__*/
