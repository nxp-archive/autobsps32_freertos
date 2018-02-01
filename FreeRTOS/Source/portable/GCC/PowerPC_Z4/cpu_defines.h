#ifndef CPU_DEFINES_H
#define CPU_DEFINES_H

#if MPC5746C == 1 | MPC5748G == 1 | MPC5744P == 1
    #define INTC_CPR_ADDR                      0xFC040010
    #define INTC_IACKR_PRC_ADDR                0xFC040020
    #define INTC_EOIR_PRC_ADDR                 0xFC040030
    #define INTC_IACKR_INTVEC_BITWIDTH_NUM      10
#else
    #error not define platform
#endif

#endif/* CPU_DEFINES_H */