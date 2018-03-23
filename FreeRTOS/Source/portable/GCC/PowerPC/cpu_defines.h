#ifndef CPU_DEFINES_H
#define CPU_DEFINES_H

#if defined(MPC5746C) || defined(MPC5748G) || defined(MPC5744P) || defined(S32R274)
    #define INTC_CPR_ADDR                      0xFC040010
    #define INTC_IACKR_PRC_ADDR                0xFC040020
    #define INTC_EOIR_PRC_ADDR                 0xFC040030
    #define INTC_IACKR_INTVEC_BITWIDTH_NUM      10
#elif S32R372 == 1
    #define INTC_CPR_ADDR                      0xFC040014
    #define INTC_IACKR_PRC_ADDR                0xFC040024
    #define INTC_EOIR_PRC_ADDR                 0xFC040034
    #define INTC_IACKR_INTVEC_BITWIDTH_NUM      10
#else
    #error not define platform
#endif

#endif/* CPU_DEFINES_H */
