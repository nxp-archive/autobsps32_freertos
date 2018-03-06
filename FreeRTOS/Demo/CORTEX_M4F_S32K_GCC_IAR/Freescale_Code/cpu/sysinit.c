/*
 * File:        sysinit.c
 * Purpose:     Kinetis Configuration
 *              Initializes processor to a default state
 *
 * Notes:
 *
 */

#include "common.h"
#include "sysinit.h"

/********************************************************************/

/* Actual system clock frequency */
int core_clk_khz;
int core_clk_mhz;
int periph_clk_khz;

/********************************************************************/
void sysinit (void)
{
	/* Ramp up the system clock */
#if 0
	/* FIRC Configuration */
	SCG_FIRCDIV = 0x010101u;   /* SCG_FIRCDIV: FIRCDIV3=1, FIRCDIV2=1, FIRCDIV1=1 */
	SCG_FIRCCFG = 0x00;        /* SCG_FIRCCFG: RANGE=0 */
	while (SCG_FIRCCSR & 0x00800000u);
	SCG_FIRCCSR = 0x00000001u;   /* SCG_FIRCCSR: FIRCEN=1 */
	while (!(SCG_FIRCCSR & 0x01000000));

	/* SIRC Configuration */
	SCG_SIRCDIV = 0x10101u;   /* SCG_SIRCDIV: SIRCDIV3=1, SIRCDIV2=1, SIRCDIV1=1 */
	SCG_SIRCCFG = 0x01;       /* SCG_SIRCCFG: RANGE=1 */
	while (SCG_SIRCCSR & 0x00800000u);
	SCG_SIRCCSR = 0x1u;       /* SCG_SIRCCSR: SIRCEN=1 */
	while (!(SCG_SIRCCSR & 0x01000000u));

	/* SOSC Configuration */
	SCG_SOSCDIV = 0x00010101u;  /* SCG_SOSCDIV: SOSCDIV3=1, SOSCDIV2=1, SOSCDIV1=1 */
	SCG_SOSCCFG = 0x00000024u;  /* SCG_SOSCCFG: RANGE=2, EREFS=1 */
	while (SCG_SOSCCSR & 0x00800000u);
	SCG_SOSCCSR = 0x5u;           /* SCG_SOSCCSR: SOSCLPEN=1, SOSCEN=1 */
	while (!(SCG_SOSCCSR & 0x01000000u));

	/* SPLL Configuration 80MHz */
	SCG_SPLLDIV = 0x10101u;
	SCG_SPLLCFG = 0x40000u;     /* SCG_SPLLCFG: MULT=2, PREDIV=3, SOURCE=0 */
	while (SCG_SPLLCSR & 0x00800000u);
	SCG_SPLLCSR = 0x01;           /* SCG_SPLLCSR: SPLLEN=1 */
	while (!(SCG_SPLLCSR & 0x01000000u));

	SCG_RCCR = 0x06000013U;  /* RUN Mode Configuration */
	SCG_VCCR = 0x02000002U;  /* VLPR Mode Configuration */
	SCG_HCCR = 0x06000013U;  /* HSPR Mode Configuration */

	/* Set PTE4 as BUSOUT (TP5 on daughter card) */
	PORTE_PCR4 = 0x200;

	SMC_PMPROT = 0x80; /* Allow high speed run */
	SMC_PMCTRL = 0x60; /* Switch to high speed run */
#endif
}
/********************************************************************/
