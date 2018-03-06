/*
 * File:        s32k.h
 * Purpose:     Definitions for s32k card
 *
 * Notes:
 */

#ifndef __S32K_H__
#define __S32K_H__

/********************************************************************/

/* Global defines to use for all boards */
#define DEBUG_PRINT


/* Defines specific to the S32K board */

/* Define for the CPU on the S32K board */
#define CPU_S32K144

/*
 * Serial Port Info
 */

/*
 * Select the serial port that is being used below. Only one of the
 * options should be uncommented at any time.
 */

/* #define SERIAL_CARD */    /* use this option for serial port on TWR-SER */
#define OSJTAG               /* use this option for serial port over the OS-JTAG circuit */

#if (defined(SERIAL_CARD))
	#define TERM_PORT           UART3_BASE_PTR
	#define TERMINAL_BAUD       115200
	#undef  HW_FLOW_CONTROL
#elif (defined(OSJTAG))
	#define TERM_PORT           UART5_BASE_PTR
	#define TERMINAL_BAUD       115200
	#undef  HW_FLOW_CONTROL
#else
	#error "No valid serial port defined"
#endif


#endif /* __S32K_H__ */
