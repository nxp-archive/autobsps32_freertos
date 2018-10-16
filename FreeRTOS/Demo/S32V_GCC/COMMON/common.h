/*
 * File:		common.h
 * Purpose:		File to be included by all project files
 *
 * Notes:
 */

#ifndef COMMON_H
#define COMMON_H

/********************************************************************/

/*
 * Debug prints ON (#define) or OFF (#undef)
 */
#define DEBUG_PRINT

/*
 * Include the generic CPU header file
 */
#include "arm_cm4.h"

/*
 * Include the platform specific header file
 */
#if (defined(S32V234))
	#include "S32V234.h"
#else
	#error "No valid CPU defined"
#endif

/*
 * Include any toolchain specfic header files
 */
#if (defined(CW))
	#include "cw.h"
#elif (defined(IAR))
	#include "iar.h"
#elif (defined(GCC))
	#include "gcc.h"
#else
	#warning "No toolchain specific header included"
#endif

/*
 * Include common utilities
 */
#include "stdlib.h"

#if (defined(IAR))
	#include "intrinsics.h"
#endif

/********************************************************************/

#endif /* COMMON_H */
