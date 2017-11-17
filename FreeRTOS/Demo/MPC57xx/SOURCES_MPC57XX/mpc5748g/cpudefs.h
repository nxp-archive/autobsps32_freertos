/*
*   Copyright 2017 NXP
*/

#ifndef __CPUDEFS_H__
#define __CPUDEFS_H__

#ifdef __cplusplus
extern "C"
{
#endif

    #define LED0                        98U
    #define LED1                        99U
    #define LED2                        100U
    #define LED3                        101U

    #define HWRGM_FES_DEFAULT           0x4080 /* clear fccr_hard and fccu_safe flags */
    #define CGM_SC_DC0_3_DEFAULT        0x80000000

    #define CPU0_ENABLE                 0x00000002 /* CPU0 is enabled              */
    #define CPU2_ENABLE                 0x00000001 /* CPU2 is enabled              */
    #define MPC574xx_ID                 0x005A0000 /* RCHW boot ID for MPC574xx devices    */

    #define RCHWDATA_Init() \
        RCHWDATA const unsigned int RCHW6=0x00; \
        RCHWDATA const unsigned int RCHW5=(const unsigned int)__start; /* entry point */ \
        RCHWDATA const unsigned int RCHW4=0x00; \
        RCHWDATA const unsigned int RCHW3=0x00; \
        RCHWDATA const unsigned int RCHW2=0x00; \
        RCHWDATA const unsigned int RCHW1=RCHW_VAL;

    #define HWINTC_INTERRUPTS    (754U)

    /* INTC has some unimplemented inputs (the registers PSR, PRC_SEL are not
       implemented for these inputs). Following array contains bit set where
       each bit corresponds to an INTC input with number of the bit.
       If the value of bit is 1 - INTC input is implemented, 0 - INTC input is
       not implemented */
    #define AVAL_INTC_TABLE { \
        0xff, 0xff, 0xff, 0x00, 0xf7, 0xff, 0xf0, 0xff, /*   0.. 63 */\
        0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, /*  64..127 */\
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc2, /* 128..191 */\
        0x03, 0xfe, 0xff, 0x07, 0xff, 0xff, 0x7f, 0xfc, /* 192..255 */\
        0xfe, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xfe, /* 256..319 */\
        0xfd, 0xfb, 0xf7, 0x0f, 0x00, 0x00, 0x30, 0xff, /* 320..383 */\
        0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x55, /* 384..447 */\
        0xe0, 0x7f, 0x00, 0x20, 0x01, 0xc7, 0xff, 0xff, /* 448..511 */\
        0xff, 0xff, 0x00, 0x00, 0x70, 0x1c, 0xe7, 0x7f, /* 512..575 */\
        0xfc, 0xc7, 0x7f, 0xfc, 0xc7, 0x7f, 0xfc, 0xc7, /* 576..639 */\
        0x7f, 0xfc, 0x07, 0xf0, 0x00, 0xcd, 0xfc, 0x60, /* 640..703 */\
        0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03        /* 704..754 */\
    }

    /* Calypso specific: pit channel to use 0-15 */
    #define configUSE_PIT_CHANNEL                     15
    #define MAX_PIT_CHANNEL                           15

#ifdef __cplusplus
}
#endif

#endif/*__CPUDEFS_H__*/