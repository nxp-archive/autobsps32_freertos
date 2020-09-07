/*
 * Copyright 2019, 2020 NXP.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef HW_SYSTEM_H
#define HW_SYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#define CM7_0  (0UL)
#define CM7_1  (1UL)

/* ----------------------------------------------------------------------------
   -- Generic macros
   ---------------------------------------------------------------------------- */

/* IO definitions (access restrictions to peripheral registers) */
/**
*   IO Type Qualifiers are used
*   \li to specify the access to peripheral variables.
*   \li for automatic generation of peripheral register debug information.
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


/*! @name IRSPRC - Interrupt Router Shared Peripheral Routing Control Register */
/*! @{ */
#define MSCM_IRSPRC_M7_0_MASK                    (0x1U)
#define MSCM_IRSPRC_M7_0_SHIFT                   (0U)
#define MSCM_IRSPRC_M7_0_WIDTH                   (1U)
#define MSCM_IRSPRC_M7_0(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_M7_0_SHIFT)) & MSCM_IRSPRC_M7_0_MASK)
#define MSCM_IRSPRC_M7_1_MASK                    (0x2U)
#define MSCM_IRSPRC_M7_1_SHIFT                   (1U)
#define MSCM_IRSPRC_M7_1_WIDTH                   (1U)
#define MSCM_IRSPRC_M7_1(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_M7_1_SHIFT)) & MSCM_IRSPRC_M7_1_MASK)
#define MSCM_IRSPRC_LOCK_MASK                    (0x8000U)
#define MSCM_IRSPRC_LOCK_SHIFT                   (15U)
#define MSCM_IRSPRC_LOCK_WIDTH                   (1U)
#define MSCM_IRSPRC_LOCK(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_LOCK_SHIFT)) & MSCM_IRSPRC_LOCK_MASK)
/*! @} */

/** MSCM - Size of Registers Arrays */
#define MSCM_IRSPRC_COUNT                         240u
/** MSCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t CPXTYPE;                           /**< Processor x Type Register, offset: 0x0 */
  __I  uint32_t CPXNUM;                            /**< Processor x Number Register, offset: 0x4 */
  __I  uint32_t CPXREV;                            /**< Processor x Revision Register, offset: 0x8 */
  __I  uint32_t CPXCFG0;                           /**< Processor x Configuration 0 Register, offset: 0xC */
  __I  uint32_t CPXCFG1;                           /**< Processor x Configuration 1 Register, offset: 0x10 */
  __I  uint32_t CPXCFG2;                           /**< Processor x Configuration 2 Register, offset: 0x14 */
  __I  uint32_t CPXCFG3;                           /**< Processor x Configuration 3 Register, offset: 0x18 */
  uint8_t RESERVED_0[4];
  __I  uint32_t CP0TYPE;                           /**< Processor 0 Type Register, offset: 0x20 */
  __I  uint32_t CP0NUM;                            /**< Processor 0 Number Register, offset: 0x24 */
  __I  uint32_t CP0REV;                            /**< Processor 0 Count Register, offset: 0x28 */
  __I  uint32_t CP0CFG0;                           /**< Processor 0 Configuration 0 Register, offset: 0x2C */
  __I  uint32_t CP0CFG1;                           /**< Processor 0 Configuration 1 Register, offset: 0x30 */
  __I  uint32_t CP0CFG2;                           /**< Processor 0 Configuration 2 Register, offset: 0x34 */
  __I  uint32_t CP0CFG3;                           /**< Processor 0 Configuration 3 Register, offset: 0x38 */
  uint8_t RESERVED_1[4];
  __I  uint32_t CP1TYPE;                           /**< Processor 1 Type Register, offset: 0x40 */
  __I  uint32_t CP1NUM;                            /**< Processor 1 Number Register, offset: 0x44 */
  __I  uint32_t CP1REV;                            /**< Processor 1 Count Register, offset: 0x48 */
  __I  uint32_t CP1CFG0;                           /**< Processor 1 Configuration 0 Register, offset: 0x4C */
  __I  uint32_t CP1CFG1;                           /**< Processor 1 Configuration 1 Register, offset: 0x50 */
  __I  uint32_t CP1CFG2;                           /**< Processor 1 Configuration 2 Register, offset: 0x54 */
  __I  uint32_t CP1CFG3;                           /**< Processor 1 Configuration 3 Register, offset: 0x58 */
  uint8_t RESERVED_2[420];
  __IO uint32_t IRCP0ISR0;                         /**< Interrupt Router CP0 Interrupt Status Register, offset: 0x200 */
  __O  uint32_t IRCP0IGR0;                         /**< Interrupt Router CP0 Interrupt Generation Register, offset: 0x204 */
  __IO uint32_t IRCP0ISR1;                         /**< Interrupt Router CP0 Interrupt Status Register, offset: 0x208 */
  __O  uint32_t IRCP0IGR1;                         /**< Interrupt Router CP0 Interrupt Generation Register, offset: 0x20C */
  __IO uint32_t IRCP0ISR2;                         /**< Interrupt Router CP0 Interrupt Status Register, offset: 0x210 */
  __O  uint32_t IRCP0IGR2;                         /**< Interrupt Router CP0 Interrupt Generation Register, offset: 0x214 */
  __IO uint32_t IRCP0ISR3;                         /**< Interrupt Router CP0 Interrupt Status Register, offset: 0x218 */
  __O  uint32_t IRCP0IGR3;                         /**< Interrupt Router CP0 Interrupt Generation Register, offset: 0x21C */
  __IO uint32_t IRCP1ISR0;                         /**< Interrupt Router CP1 Interrupt Status Register, offset: 0x220 */
  __O  uint32_t IRCP1IGR0;                         /**< Interrupt Router CP1 Interrupt Generation Register, offset: 0x224 */
  __IO uint32_t IRCP1ISR1;                         /**< Interrupt Router CP1 Interrupt Status Register, offset: 0x228 */
  __O  uint32_t IRCP1IGR1;                         /**< Interrupt Router CP1 Interrupt Generation Register, offset: 0x22C */
  __IO uint32_t IRCP1ISR2;                         /**< Interrupt Router CP1 Interrupt Status Register, offset: 0x230 */
  __O  uint32_t IRCP1IGR2;                         /**< Interrupt Router CP1 Interrupt Generation Register, offset: 0x234 */
  __IO uint32_t IRCP1ISR3;                         /**< Interrupt Router CP1 Interrupt Status Register, offset: 0x238 */
  __O  uint32_t IRCP1IGR3;                         /**< Interrupt Router CP1 Interrupt Generation Register, offset: 0x23C */
  uint8_t RESERVED_3[448];
  __IO uint32_t IRCPCFG;                           /**< Interrupt Router Configuration Register, offset: 0x400 */
  uint8_t RESERVED_4[508];
  __IO uint32_t ENEDC;                             /**< Enable Interconnect Error Detection Register, offset: 0x600 */
  uint8_t RESERVED_5[252];
  __IO uint32_t IAHBCFGREG;                        /**< AHB Gasket Configuration Register, offset: 0x700 */
  uint8_t RESERVED_6[380];
  __IO uint16_t IRSPRC[MSCM_IRSPRC_COUNT];         /**< Interrupt Router Shared Peripheral Routing Control Register, array offset: 0x880, array step: 0x2 */
} MSCM_Type, *MSCM_MemMapPtr;

/** Number of instances of the MSCM module. */
#define MSCM_INSTANCE_COUNT                      (1u)

/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define MSCM_BASE                                (0x40260000u)
/** Peripheral MSCM base pointer */
#define MSCM                                     ((MSCM_Type *)MSCM_BASE)
/** Array initializer of MSCM peripheral base addresses */
#define MSCM_BASE_ADDRS                          { MSCM_BASE }
/** Array initializer of MSCM peripheral base pointers */
#define MSCM_BASE_PTRS                           { MSCM }

/*! @name CPXNUM - Processor x Number Register */
/*! @{ */
#define MSCM_CPXNUM_CPN_MASK                     (0x3U)
#define MSCM_CPXNUM_CPN_SHIFT                    (0U)
#define MSCM_CPXNUM_CPN_WIDTH                    (2U)
#define MSCM_CPXNUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPXNUM_CPN_SHIFT)) & MSCM_CPXNUM_CPN_MASK)
/*! @} */

#ifdef __cplusplus
}
#endif

#endif /** HW_SYSTEM_H */