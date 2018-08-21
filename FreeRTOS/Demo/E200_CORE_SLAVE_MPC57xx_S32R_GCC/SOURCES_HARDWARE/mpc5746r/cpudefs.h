/*
*   Copyright 2018 NXP
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

    #define CPU0_ENABLE                 0x00000002 /* CPU0 is enabled              */
    #define CPU2_ENABLE                 0x00000001 /* CPU2 is enabled              */
    #define MPC574xx_ID                 0x005A0000 /* RCHW boot ID for MPC574xx devices    */


    #define ME_MCTL_OFFSET               0x4U
    #define ME_MCTL_KEY_DEFAULT          0x30005AF0
    #define ME_MCTL_INVERTED_KEY_DEFAULT 0x3000A50F

    #define HWRGM_FES_OFFSET            0x300U
    #define CGM_SC_DC0_3_OFFSET         0x0108U
    #define CGM_SC_DC0_3_DEFAULT        0x80030000

    #define CGM_AC_SC_0_OFFSET           0x100U
    #define CGM_AC_SC_0_DEFAULT          0x00000000U

    #define ME_RUN_PC_OFFSET             0x80U
    #define ME_RUN_PC_DEFAULT            0x000000FE

    #define RCHWDATA_Init() \
        RCHWDATA const unsigned int RCHW6=0x00; \
        RCHWDATA const unsigned int RCHW5=(const unsigned int)__start; /* entry point */ \
        RCHWDATA const unsigned int RCHW4=0x00; \
        RCHWDATA const unsigned int RCHW3=0x00; \
        RCHWDATA const unsigned int RCHW2=0x00; \
        RCHWDATA const unsigned int RCHW1=RCHW_VAL;

    #define HWINTC_INTERRUPTS    (1024U)

    /* INTC has some unimplemented inputs (the registers PSR, PRC_SEL are not
       implemented for these inputs). Following array contains bit set where
       each bit corresponds to an INTC input with number of the bit.
       If the value of bit is 1 - INTC input is implemented, 0 - INTC input is
       not implemented */
    #define AVAL_INTC_TABLE { \
        0xff,  0xff,  0xff,  0xff,  0xfb,  0x0f,  0xf0,  0xff, \
        0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0x1f,  0x00, \
        0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x02, \
        0x00,  0x00,  0x00,  0x1c,  0xfc,  0x83,  0x1f,  0xf8, \
        0xf8,  0xf7,  0xef,  0xdf,  0xbf,  0x7f,  0xff,  0xff, \
        0x03,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x77, \
        0x77,  0x77,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, \
        0x00,  0x00,  0x00,  0x60,  0xff,  0xcf,  0x00,  0x00, \
        0x00,  0x00,  0x77,  0x77,  0x0f,  0xc0,  0xff,  0x1f, \
        0xf8,  0x0f,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, \
        0x00,  0xc0,  0xff,  0x03,  0xec,  0xff,  0xff,  0x1f, \
        0xfc,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff,  0xff, \
        0xff,  0xff,  0xff,  0xff,  0x07,  0x00,  0x00,  0x00, \
        0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, \
        0xf0,  0x03,  0xf8,  0x3f,  0xf0,  0x03,  0x00,  0x00, \
        0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00  \
    }

    /* Definition is used in FreeRTOSConfig.h */
    #define configCPU_CLOCK_HZ                         ((unsigned portLONG ) 4000000 )
    /* Calypso specific: pit channel to use 0-15 */
    #define configUSE_PIT_CHANNEL                     0
    #define MAX_PIT_CHANNEL                           8

#ifdef __cplusplus
}
#endif

#endif/*__CPUDEFS_H__*/