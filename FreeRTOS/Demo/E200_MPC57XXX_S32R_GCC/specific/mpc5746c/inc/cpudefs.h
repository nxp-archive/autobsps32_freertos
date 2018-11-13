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

    #define LED0                        98U
    #define LED1                        99U
    #define LED2                        100U
    #define LED3                        101U
    #define HWRGM_FES_OFFSET            0x300U
    #define HWRGM_FES_DEFAULT           0x4080 /* clear fccr_hard and fccu_safe flags */
    #define CGM_SC_DC0_3_OFFSET         0x07E8U
    #define CGM_SC_DC0_3_DEFAULT        0x80000000

    #define ME_RUN_PC_OFFSET             0x80U
    #define ME_RUN_PC_DEFAULT            0x000000FE

    #define ME_MCTL_OFFSET               0x4U
    #define ME_MCTL_KEY_DEFAULT          0x30005AF0
    #define ME_MCTL_INVERTED_KEY_DEFAULT 0x3000A50F

    #define MC_ME_CCTL_OFFSET            0x1C6U
    #define MC_ME_CADDR_OFFSET           0x1E4U


    #define HWINTC_INTERRUPTS    (766U)

    /* INTC has some unimplemented inputs (the registers PSR, PRC_SEL are not
       implemented for these inputs). Following array contains bit set where
       each bit corresponds to an INTC input with number of the bit.
       If the value of bit is 1 - INTC input is implemented, 0 - INTC input is
       not implemented */
    #define AVAL_INTC_TABLE { \
        0xff, 0xff, 0xff, 0x00, 0xf3, 0x0f, 0xf0, 0xff, /*   0.. 63 */\
        0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, /*  64..127 */\
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, /* 128..191 */\
        0x00, 0x00, 0xfc, 0x07, 0xff, 0xff, 0x7f, 0xfc, /* 192..255 */\
        0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xfe, /* 256..319 */\
        0xfd, 0x03, 0x00, 0x00, 0x00, 0x00, 0x30, 0xff, /* 320..383 */\
        0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x55, /* 384..447 */\
        0xe0, 0x7f, 0x00, 0x00, 0x11, 0x07, 0xff, 0xff, /* 448..511 */\
        0xff, 0xff, 0x00, 0x00, 0x70, 0x1c, 0xe7, 0x7f, /* 512..575 */\
        0xfc, 0xc7, 0x7f, 0xfc, 0xc7, 0x7f, 0xfc, 0xc7, /* 576..639 */\
        0x7f, 0xfc, 0x07, 0xf0, 0x00, 0x00, 0xfc, 0x60, /* 640..703 */\
        0xfc, 0xff, 0xff, 0xff, 0x03, 0x00, 0xfc, 0x3f  /* 704..765 */\
    }

    /* Definition is used in FreeRTOSConfig.h */
    #define configCPU_CLOCK_HZ                         ((unsigned portLONG ) 4000000 )
    /* Calypso specific: pit channel to use 0-15 */
    #define configUSE_PIT_CHANNEL                     15
    #define MAX_PIT_CHANNEL                           15

#ifdef __cplusplus
}
#endif

#endif/*__CPUDEFS_H__*/
