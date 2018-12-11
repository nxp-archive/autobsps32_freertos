/*
*   Copyright 2018 NXP
*/

#ifndef __CPUDEFS_H__
#define __CPUDEFS_H__

#ifdef __cplusplus
extern "C"
{
#endif

    #define LED0                         68U
    #define LED1                         69U
    #define LED2                         70U

    #define HWINTC_INTERRUPTS    (512U)

    /* INTC has some unimplemented inputs (the registers PSR, PRC_SEL are not
       implemented for these inputs). Following array contains bit set where
       each bit corresponds to an INTC input with number of the bit.
       If the value of bit is 1 - INTC input is implemented, 0 - INTC input is
       not implemented */
    #define AVAL_INTC_TABLE { \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /*   0.. 63 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /*  64..127 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 128..191 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 192..255 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 256..319 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 320..383 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 384..447 */ \
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff  /* 448..511 */ \
    }

    /* Definition is used in FreeRTOSConfig.h */
    #define configCPU_CLOCK_HZ                         ((unsigned portLONG ) 4000000 )
    /* RaceRunner skinny specific: pit channel to use 0-3 */
    #define configUSE_PIT_CHANNEL                     3
    #define MAX_PIT_CHANNEL                           3

#ifdef __cplusplus
}
#endif

#endif/*__CPUDEFS_H__*/
