/*
 *
 * Copyright 2018 NXP
 *
 * File:		common.h
 * Purpose:		File to be included by all project files
 *
 * Notes:
 */

#ifndef _COMMON_H_
#define _COMMON_H_

/********************************************************************/

/*
 * Include the cpu specific header file
 */
#if (defined(CPU_S32K118))
    #include "cortex-m0plus.h"
    #include "S32K118.h"
#elif (defined(CPU_S32K116))
    #include "cortex-m0plus.h"
    #include "S32K116.h"
#elif (defined(CPU_S32K142))
    #include "cortex-m4.h"
    #include "S32K142.h"
#elif (defined(CPU_S32K144))
    #include "cortex-m4.h"
    #include "S32K144.h"
#elif (defined(CPU_S32K144W))
    #include "cortex-m4.h"
    #include "S32K144W.h"
#elif (defined(CPU_S32K146))
    #include "cortex-m4.h"
    #include "S32K146.h"
#elif (defined(CPU_S32K148))
    #include "cortex-m4.h"
    #include "S32K148.h"
#else
    #error "No valid CPU defined"
#endif

/*
 * Include common utilities
 */
#include "startup.h"
#include "stdlib.h"

#include "hw_gpio.h"

/********************************************************************/

#endif /* _COMMON_H_ */
