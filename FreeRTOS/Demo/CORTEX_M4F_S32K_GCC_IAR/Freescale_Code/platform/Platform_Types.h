/**
    @file        Platform_Types.h
    @version     0.9.0

    @brief       Platform dependent data type definitions.
    @details     Platform types header file. It contains all
                 platform dependent types and symbols. Those types must be abstracted in order to
                 become platform and compiler independent.

    Platform     : ARM
    Peripheral   : S32K144
    Dependencies : none

    (c) Copyright 2015 Freescale Semiconductor Inc.
    All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/

/**
@file        Platform_Types.h
*/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

#ifndef NULL
    /**
    @brief Null pointer definition
    */
	#define NULL ((void*) 0)
#endif

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* IO definitions (access restrictions to peripheral registers) */
/**
    IO Type Qualifiers are used
    \li to specify the access to peripheral variables.
    \li for automatic generation of peripheral register debug information.
*/
#ifndef __IO
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#if !defined(IAR)
/**
@brief Unsigned 8 bit integer with range of 0 ..+255 (0x00..0xFF) -
       8 bit
*/
typedef unsigned char uint8;

/**
@brief Unsigned 16 bit integer with range of 0 ..+65535 (0x0000..0xFFFF) -
       16 bit
*/
typedef unsigned short uint16;

/**
@brief Unsigned 32 bit integer with range of 0 ..+4294967295 (0x00000000..0xFFFFFFFF) -
       32 bit
*/
typedef unsigned long uint32;

/**
@brief Signed 8 bit integer with range of -128 ..+127 (0x80..0x7F) -
       7 bit + 1 sign bit
*/
typedef signed char sint8;

/**
@brief Signed 16 bit integer with range of -32768 ..+32767 (0x8000..0x7FFF) -
       15 bit + 1 sign bit
*/
typedef signed short sint16;

/**
@brief Signed 32 bit integer with range of -2147483648.. +2147483647 (0x80000000..0x7FFFFFFF) -
       31 bit + 1 sign bit
*/
typedef signed long sint32;

/**
@brief Unsigned integer at least 8 bit long. Range of at least 0 ..+255 (0x00..0xFF) -
       8 bit
*/
typedef unsigned long uint8_least;

/**
@brief  Unsigned integer at least 16 bit long. Range of at least 0 ..+65535 (0x0000..0xFFFF) -
        16 bit
*/
typedef unsigned long uint16_least;

/**
@brief Unsigned integer at least 32 bit long. Range of at least 0 ..+4294967295 (0x00000000..0xFFFFFFFF) -
       32 bit
*/
typedef unsigned long uint32_least;

/**
@brief Signed integer at least 8 bit long. Range - at least -128 ..+127.
       At least 7 bit + 1 bit sign
*/
typedef signed long sint8_least;

/**
@brief Signed integer at least 16 bit long. Range - at least -32768 ..+32767.
       At least 15 bit + 1 bit sign
*/
typedef signed long sint16_least;

/**
@brief Signed integer at least 32 bit long. Range - at least -2147483648.. +2147483647.
       At least 31 bit + 1 bit sign
*/
typedef signed long sint32_least;

/**
@brief 32bit long floating point data type
*/
typedef float float32;

/**
@brief 64bit long floating point data type
*/
typedef double float64;

#endif

/**
@brief Unsigned pointer compatible type.
*/
typedef unsigned int uintptr;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* #ifndef PLATFORM_TYPES_H */
