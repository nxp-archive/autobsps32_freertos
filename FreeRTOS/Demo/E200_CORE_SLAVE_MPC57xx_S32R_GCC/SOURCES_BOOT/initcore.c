/*
*   Copyright 2018 NXP
*/

/* Include hardware configuration */
#include "hw_platform.h"


volatile uint32_t ui32_ms_cnt_loop = 0;

#define KEY_VALUE 0x5AF0ul

extern void __startSlave(void);

void hw_init()
{
    uint32_t mctl = MC_ME_MCTL;
#if CORE_ID == 1
    /* enable core 1 in all modes */
    MC_ME_CCTL(1) = 0x00FE;
    /* Set Start address for core 1: Will reset and start */
    MC_ME_CADDR(1) = (uint32_t)(__startSlave) | 0x1;
#endif
#if CORE_ID == 2
    MC_ME_CCTL(2) = 0x00FE;
    /* Set Start address for core 1: Will reset and start */
    MC_ME_CADDR(2) = (uint32_t)(__startSlave) | 0x1;
#endif
    MC_ME_MCTL = (mctl & 0xffff0000ul) | KEY_VALUE;
    MC_ME_MCTL =  mctl; /* key value 2 always from MCTL */
}

int loop(void)
{
    for(;;) {
        ui32_ms_cnt_loop++;
    }
}
