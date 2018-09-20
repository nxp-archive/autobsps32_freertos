/*
*   Copyright 2018 NXP
*/

#include "hw_base.h"

extern void __start(void);
extern void __startSlave(void);

#define RCHWDATA __attribute__((section(".rchwdata")))

#define VLE_ENABLE                  0x01000000  /* VLE is enabled   */
#define MPC574xx_ID                 0x005A0000  /* RCHW boot ID for MPC574xx devices    */
#define RCHW_VAL (VLE_ENABLE | MPC574xx_ID)


RCHWDATA const unsigned int RCHW1=RCHW_VAL;
const  unsigned int __attribute__ ((section(".cpu_master_reset_vector"))) RCHW2_0 = ( unsigned int)__start;

#if defined(CORE_SLAVE)
const  unsigned int __attribute__ ((section(".cpu_slave_reset_vector"))) RCHW2_1 = ( unsigned int)__startSlave;
#endif
