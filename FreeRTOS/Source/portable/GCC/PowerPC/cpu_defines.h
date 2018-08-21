/*
*   Copyright 2018 NXP.
*/

#ifndef CPU_DEFINES_H
#define CPU_DEFINES_H

#if defined(CPU_MPC5746C) || defined(CPU_MPC5748G) || defined(CPU_MPC5744P) || defined(CPU_S32R274) || defined(CPU_S32R372) || defined(CPU_MPC5746R)
    #define INTC_CPR_ADDR_BASE                      0xFC040010
    #define INTC_IACKR_PRC_ADDR_BASE                0xFC040020
    #define INTC_EOIR_PRC_ADDR_BASE                 0xFC040030
    #define INTC_IACKR_INTVEC_BITWIDTH_NUM_BASE     10
    #define INTC_OFFSET_NUM                            2
#else
    #error not define platform
#endif

    #define INTC_OFFSET(coreId)                        (coreId << INTC_OFFSET_NUM)
    #define INTC_CPR_ADDR(coreId)                      INTC_CPR_ADDR_BASE + INTC_OFFSET((coreId))
    #define INTC_IACKR_PRC_ADDR(coreId)                INTC_IACKR_PRC_ADDR_BASE + INTC_OFFSET((coreId))
    #define INTC_EOIR_PRC_ADDR(coreId)                 INTC_EOIR_PRC_ADDR_BASE + INTC_OFFSET((coreId))
    #define INTC_IACKR_INTVEC_BITWIDTH_NUM             INTC_IACKR_INTVEC_BITWIDTH_NUM_BASE

#endif/* CPU_DEFINES_H */
