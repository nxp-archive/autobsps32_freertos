/*
 * File:	start.c
 * Purpose:	start up code.
 *
 * Notes:
 */

#include "common.h"
#include "sysinit.h"

/********************************************************************/
/*!
 * \brief   s32v234 Start
 * \return  None
 *
 * This function calls all of the needed startup routines and then
 * branches to the main.
 */
void start(void)
{
	/* Copy any vector or data sections that need to be in RAM */
	common_startup();

	/* Perform paltform initialization */
	sysinit();

	/* Jump to main() */
	main();

	while(1); /* just in case main() returns */
}
/********************************************************************/
