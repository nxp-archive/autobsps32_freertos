/*
 * File:		wdog.c
 * Purpose:		Provide common watchdog module routines
 *
 * Notes:		Need to add more functionality. Right now it
 * 				is just a disable routine since we know almost
 * 				all projects will need that.
 *
 */

#include "common.h"
#include "wdog.h"

/********************************************************************/
/*
 * Watchdog timer disable routine
 *
 * Parameters:
 * none
 */
void wdog_disable(void)
{
	WDOG->CS &= ~WDOG_CS_EN_MASK;
}
/********************************************************************/
