/*
*   Copyright 2018 NXP
*/

#ifndef HW_BASE_H
#define HW_BASE_H

#include "cpudefs.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /* peripheral base addresses */
    #define HWGCM_BASE_ADDR    (0xFFFB0000UL)
    #define HWGPIO_BASE_ADDR   (0xFFFC0000UL)
    #define HWINTC_BASE_ADDR   (0xFC040000UL)
    #define HWME_BASE_ADDR     (0xFFFB8000UL)
    #define HWPIT_BASE_ADDR    (0xFFF84000UL)
    #define HWRGM_BASE_ADDR    (0xFFFA8000UL)
    #define HWSWT0_BASE_ADDR   (0xFC050000UL)

#ifdef __cplusplus
}
#endif

#endif  /* HW_BASE_H */

