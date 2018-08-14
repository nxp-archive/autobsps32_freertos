/*
*   Copyright 2018 NXP
*/

#ifndef HW_INTC_H
#define HW_INTC_H

#include "hw_typedefs.h"
#include "hw_base.h"

#ifdef __cplusplus
extern "C"
{
#endif

    #define HWINTC_OFFSET        (CORE_ID << 2U) /* can be used to access the INTC registers for the other cores */

    #define HWINTC_MCR           HWREG32(HWINTC_BASE_ADDR)                            /* Module/Block Configuration Register */
    #define HWINTC_CPR           HWREG32(HWINTC_BASE_ADDR + 0x10U + HWINTC_OFFSET)    /* Current Priority Register */
    #define HWINTC_IACKR         HWREG32(HWINTC_BASE_ADDR + 0x20U + HWINTC_OFFSET)    /* Interrupt Acknowledge Register */
    #define HWINTC_EOIR          HWREG32(HWINTC_BASE_ADDR + 0x30U + HWINTC_OFFSET)    /* End of Interrupt Register */
    #define HWINTC_SSCIR(intr)   HWREG8(HWINTC_BASE_ADDR  + 0x40U + (intr))           /* Software Set/Clear Interrupt Register
                                                                                         for setable software interrupt (n) */

    #define HWINTC_SOFTINVOKE    (0x2U)                                               /* bit number to invoke setable software interrupt */
    #define HWINTC_SOFTCLEAR     (0x1U)                                               /* bit number to clear setable software interrupt */

    #define HWINTC_PSR_ADDR(intr) (HWINTC_BASE_ADDR + 0x60U + (unsigned int)((intr)<<1U))  /* address of INTC_PSR for intr input */

    #define HWINTC_PSR(intr)            HWREG16( HWINTC_PSR_ADDR(intr) )                    /* INTC_PSR register for intr input */
    #define HWINTC_PRIO(intr)           HWREG8(  HWINTC_PSR_ADDR(intr) + 1U)                /* Priority select register for intr input */
    #define HWINTC_SET_PRC_SEL          (0x1U << (15 - CORE_ID))                            /* Processor select bits' registor for intr input */


    /* Set priority, given prio must contain only priority */
    #define HWINTC_SET_PSRX(intr, prio) (HWINTC_PRIO(intr) = (prio))

    #define HWINTC_GET_PSRX(intr) (HWINTC_PRIO(intr))                                /* Return current prio for intr input */

    /* Hardware vector mode bit */
    #define HWINTC_MCR_HVEN_HW      ((0x1UL << ((CORE_ID) << 2U)))                   /* coreId - hw coreId (value that is read from PIR) */
    /* Software vector mode bit */
    #define HWINTC_MCR_HVEN_SW      ((0xFFFFFFFFUL & (~(0x1U<<(CORE_ID << 2U)))))     /* coreId - hw coreId (value that is read from PIR) */

#ifdef __cplusplus
}
#endif


#endif /* HW_INTC_H */


