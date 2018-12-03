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

    #define LED0                        99U
    #define LED1                        100U
    #define HWRGM_FES_OFFSET            0x0000U
    #define HWRGM_FES_DEFAULT           0x4080 /* clear fccr_hard and fccu_safe flags */
    #define CGM_SC_DC0_3_OFFSET         0x0108U
    #define CGM_SC_DC0_3_DEFAULT        0x80040000

    #define ME_RUN_PC_OFFSET             0x80U
    #define ME_RUN_PC_DEFAULT            0x000000FE

    #define ME_MCTL_OFFSET               0x4U
    #define ME_MCTL_KEY_DEFAULT          0x30005AF0
    #define ME_MCTL_INVERTED_KEY_DEFAULT 0x3000A50F

    #define MC_ME_CCTL_OFFSET            0x1C4U
    #define MC_ME_CADDR_OFFSET           0x1E0U


    #define HWINTC_INTERRUPTS    (1024U)

    /* INTC has some unimplemented inputs (the registers PSR, PRC_SEL are not
       implemented for these inputs). Following array contains bit set where
       each bit corresponds to an INTC input with number of the bit.
       If the value of bit is 1 - INTC input is implemented, 0 - INTC input is
       not implemented */
    #define AVAL_INTC_TABLE { \
        0xff,  0xff,  0xff,  0xff,  0xfb,  0x0f,  0xf0,  0xff, \
        0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x1f,  0x00, \
        0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x02, \
        0x00,  0x00,  0x00,  0x1c,  0xfc,  0x83,  0x1f,  0xf8, \
        0xf8,  0xf7,  0xef,  0xdf,  0xbf,  0x7f,  0xff,  0xff, \
        0x03,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x77, \
        0x77,  0x77,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, \
        0x00,  0x00,  0x00,  0x60,  0xff,  0xcf,  0x00,  0x00, \
        0x00,  0x00,  0x77,  0x77,  0x0f,  0xc0,  0xff,  0x1f, \
        0xf8,  0x0f,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, \
        0x00,  0xc0,  0xff,  0x03,  0xec,  0xff,  0xff,  0x1f, \
        0xfc,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff, \
        0xff,  0xff,  0xff,  0xff,  0x07,  0x00,  0x00,  0x00, \
        0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, \
        0xf0,  0x03,  0xf8,  0x3f,  0xf0,  0x03,  0x00,  0x00, \
        0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00  \
    }

    /* Definition is used in FreeRTOSConfig.h */
    #define configCPU_CLOCK_HZ                         ((unsigned portLONG ) 4000000 )
    /* Calypso specific: pit channel to use 0-15 */
    #define configUSE_PIT_CHANNEL                     0
    #define MAX_PIT_CHANNEL                           8

#ifdef __cplusplus
}
#endif

#endif/*__CPUDEFS_H__*/
