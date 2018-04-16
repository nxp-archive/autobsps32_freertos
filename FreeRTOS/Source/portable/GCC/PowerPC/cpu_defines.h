/* Copyright 2018 NXP */

#ifndef CPU_DEFINES_H
#define CPU_DEFINES_H

#if defined(CPU_MPC5746C) || defined(CPU_MPC5748G) || defined(CPU_MPC5744P) || defined(CPU_S32R274)
    #define INTC_CPR_ADDR                      0xFC040010
    #define INTC_IACKR_PRC_ADDR                0xFC040020
    #define INTC_EOIR_PRC_ADDR                 0xFC040030
    #define INTC_IACKR_INTVEC_BITWIDTH_NUM      10
#elif defined(CPU_S32R372)
    #define INTC_CPR_ADDR                      0xFC040014
    #define INTC_IACKR_PRC_ADDR                0xFC040024
    #define INTC_EOIR_PRC_ADDR                 0xFC040034
    #define INTC_IACKR_INTVEC_BITWIDTH_NUM      10
#else
    #error not define platform
#endif

#endif/* CPU_DEFINES_H */
