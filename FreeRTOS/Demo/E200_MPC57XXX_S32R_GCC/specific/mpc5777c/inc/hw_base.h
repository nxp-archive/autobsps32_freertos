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
    #define HWINTC_BASE_ADDR   (0xFFF48000UL)
    #define HWPIT_BASE_ADDR    (0xC3FF0000UL)
    #define HWSWT0_BASE_ADDR   (0xFFF38000UL)
    #define HWSIU_BASE_ADDR    (0xC3F90000UL)
    #define HWPLLDIG_BASE_ADDR (0xFFE74000UL)


#ifdef __cplusplus
}
#endif

#endif  /* HW_BASE_H */

