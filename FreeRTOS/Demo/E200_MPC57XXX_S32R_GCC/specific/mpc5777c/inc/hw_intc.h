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

#ifndef HW_INTC_H
#define HW_INTC_H

#include "hw_typedefs.h"
#include "hw_base.h"

#ifdef __cplusplus
extern "C"
{
#endif

    #define HWINTC_OFFSET(coreId)        (coreId << 2U) /* can be used to access the INTC registers for the other cores */

    #define HWINTC_MCR                   HWREG32(HWINTC_BASE_ADDR)                                   /* Module/Block Configuration Register */
    #define HWINTC_CPR(coreId)           HWREG32(HWINTC_BASE_ADDR + 0x8U + HWINTC_OFFSET(coreId))    /* Current Priority Register */
    #define HWINTC_IACKR(coreId)         HWREG32(HWINTC_BASE_ADDR + 0x10U + HWINTC_OFFSET(coreId))   /* Interrupt Acknowledge Register */
    #define HWINTC_EOIR  (coreId)        HWREG32(HWINTC_BASE_ADDR + 0x18U + HWINTC_OFFSET(coreId))   /* End of Interrupt Register */
    #define HWINTC_SSCIR(intr)           HWREG8(HWINTC_BASE_ADDR  + 0x20U + (intr))                  /* Software Set/Clear Interrupt Register
                                                                                         for setable software interrupt (n) */

    #define HWINTC_SOFTINVOKE    (0x2U)                                               /* bit number to invoke setable software interrupt */
    #define HWINTC_SOFTCLEAR     (0x1U)                                               /* bit number to clear setable software interrupt */

    #define HWINTC_PSR_ADDR(intr) (HWINTC_BASE_ADDR + 0x40U + (intr))  /* address of INTC_PSR for intr input */

    #define HWINTC_PSR(intr)            HWREG8( HWINTC_PSR_ADDR(intr) )                    /* INTC_PSR register for intr input */
    #define HWINTC_PRIO(intr)           HWREG8( HWINTC_PSR_ADDR(intr) )                /* Priority select register for intr input */
    #define HWINTC_SET_PRC_SEL(coreId)          (unsigned char)((coreId*3) << 6)                            /* Processor select bits' registor for intr input */


    /* Set priority, given prio must contain only priority */
    #define HWINTC_SET_PSRX(intr, prio) (HWINTC_PRIO(intr) = ((HWINTC_PRIO(intr) & (unsigned char)(~0xF)) | ((prio) & (unsigned char)(0xF))))

    #define HWINTC_GET_PSRX(intr) (HWINTC_PRIO(intr) & 0xFU)                                /* Return current prio for intr input */

    /* Hardware vector mode bit */
    #define HWINTC_MCR_HVEN_HW(coreId)      ((0x1U << ((coreId) << 3U)))                   /* coreId - hw coreId (value that is read from PIR) */
    /* Software vector mode bit */
    #define HWINTC_MCR_HVEN_SW(coreId)      ((0xFFFFFFFFUL & (~(0x1U<<(coreId << 3U)))))     /* coreId - hw coreId (value that is read from PIR) */

#ifdef __cplusplus
}
#endif


#endif /* HW_INTC_H */


