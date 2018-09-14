/*
*   Copyright 2018 NXP
*/

#ifndef HW_GPIO_H
#define HW_GPIO_H

#include "hw_typedefs.h"
#include "hw_base.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /***** GPIO *****/
    #define SIUL2_MSCR(n)  HWREG32(HWGPIO_BASE_ADDR + 0x240 + (n) * 4)      /* SIUL2 Multiplexed Signal Configuration Register */
    #define SIUL2_GPDO(n)  HWREG8(HWGPIO_BASE_ADDR + 0x1300 + (n))           /* Pad Data Output Register */

    #define SIUL_MSCR     0x02000000ul              /* GPIO, Output Buffer Enable */

    #define SetGPIO(n)    SIUL2_GPDO(n)  = 0x1       /* set pin GPIO_NUM */
    #define ClrGPIO(n)    SIUL2_GPDO(n)  = 0x0       /* reset pin GPIO_NUM */
    #define ToogleGPIO(n) SIUL2_GPDO(n) ^= 0x1       /* toogle pin GPIO_NUM */

    #define InitGPIO(n)                 \
            SIUL2_MSCR(n) = SIUL_MSCR;  \
            ClrGPIO(n)

#ifdef __cplusplus
}
#endif

#endif  /* HW_GPIO_H */
