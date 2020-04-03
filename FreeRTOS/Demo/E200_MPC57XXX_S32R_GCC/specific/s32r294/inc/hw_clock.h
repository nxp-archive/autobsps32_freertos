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

#ifndef HW_CLOCK_H
#define HW_CLOCK_H

#include "hw_typedefs.h"
#include "hw_base.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /***** Clocks *****/
    /* Reset generation module */
    #define HWRGM_FES       HWREG32(HWRGM_BASE_ADDR + HWRGM_FES_OFFSET)            /* Functional Event Status */

    #define CGM_SC_DC0_3    HWREG32(HWGCM_BASE_ADDR + CGM_SC_DC0_3_OFFSET)  /* System Clock Divider Configuration Registers (CGM_SC_DC0:3) */
    #define MC_ME_GS        HWREG32(HWME_BASE_ADDR)             /* Global Status Register */
    #define MC_ME_RUN_PC    HWREG32(HWME_BASE_ADDR + ME_RUN_PC_OFFSET)     /* Run Peripheral Configuration Registers MC_ME_RUN_PC0 */
    #define MC_ME_MCTL      HWREG32(HWME_BASE_ADDR + ME_MCTL_OFFSET)      /* Mode Control Register */

    #define MC_ME_CCTL(coreId) \
        (HWREG16(HWME_BASE_ADDR + MC_ME_CCTL_OFFSET + ((coreId) << 1U))) /* Core Control Register for core with given coreId */

    #define MC_ME_CADDR(coreId) \
        (HWREG32(HWME_BASE_ADDR + MC_ME_CADDR_OFFSET + ((coreId) << 2U))) /* Core Address Register for core with given coreId */

    #define HWPeriphEnableAll()                                                    \
    {                                                                              \
        HWRGM_FES = HWRGM_FES_DEFAULT; \
        CGM_SC_DC0_3 = CGM_SC_DC0_3_DEFAULT; \
        MC_ME_RUN_PC = ME_RUN_PC_DEFAULT;          /* Set configuration,peripheral ON in every mode */ \
        MC_ME_MCTL = ME_MCTL_KEY_DEFAULT;            /* Re-enter in DRUN mode to update with control key */ \
        MC_ME_MCTL = ME_MCTL_INVERTED_KEY_DEFAULT;            /* --//-- with inverted control key */ \
        while(MC_ME_GS & 0x08000000ul){}    /* Wait for mode transition to complete */ \
        while((MC_ME_GS & 0x30000000ul) != 0x30000000ul){}     /* Check current mode status is DRUN */ \
    }



#ifdef __cplusplus
}
#endif

#endif  /* HW_CLOCK_H */
