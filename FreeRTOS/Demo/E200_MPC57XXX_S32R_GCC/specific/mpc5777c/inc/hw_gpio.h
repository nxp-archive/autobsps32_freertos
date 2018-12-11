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

