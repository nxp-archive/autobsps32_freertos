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
#if defined(CPU_MPC5746C) || defined(CPU_MPC5748G) || defined(CPU_MPC5744P) || defined(CPU_S32R274) || defined(CPU_S32R372)
    #define HWGCM_BASE_ADDR    (0xFFFB0000UL)
    #define HWGPIO_BASE_ADDR   (0xFFFC0000UL)
    #define HWINTC_BASE_ADDR   (0xFC040000UL)
    #define HWME_BASE_ADDR     (0xFFFB8000UL)
    #define HWPIT_BASE_ADDR    (0xFFF84000UL)
    #define HWRGM_BASE_ADDR    (0xFFFA8000UL)
    #define HWSWT0_BASE_ADDR   (0xFC050000UL)
#elif defined(CPU_MPC5746R)
/* This Base address of MPC5746R platform */

    #define HWGCM_BASE_ADDR    (0xFFFB0700UL) 
    #define HWGPIO_BASE_ADDR   (0xFFFC0000UL)
    #define HWINTC_BASE_ADDR   (0xFC040000UL)
    #define HWME_BASE_ADDR     (0xFFFB8000UL)
    #define HWPIT_BASE_ADDR    (0xFFF84000UL)
    #define HWRGM_BASE_ADDR    (0xFFFA8000UL)
    #define HWSWT0_BASE_ADDR   (0xFC050000UL)
#else
    #error not define platform
#endif

#ifdef __cplusplus
}
#endif

#endif  /* HW_BASE_H */
