/*
*   Copyright 2018 NXP
*/

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include "stdint.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /* hw register access macros */
    #define HWREG32(address) (*(volatile unsigned int   *)(address)) /* 32-bit register */
    #define HWREG16(address) (*(volatile unsigned short *)(address)) /* 16-bit register */
    #define HWREG8(address)  (*(volatile unsigned char  *)(address)) /*  8-bit register */

    typedef volatile signed char vint8_t;
    typedef volatile unsigned char vuint8_t;

    typedef volatile signed short vint16_t;
    typedef volatile unsigned short vuint16_t;

    typedef volatile signed int vint32_t;
    typedef volatile unsigned int vuint32_t;

#ifdef __cplusplus
}
#endif

#endif
