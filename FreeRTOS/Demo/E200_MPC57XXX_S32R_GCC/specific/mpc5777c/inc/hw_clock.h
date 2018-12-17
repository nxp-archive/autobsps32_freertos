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

#ifndef HW_CLOCK_H
#define HW_CLOCK_H

#include "hw_typedefs.h"
#include "hw_base.h"

#ifdef __cplusplus
extern "C"
{
#endif

    #define SIU_ECCR            HWREG32(HWSIU_BASE_ADDR + 0x984UL)
    #define SIU_SYSDIV          HWREG32(HWSIU_BASE_ADDR + 0x9A0UL)
    #define SIU_FECCR           HWREG32(HWSIU_BASE_ADDR + 0x9E0UL)
    #define SIU_SDCLKCFG        HWREG32(HWSIU_BASE_ADDR + 0x9C4UL)
    #define SIU_LFCLKCFG        HWREG32(HWSIU_BASE_ADDR + 0x9C8UL)
    #define SIU_PSCLKCFG        HWREG32(HWSIU_BASE_ADDR + 0x9CCUL)

    #define PLLDIG_PLL0CR       HWREG32(HWPLLDIG_BASE_ADDR + 0x0U)
    #define PLLDIG_PLL0SR       HWREG32(HWPLLDIG_BASE_ADDR + 0x4U)
    #define PLLDIG_PLL0DV       HWREG32(HWPLLDIG_BASE_ADDR + 0x8U)

    #define PLLDIG_PLL1CR       HWREG32(HWPLLDIG_BASE_ADDR + 0x20UL)
    #define PLLDIG_PLL1SR       HWREG32(HWPLLDIG_BASE_ADDR + 0x24UL)
    #define PLLDIG_PLL1DV       HWREG32(HWPLLDIG_BASE_ADDR + 0x28UL)
    #define PLLDIG_PLL1FM       HWREG32(HWPLLDIG_BASE_ADDR + 0x2CUL)
    #define PLLDIG_PLL1FD       HWREG32(HWPLLDIG_BASE_ADDR + 0x30UL)
    #define PLLDIG_PLL1FD_8B    HWREG8(HWPLLDIG_BASE_ADDR + 0x30UL)

    #define SIU_RSTVEC1         HWREG32(HWSIU_BASE_ADDR + 0x9B0UL)
    #define SIU_HLT1            HWREG32(HWSIU_BASE_ADDR + 0x9A4UL)

    /* configure IRCOSC as the system clock 16MHz */
    #define HWPeriphEnableAll()                                       \
    {                                                           \
        SIU_SYSDIV |= 0x10000000UL;                             \
        SIU_SYSDIV &= ~ 0x4000000UL;                            \
        PLLDIG_PLL0DV = 0x20011008UL;                           \
        PLLDIG_PLL0CR &=  ~ 0x300UL;                            \
        PLLDIG_PLL1DV = 0x00010010UL;                           \
        PLLDIG_PLL1FD = 0x0U;                                   \
        PLLDIG_PLL1CR &= ~ 0x300UL;                             \
        SIU_SYSDIV &= ~ 0x3000U;                                \
        SIU_SYSDIV |= 0x10U;                                    \
        SIU_SYSDIV |= 0x10000UL;                                \
    }

#ifdef __cplusplus
}
#endif

#endif  /* HW_CLOCK_H */

