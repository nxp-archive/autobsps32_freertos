/*
 * File:        sysinit.c
 * Purpose:     s32v234 Configuration
 *
 * Notes:
 *
 */

#include "common.h"


void peripherals_clock_setup();
void clock_start();


void sysinit( void )
{
	peripherals_clock_setup();
	clock_start();
}


void peripherals_clock_setup()
{
	/* Select the source clock for FTM0 */
	REG_WRITE32 ( CGM_ACn_SC( MC_CGM0_BASE_ADDRESS, 4 ), MC_CGM_ACn_SEL_SET( MC_CGM_ACn_SEL_XOSC ) );

	/* Select the source clock for FTM1 */
	REG_WRITE32 ( CGM_ACn_SC( MC_CGM2_BASE_ADDRESS, 3 ), MC_CGM_ACn_SEL_SET( MC_CGM_ACn_SEL_XOSC ) );
}

/* select xosc for M4 freq = 40/2 Mhz -> 20MHz*/
void clock_start( void )
{
	REG_WRITE8( MC_ME_ME, MC_ME_ME_RUN0 | \
                          MC_ME_ME_RUN1 | \
                          MC_ME_ME_RUN2 | \
						  MC_ME_ME_RUN3 | \
                          MC_ME_ME_DRUN );
	REG_WRITE8( MC_ME_RUN_PCn(0), MC_ME_RUN_PCn_RUN0 | \
                                  MC_ME_RUN_PCn_RUN1 | \
								  MC_ME_RUN_PCn_RUN2 | \
                                  MC_ME_RUN_PCn_RUN3 | \
								  MC_ME_RUN_PCn_DRUN | \
                                  MC_ME_RUN_PCn_TEST );
	REG_WRITE32( FXOSC, 0x01a02070 );
	REG_WRITE32( MC_ME_RUNn_MC( 0 ), MC_ME_RUNMODE_MC_SYSCLK( 1 ) | \
									 MC_ME_RUNMODE_MC_FIRCON | \
									 MC_ME_RUNMODE_MC_XOSCON );
	REG_WRITE32( MC_ME_MCTL, MC_ME_MCTL_RUN0 | MC_ME_MCTL_KEY );
	REG_WRITE32( MC_ME_MCTL, MC_ME_MCTL_RUN0 | MC_ME_MCTL_INVERTEDKEY );
	REG_WRITE32( MC_ME_RUNn_SEC_CC_I( 0 ),
				 MC_ME_RUNMODE_SEC_CC_I_SYSCLK( 1, MC_ME_RUNMODE_SEC_CC_I_SYSCLK1_OFFSET ) |
				 MC_ME_RUNMODE_SEC_CC_I_SYSCLK( 1, MC_ME_RUNMODE_SEC_CC_I_SYSCLK2_OFFSET ) |
				 MC_ME_RUNMODE_SEC_CC_I_SYSCLK( 1, MC_ME_RUNMODE_SEC_CC_I_SYSCLK3_OFFSET ) );
	REG_WRITE32( MC_ME_MCTL, MC_ME_MCTL_RUN0 | MC_ME_MCTL_KEY );
	REG_WRITE32( MC_ME_MCTL, MC_ME_MCTL_RUN0 | MC_ME_MCTL_INVERTEDKEY );
}

