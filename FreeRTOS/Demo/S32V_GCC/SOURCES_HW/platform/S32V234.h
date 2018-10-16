/**************************************************************************
 * FILE NAME: S32V234.h                      COPYRIGHT (c) Freescale 2015 *
 *                                                    All Rights Reserved *
 *                                                                        *
 * DESCRIPTION:                                                           *
 * This file contains all of the register and bit field definitions for   *
 * the S32V234.                                                           *
 **************************************************************************/

#ifndef S32V234_H
#define S32V234_H
#include "stdint.h"


#ifdef __cplusplus
extern "C" {
#endif
#ifdef __MWERKS__
#pragma push
#pragma ANSI_strict off
#endif


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


/**
 * @brief Macro to access a single bit of a 32-bit peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_ACCESS32(Reg,Bit) (*((uint32_t volatile*)(0x42000000u + (32u*((uintptr_t)(Reg) - (uintptr_t)0x40000000u)) + (4u*((uintptr_t)(Bit))))))

/**
 * @brief Macro to access a single bit of a 16-bit peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_ACCESS16(Reg,Bit) (*((uint16_t volatile*)(0x42000000u + (32u*((uintptr_t)(Reg) - (uintptr_t)0x40000000u)) + (4u*((uintptr_t)(Bit))))))

/**
 * @brief Macro to access a single bit of an 8-bit peripheral register (bit band region
 *        0x40000000 to 0x400FFFFF) using the bit-band alias region access.
 * @param Reg Register to access.
 * @param Bit Bit number to access.
 * @return Value of the targeted bit in the bit band region.
 */
#define BITBAND_ACCESS8(Reg,Bit) (*((uint8_t volatile*)(0x42000000u + (32u*((uintptr_t)(Reg) - (uintptr_t)0x40000000u)) + (4u*((uintptr_t)(Bit))))))

/**
* @brief 32 bits memory read macro.
*/
#define REG_READ32(address)               (*(volatile uint32_t*)(address))

/**
* @brief 32 bits memory write macro.
*/
#define REG_WRITE32(address, value)       ((*(volatile uint32_t*)(address))= (uint32_t)(value))

/**
* @brief 32 bits bits setting macro.
*/
#define REG_BIT_SET32(address, mask)      ((*(volatile uint32_t*)(address))|= (uint32_t)(mask))

/**
* @brief 32 bits bits clearing macro.
*/
#define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32_t*)(address))&= ((uint32_t)~((uint32_t)(mask))))

/**
* @brief 8 bits memory read macro.
*/
#define REG_READ8(address)               (*(volatile uint8_t*)(address))

/**
* @brief 8 bits memory write macro.
*/
#define REG_WRITE8(address, value)       ((*(volatile uint8_t*)(address))= (uint8_t)(value))

/**
* @brief 8 bits bits setting macro.
*/
#define REG_BIT_SET8(address, mask)      ((*(volatile uint8_t*)(address))|= (uint8_t)(mask))

/**
* @brief 8 bits bits clearing macro.
*/
#define REG_BIT_CLEAR8(address, mask)    ((*(volatile uint8_t*)(address))&= ((uint8_t)~((uint8_t)(mask))))


/**
* @brief 32 bit clear bits and set with new value
* @note It is user's responsability to make sure that value has only "mask" bits set - (value&~mask)==0
*/
#define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32_t)~((uint32_t)(mask))))| ((uint32_t)(value)))))

#define SIUL2_BASE_ADDR				0x4006C000
#define SIUL2_MIDR1					(SIUL2_BASE_ADDR + 0x00000004)
#define SIUL2_MIDR2					(SIUL2_BASE_ADDR + 0x00000008)
#define SIUL2_DISR0					(SIUL2_BASE_ADDR + 0x00000010)
#define SIUL2_DIRER0				(SIUL2_BASE_ADDR + 0x00000018)
#define SIUL2_DIRSR0				(SIUL2_BASE_ADDR + 0x00000020)
#define SIUL2_IREER0				(SIUL2_BASE_ADDR + 0x00000028)
#define SIUL2_IFEER0				(SIUL2_BASE_ADDR + 0x00000030)
#define SIUL2_IFER0					(SIUL2_BASE_ADDR + 0x00000038)

#define SIUL2_IFMCR_BASE			(SIUL2_BASE_ADDR + 0x00000040)
#define SIUL2_IFMCRn(i)				(SIUL2_IFMCR_BASE + 4 * (i))

#define SIUL2_IFCPR					(SIUL2_BASE_ADDR + 0x000000C0)

/* SIUL2_MSCR specifications as stated in Reference Manual:
 * 0 - 359 Output Multiplexed Signal Configuration Registers
 * 512- 1023 Input Multiplexed Signal Configuration Registers */
#define SIUL2_MSCR_BASE				(SIUL2_BASE_ADDR + 0x00000240)
#define SIUL2_MSCRn(i)				(SIUL2_MSCR_BASE + 4 * (i))

#define SIUL2_IMCR_BASE				(SIUL2_BASE_ADDR + 0x00000A40)
#define SIUL2_IMCRn(i)				(SIUL2_IMCR_BASE +  4 * (i))

#define SIUL2_GPDO_BASE				(SIUL2_BASE_ADDR + 0x00001300)
#define SIUL2_GPDOn(i)				(SIUL2_GPDO_BASE + 4 * (i))

#define SIUL2_GPDI_BASE				(SIUL2_BASE_ADDR + 0x00001500)
#define SIUL2_GPDIn(i)				(SIUL2_GPDI_BASE + 4 * (i))

#define SIUL2_PGPDO_BASE			(SIUL2_BASE_ADDR + 0x00001700)
#define SIUL2_PGPDOn(i)				(SIUL2_PGPDO_BASE +  2 * (i))

#define SIUL2_PGPDI_BASE			(SIUL2_BASE_ADDR + 0x00001740)
#define SIUL2_PGPDIn(i)				(SIUL2_PGPDI_BASE + 2 * (i))

#define SIUL2_MPGPDO_BASE			(SIUL2_BASE_ADDR + 0x00001780)
#define SIUL2_MPGPDOn(i)			(SIUL2_MPGPDO_BASE + 4 * (i))

/* SIUL2_MSCR masks */
#define SIUL2_MSCR_DDR_DO_TRIM(v)		((v) & 0xC0000000)
#define SIUL2_MSCR_DDR_DO_TRIM_MIN		(0 << 30)
#define SIUL2_MSCR_DDR_DO_TRIM_50PS		(1 << 30)
#define SIUL2_MSCR_DDR_DO_TRIM_100PS	(2 << 30)
#define SIUL2_MSCR_DDR_DO_TRIM_150PS	(3 << 30)


#define SIUL2_MSCR_DDR_INPUT(v)			((v) & 0x20000000)
#define SIUL2_MSCR_DDR_INPUT_CMOS		(0 << 29)
#define SIUL2_MSCR_DDR_INPUT_DIFF_DDR	(1 << 29)

#define SIUL2_MSCR_DDR_SEL(v)		((v) & 0x18000000)
#define SIUL2_MSCR_DDR_SEL_DDR3		(0 << 27)
#define SIUL2_MSCR_DDR_SEL_LPDDR2	(2 << 27)

#define SIUL2_MSCR_DDR_ODT(v)		((v) & 0x07000000)
#define SIUL2_MSCR_DDR_ODT_120ohm	(1 << 24)
#define SIUL2_MSCR_DDR_ODT_60ohm	(2 << 24)
#define SIUL2_MSCR_DDR_ODT_40ohm	(3 << 24)
#define SIUL2_MSCR_DDR_ODT_30ohm	(4 << 24)
#define SIUL2_MSCR_DDR_ODT_24ohm	(5 << 24)
#define SIUL2_MSCR_DDR_ODT_20ohm	(6 << 24)
#define SIUL2_MSCR_DDR_ODT_17ohm	(7 << 24)

#define SIUL2_MSCR_DCYCLE_TRIM(v)		((v) & 0x00C00000)
#define SIUL2_MSCR_DCYCLE_TRIM_NONE		(0 << 22)
#define SIUL2_MSCR_DCYCLE_TRIM_LEFT		(1 << 22)
#define SIUL2_MSCR_DCYCLE_TRIM_RIGHT	(2 << 22)

#define SIUL2_MSCR_OBE(v)			((v) & 0x00200000)
#define SIUL2_MSCR_OBE_EN			(1 << 21)

#define SIUL2_MSCR_ODE(v)			((v) & 0x00100000)
#define SIUL2_MSCR_ODE_EN			(1 << 20)

#define SIUL2_MSCR_IBE(v)			((v) & 0x00010000)
#define SIUL2_MSCR_IBE_EN			(1 << 19)

#define SIUL2_MSCR_HYS(v)			((v) & 0x00400000)
#define SIUL2_MSCR_HYS_EN			(1 << 18)

#define SIUL2_MSCR_INV(v)			((v) & 0x00020000)
#define SIUL2_MSCR_INV_EN			(1 << 17)

#define SIUL2_MSCR_PKE(v)			((v) & 0x00010000)
#define SIUL2_MSCR_PKE_EN			(1 << 16)

#define SIUL2_MSCR_SRE(v)			((v) & 0x0000C000)
#define SIUL2_MSCR_SRE_SPEED_LOW_50		(0 << 14)
#define SIUL2_MSCR_SRE_SPEED_LOW_100	(1 << 14)
#define SIUL2_MSCR_SRE_SPEED_HIGH_100	(2 << 14)
#define SIUL2_MSCR_SRE_SPEED_HIGH_200	(3 << 14)


#define SIUL2_MSCR_PUE(v)			((v) & 0x00002000)
#define SIUL2_MSCR_PUE_EN			(1 << 13)

#define SIUL2_MSCR_PUS(v)			((v) & 0x00001800)
#define SIUL2_MSCR_PUS_100K_DOWN	(0 << 11)
#define SIUL2_MSCR_PUS_50K_DOWN		(1 << 11)
#define SIUL2_MSCR_PUS_100K_UP		(2 << 11)
#define SIUL2_MSCR_PUS_33K_UP		(3 << 11)

#define SIUL2_MSCR_DSE(v)			((v) & 0x00000700)
#define SIUL2_MSCR_DSE_240ohm		(1 << 8)
#define SIUL2_MSCR_DSE_120ohm		(2 << 8)
#define SIUL2_MSCR_DSE_80ohm		(3 << 8)
#define SIUL2_MSCR_DSE_60ohm		(4 << 8)
#define SIUL2_MSCR_DSE_48ohm		(5 << 8)
#define SIUL2_MSCR_DSE_40ohm		(6 << 8)
#define SIUL2_MSCR_DSE_34ohm		(7 << 8)

#define SIUL2_MSCR_CRPOINT_TRIM(v)	((v) & 0x000000C0)
#define SIUL2_MSCR_CRPOINT_TRIM_1	(1 << 6)

#define SIUL2_MSCR_SMC(v)			((v) & 0x00000020)
#define SIUL2_MSCR_MUX_MODE(v)		((v) & 0x0000000f)
#define SIUL2_MSCR_MUX_MODE_ALT1	(0x1)
#define SIUL2_MSCR_MUX_MODE_ALT2	(0x2)
#define SIUL2_MSCR_MUX_MODE_ALT3	(0x3)
#define SIUL2_MSCR_MUX_MODE_ALT4	(0x4)


/* UART settings */

/* UART0 */
#define SIUL2_UART0_TXD_PAD	12
#define SIUL2_UART0_MSCR_RXD_PAD	11
#define SIUL2_UART0_IMCR_RXD_PAD	200

/* UART1 */
#define SIUL2_UART1_TXD_PAD	14
#define SIUL2_UART1_MSCR_RXD_PAD	13
#define SIUL2_UART1_IMCR_RXD_PAD	202

#define SIUL2_UART_TXD		(SIUL2_MSCR_OBE_EN | SIUL2_MSCR_PUS_100K_UP | SIUL2_MSCR_DSE_60ohm |	\
				SIUL2_MSCR_SRE_SPEED_LOW_100 | SIUL2_MSCR_MUX_MODE_ALT1)

#define SIUL2_UART_MSCR_RXD	(SIUL2_MSCR_PUE_EN | SIUL2_MSCR_IBE_EN | SIUL2_MSCR_DCYCLE_TRIM_RIGHT)
#define SIUL2_UART_IMCR_RXD	(SIUL2_MSCR_MUX_MODE_ALT2)

/* uSDHC settings */
#define SIUL2_USDHC_PAD_CTRL_BASE	(SIUL2_MSCR_SRE_SPEED_HIGH_200 | SIUL2_MSCR_OBE_EN |	\
						SIUL2_MSCR_DSE_34ohm | SIUL2_MSCR_PKE_EN | SIUL2_MSCR_IBE_EN |		\
						SIUL2_MSCR_PUS_100K_UP | SIUL2_MSCR_PUE_EN )
#define SIUL2_USDHC_PAD_CTRL_CMD	(SIUL2_USDHC_PAD_CTRL_BASE | SIUL2_MSCR_MUX_MODE_ALT1)
#define SIUL2_USDHC_PAD_CTRL_CLK	(SIUL2_USDHC_PAD_CTRL_BASE | SIUL2_MSCR_MUX_MODE_ALT2)
#define SIUL2_USDHC_PAD_CTRL_DAT0_3	(SIUL2_USDHC_PAD_CTRL_BASE | SIUL2_MSCR_MUX_MODE_ALT2)
#define SIUL2_USDHC_PAD_CTRL_DAT4_7	(SIUL2_USDHC_PAD_CTRL_BASE | SIUL2_MSCR_MUX_MODE_ALT3)

/* I2C settings */
/* I2C0 - Serial Data Input */
#define  SIUL2_PAD_CTRL_I2C0_MSCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT2 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
												SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C0_IMCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT3)


/* I2C0 - Serial Clock Input */
#define  SIUL2_PAD_CTRL_I2C0_MSCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT2 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
											SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C0_IMCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT3)

/* I2C1 - Serial Data Input */
#define  SIUL2_PAD_CTRL_I2C1_MSCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT2 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
											SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C1_IMCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT3)

/* I2C1 - Serial Clock Input */
#define  SIUL2_PAD_CTRL_I2C1_MSCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT2 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
											SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C1_IMCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT3)

/* I2C2 - Serial Data Input */
#define  SIUL2_PAD_CTRL_I2C2_MSCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT1 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
												SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C2_IMCR_SDA	(SIUL2_MSCR_MUX_MODE_ALT2)

/* I2C2 - Serial Clock Input */
#define  SIUL2_PAD_CTRL_I2C2_MSCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT1 | SIUL2_MSCR_OBE_EN | SIUL2_MSCR_IBE_EN | \
											SIUL2_MSCR_ODE_EN | SIUL2_MSCR_DSE_34ohm)
#define SIUL2_PAD_CTRL_I2C2_IMCR_SCLK	(SIUL2_MSCR_MUX_MODE_ALT2)

/* ----------------------------------------------------------------------------
   -- FSL_NVIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSL_NVIC_Peripheral_Access_Layer FSL_NVIC Peripheral Access Layer
 * @{
 */


/** FSL_NVIC - Size of Registers Arrays */
#define FSL_NVIC_ISER_COUNT                      4u
#define FSL_NVIC_ICER_COUNT                      4u
#define FSL_NVIC_ISPR_COUNT                      4u
#define FSL_NVIC_ICPR_COUNT                      4u
#define FSL_NVIC_IABR_COUNT                      4u
#define FSL_NVIC_IP_COUNT                        106u
#define FSL_NVIC_STIR_COUNT                      1u

/** FSL_NVIC - Register Layout Typedef */
typedef struct {
  __IO uint32_t ISER[FSL_NVIC_ISER_COUNT];         /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[112];
  __IO uint32_t ICER[FSL_NVIC_ICER_COUNT];         /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_1[112];
  __IO uint32_t ISPR[FSL_NVIC_ISPR_COUNT];         /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_2[112];
  __IO uint32_t ICPR[FSL_NVIC_ICPR_COUNT];         /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
       uint8_t RESERVED_3[112];
  __IO uint32_t IABR[FSL_NVIC_IABR_COUNT];         /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_4[240];
  __IO uint8_t IP[FSL_NVIC_IP_COUNT];              /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
       uint8_t RESERVED_5[2710];
  __IO uint32_t STIR[FSL_NVIC_STIR_COUNT];         /**< Software Trigger Interrupt Register, array offset: 0xE00, array step: 0x4 */
} FSL_NVIC_Type, *FSL_NVIC_MemMapPtr;

 /** Number of instances of the FSL_NVIC module. */
#define FSL_NVIC_INSTANCE_COUNT (1u)


/* FSL_NVIC - Peripheral instance base addresses */
/** Peripheral FSL_NVIC base address */
#define FSL_NVIC_BASE                            (0xE000E100u)
/** Peripheral FSL_NVIC base pointer */
#define FSL_NVIC                                 ((FSL_NVIC_Type *)FSL_NVIC_BASE)
/** Array initializer of FSL_NVIC peripheral base addresses */
#define FSL_NVIC_BASE_ADDRS                      { FSL_NVIC_BASE }
/** Array initializer of FSL_NVIC peripheral base pointers */
#define FSL_NVIC_BASE_PTRS                       { FSL_NVIC }
/** Interrupt vectors for the FSL_NVIC peripheral type */
#define FSL_NVIC_IRQS                            { SWI_IRQn }

/* ----------------------------------------------------------------------------
   -- FSL_NVIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSL_NVIC_Register_Masks FSL_NVIC Register Masks
 * @{
 */

/* ISER Bit Fields */
#define FSL_NVIC_ISER_SETENA_MASK                0xFFFFFFFFu
#define FSL_NVIC_ISER_SETENA_SHIFT               0u
#define FSL_NVIC_ISER_SETENA_WIDTH               32u
#define FSL_NVIC_ISER_SETENA(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_NVIC_ISER_SETENA_SHIFT))&FSL_NVIC_ISER_SETENA_MASK)
/* ICER Bit Fields */
#define FSL_NVIC_ICER_CLRENA_MASK                0xFFFFFFFFu
#define FSL_NVIC_ICER_CLRENA_SHIFT               0u
#define FSL_NVIC_ICER_CLRENA_WIDTH               32u
#define FSL_NVIC_ICER_CLRENA(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_NVIC_ICER_CLRENA_SHIFT))&FSL_NVIC_ICER_CLRENA_MASK)
/* ISPR Bit Fields */
#define FSL_NVIC_ISPR_SETPEND_MASK               0xFFFFFFFFu
#define FSL_NVIC_ISPR_SETPEND_SHIFT              0u
#define FSL_NVIC_ISPR_SETPEND_WIDTH              32u
#define FSL_NVIC_ISPR_SETPEND(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_NVIC_ISPR_SETPEND_SHIFT))&FSL_NVIC_ISPR_SETPEND_MASK)
/* ICPR Bit Fields */
#define FSL_NVIC_ICPR_CLRPEND_MASK               0xFFFFFFFFu
#define FSL_NVIC_ICPR_CLRPEND_SHIFT              0u
#define FSL_NVIC_ICPR_CLRPEND_WIDTH              32u
#define FSL_NVIC_ICPR_CLRPEND(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_NVIC_ICPR_CLRPEND_SHIFT))&FSL_NVIC_ICPR_CLRPEND_MASK)
/* IABR Bit Fields */
#define FSL_NVIC_IABR_ACTIVE_MASK                0xFFFFFFFFu
#define FSL_NVIC_IABR_ACTIVE_SHIFT               0u
#define FSL_NVIC_IABR_ACTIVE_WIDTH               32u
#define FSL_NVIC_IABR_ACTIVE(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_NVIC_IABR_ACTIVE_SHIFT))&FSL_NVIC_IABR_ACTIVE_MASK)
/* STIR Bit Fields */
#define FSL_NVIC_STIR_INTID_MASK                 0x1FFu
#define FSL_NVIC_STIR_INTID_SHIFT                0u
#define FSL_NVIC_STIR_INTID_WIDTH                9u
#define FSL_NVIC_STIR_INTID(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_NVIC_STIR_INTID_SHIFT))&FSL_NVIC_STIR_INTID_MASK)

/* ----------------------------------------------------------------------------
   -- FSL_SCB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSL_SCB_Peripheral_Access_Layer FSL_SCB Peripheral Access Layer
 * @{
 */


/** FSL_SCB - Size of Registers Arrays */

/** FSL_SCB - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t ACTLR;                             /**< Auxiliary Control Register,, offset: 0x8 */
       uint8_t RESERVED_1[3316];
  __I  uint32_t CPUID;                             /**< CPUID Base Register, offset: 0xD00 */
  __IO uint32_t ICSR;                              /**< Interrupt Control and State Register, offset: 0xD04 */
  __IO uint32_t VTOR;                              /**< Vector Table Offset Register, offset: 0xD08 */
  __IO uint32_t AIRCR;                             /**< Application Interrupt and Reset Control Register, offset: 0xD0C */
  __IO uint32_t SCR;                               /**< System Control Register, offset: 0xD10 */
  __IO uint32_t CCR;                               /**< Configuration and Control Register, offset: 0xD14 */
  __IO uint32_t SHPR1;                             /**< System Handler Priority Register 1, offset: 0xD18 */
  __IO uint32_t SHPR2;                             /**< System Handler Priority Register 2, offset: 0xD1C */
  __IO uint32_t SHPR3;                             /**< System Handler Priority Register 3, offset: 0xD20 */
  __IO uint32_t SHCSR;                             /**< System Handler Control and State Register, offset: 0xD24 */
  __IO uint32_t CFSR;                              /**< Configurable Fault Status Registers, offset: 0xD28 */
  __IO uint32_t HFSR;                              /**< HardFault Status register, offset: 0xD2C */
  __IO uint32_t DFSR;                              /**< Debug Fault Status Register, offset: 0xD30 */
  __IO uint32_t MMFAR;                             /**< MemManage Address Register, offset: 0xD34 */
  __IO uint32_t BFAR;                              /**< BusFault Address Register, offset: 0xD38 */
  __IO uint32_t AFSR;                              /**< Auxiliary Fault Status Register, offset: 0xD3C */
       uint8_t RESERVED_2[72];
  __IO uint32_t CPACR;                             /**< Coprocessor Access Control Register, offset: 0xD88 */
       uint8_t RESERVED_3[424];
  __IO uint32_t FPCCR;                             /**< Floating-point Context Control Register, offset: 0xF34 */
  __IO uint32_t FPCAR;                             /**< Floating-point Context Address Register, offset: 0xF38 */
  __IO uint32_t FPDSCR;                            /**< Floating-point Default Status Control Register, offset: 0xF3C */
} FSL_SCB_Type, *FSL_SCB_MemMapPtr;

 /** Number of instances of the FSL_SCB module. */
#define FSL_SCB_INSTANCE_COUNT (1u)


/* FSL_SCB - Peripheral instance base addresses */
/** Peripheral FSL_SCB base address */
#define FSL_SCB_BASE                             (0xE000E000u)
/** Peripheral FSL_SCB base pointer */
#define FSL_SCB                                  ((FSL_SCB_Type *)FSL_SCB_BASE)
/** Array initializer of FSL_SCB peripheral base addresses */
#define FSL_SCB_BASE_ADDRS                       { FSL_SCB_BASE }
/** Array initializer of FSL_SCB peripheral base pointers */
#define FSL_SCB_BASE_PTRS                        { FSL_SCB }

/* ----------------------------------------------------------------------------
   -- FSL_SCB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSL_SCB_Register_Masks FSL_SCB Register Masks
 * @{
 */

/* ACTLR Bit Fields */
#define FSL_SCB_ACTLR_DISMCYCINT_MASK            0x1u
#define FSL_SCB_ACTLR_DISMCYCINT_SHIFT           0u
#define FSL_SCB_ACTLR_DISMCYCINT_WIDTH           1u
#define FSL_SCB_ACTLR_DISMCYCINT(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ACTLR_DISMCYCINT_SHIFT))&FSL_SCB_ACTLR_DISMCYCINT_MASK)
#define FSL_SCB_ACTLR_DISDEFWBUF_MASK            0x2u
#define FSL_SCB_ACTLR_DISDEFWBUF_SHIFT           1u
#define FSL_SCB_ACTLR_DISDEFWBUF_WIDTH           1u
#define FSL_SCB_ACTLR_DISDEFWBUF(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ACTLR_DISDEFWBUF_SHIFT))&FSL_SCB_ACTLR_DISDEFWBUF_MASK)
#define FSL_SCB_ACTLR_DISFOLD_MASK               0x4u
#define FSL_SCB_ACTLR_DISFOLD_SHIFT              2u
#define FSL_SCB_ACTLR_DISFOLD_WIDTH              1u
#define FSL_SCB_ACTLR_DISFOLD(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ACTLR_DISFOLD_SHIFT))&FSL_SCB_ACTLR_DISFOLD_MASK)
/* CPUID Bit Fields */
#define FSL_SCB_CPUID_REVISION_MASK              0xFu
#define FSL_SCB_CPUID_REVISION_SHIFT             0u
#define FSL_SCB_CPUID_REVISION_WIDTH             4u
#define FSL_SCB_CPUID_REVISION(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPUID_REVISION_SHIFT))&FSL_SCB_CPUID_REVISION_MASK)
#define FSL_SCB_CPUID_PARTNO_MASK                0xFFF0u
#define FSL_SCB_CPUID_PARTNO_SHIFT               4u
#define FSL_SCB_CPUID_PARTNO_WIDTH               12u
#define FSL_SCB_CPUID_PARTNO(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPUID_PARTNO_SHIFT))&FSL_SCB_CPUID_PARTNO_MASK)
#define FSL_SCB_CPUID_VARIANT_MASK               0xF00000u
#define FSL_SCB_CPUID_VARIANT_SHIFT              20u
#define FSL_SCB_CPUID_VARIANT_WIDTH              4u
#define FSL_SCB_CPUID_VARIANT(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPUID_VARIANT_SHIFT))&FSL_SCB_CPUID_VARIANT_MASK)
#define FSL_SCB_CPUID_IMPLEMENTER_MASK           0xFF000000u
#define FSL_SCB_CPUID_IMPLEMENTER_SHIFT          24u
#define FSL_SCB_CPUID_IMPLEMENTER_WIDTH          8u
#define FSL_SCB_CPUID_IMPLEMENTER(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPUID_IMPLEMENTER_SHIFT))&FSL_SCB_CPUID_IMPLEMENTER_MASK)
/* ICSR Bit Fields */
#define FSL_SCB_ICSR_VECTACTIVE_MASK             0x1FFu
#define FSL_SCB_ICSR_VECTACTIVE_SHIFT            0u
#define FSL_SCB_ICSR_VECTACTIVE_WIDTH            9u
#define FSL_SCB_ICSR_VECTACTIVE(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_VECTACTIVE_SHIFT))&FSL_SCB_ICSR_VECTACTIVE_MASK)
#define FSL_SCB_ICSR_RETTOBASE_MASK              0x800u
#define FSL_SCB_ICSR_RETTOBASE_SHIFT             11u
#define FSL_SCB_ICSR_RETTOBASE_WIDTH             1u
#define FSL_SCB_ICSR_RETTOBASE(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_RETTOBASE_SHIFT))&FSL_SCB_ICSR_RETTOBASE_MASK)
#define FSL_SCB_ICSR_VECTPENDING_MASK            0x3F000u
#define FSL_SCB_ICSR_VECTPENDING_SHIFT           12u
#define FSL_SCB_ICSR_VECTPENDING_WIDTH           6u
#define FSL_SCB_ICSR_VECTPENDING(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_VECTPENDING_SHIFT))&FSL_SCB_ICSR_VECTPENDING_MASK)
#define FSL_SCB_ICSR_ISRPENDING_MASK             0x400000u
#define FSL_SCB_ICSR_ISRPENDING_SHIFT            22u
#define FSL_SCB_ICSR_ISRPENDING_WIDTH            1u
#define FSL_SCB_ICSR_ISRPENDING(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_ISRPENDING_SHIFT))&FSL_SCB_ICSR_ISRPENDING_MASK)
#define FSL_SCB_ICSR_ISRPREEMPT_MASK             0x800000u
#define FSL_SCB_ICSR_ISRPREEMPT_SHIFT            23u
#define FSL_SCB_ICSR_ISRPREEMPT_WIDTH            1u
#define FSL_SCB_ICSR_ISRPREEMPT(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_ISRPREEMPT_SHIFT))&FSL_SCB_ICSR_ISRPREEMPT_MASK)
#define FSL_SCB_ICSR_PENDSTCLR_MASK              0x2000000u
#define FSL_SCB_ICSR_PENDSTCLR_SHIFT             25u
#define FSL_SCB_ICSR_PENDSTCLR_WIDTH             1u
#define FSL_SCB_ICSR_PENDSTCLR(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_PENDSTCLR_SHIFT))&FSL_SCB_ICSR_PENDSTCLR_MASK)
#define FSL_SCB_ICSR_PENDSTSET_MASK              0x4000000u
#define FSL_SCB_ICSR_PENDSTSET_SHIFT             26u
#define FSL_SCB_ICSR_PENDSTSET_WIDTH             1u
#define FSL_SCB_ICSR_PENDSTSET(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_PENDSTSET_SHIFT))&FSL_SCB_ICSR_PENDSTSET_MASK)
#define FSL_SCB_ICSR_PENDSVCLR_MASK              0x8000000u
#define FSL_SCB_ICSR_PENDSVCLR_SHIFT             27u
#define FSL_SCB_ICSR_PENDSVCLR_WIDTH             1u
#define FSL_SCB_ICSR_PENDSVCLR(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_PENDSVCLR_SHIFT))&FSL_SCB_ICSR_PENDSVCLR_MASK)
#define FSL_SCB_ICSR_PENDSVSET_MASK              0x10000000u
#define FSL_SCB_ICSR_PENDSVSET_SHIFT             28u
#define FSL_SCB_ICSR_PENDSVSET_WIDTH             1u
#define FSL_SCB_ICSR_PENDSVSET(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_PENDSVSET_SHIFT))&FSL_SCB_ICSR_PENDSVSET_MASK)
#define FSL_SCB_ICSR_NMIPENDSET_MASK             0x80000000u
#define FSL_SCB_ICSR_NMIPENDSET_SHIFT            31u
#define FSL_SCB_ICSR_NMIPENDSET_WIDTH            1u
#define FSL_SCB_ICSR_NMIPENDSET(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_ICSR_NMIPENDSET_SHIFT))&FSL_SCB_ICSR_NMIPENDSET_MASK)
/* VTOR Bit Fields */
#define FSL_SCB_VTOR_TBLOFF_MASK                 0xFFFFFF80u
#define FSL_SCB_VTOR_TBLOFF_SHIFT                7u
#define FSL_SCB_VTOR_TBLOFF_WIDTH                25u
#define FSL_SCB_VTOR_TBLOFF(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_VTOR_TBLOFF_SHIFT))&FSL_SCB_VTOR_TBLOFF_MASK)
/* AIRCR Bit Fields */
#define FSL_SCB_AIRCR_VECTRESET_MASK             0x1u
#define FSL_SCB_AIRCR_VECTRESET_SHIFT            0u
#define FSL_SCB_AIRCR_VECTRESET_WIDTH            1u
#define FSL_SCB_AIRCR_VECTRESET(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_VECTRESET_SHIFT))&FSL_SCB_AIRCR_VECTRESET_MASK)
#define FSL_SCB_AIRCR_VECTCLRACTIVE_MASK         0x2u
#define FSL_SCB_AIRCR_VECTCLRACTIVE_SHIFT        1u
#define FSL_SCB_AIRCR_VECTCLRACTIVE_WIDTH        1u
#define FSL_SCB_AIRCR_VECTCLRACTIVE(x)           (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_VECTCLRACTIVE_SHIFT))&FSL_SCB_AIRCR_VECTCLRACTIVE_MASK)
#define FSL_SCB_AIRCR_SYSRESETREQ_MASK           0x4u
#define FSL_SCB_AIRCR_SYSRESETREQ_SHIFT          2u
#define FSL_SCB_AIRCR_SYSRESETREQ_WIDTH          1u
#define FSL_SCB_AIRCR_SYSRESETREQ(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_SYSRESETREQ_SHIFT))&FSL_SCB_AIRCR_SYSRESETREQ_MASK)
#define FSL_SCB_AIRCR_PRIGROUP_MASK              0x700u
#define FSL_SCB_AIRCR_PRIGROUP_SHIFT             8u
#define FSL_SCB_AIRCR_PRIGROUP_WIDTH             3u
#define FSL_SCB_AIRCR_PRIGROUP(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_PRIGROUP_SHIFT))&FSL_SCB_AIRCR_PRIGROUP_MASK)
#define FSL_SCB_AIRCR_ENDIANNESS_MASK            0x8000u
#define FSL_SCB_AIRCR_ENDIANNESS_SHIFT           15u
#define FSL_SCB_AIRCR_ENDIANNESS_WIDTH           1u
#define FSL_SCB_AIRCR_ENDIANNESS(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_ENDIANNESS_SHIFT))&FSL_SCB_AIRCR_ENDIANNESS_MASK)
#define FSL_SCB_AIRCR_VECTKEY_MASK               0xFFFF0000u
#define FSL_SCB_AIRCR_VECTKEY_SHIFT              16u
#define FSL_SCB_AIRCR_VECTKEY_WIDTH              16u
#define FSL_SCB_AIRCR_VECTKEY(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AIRCR_VECTKEY_SHIFT))&FSL_SCB_AIRCR_VECTKEY_MASK)
/* SCR Bit Fields */
#define FSL_SCB_SCR_SLEEPONEXIT_MASK             0x2u
#define FSL_SCB_SCR_SLEEPONEXIT_SHIFT            1u
#define FSL_SCB_SCR_SLEEPONEXIT_WIDTH            1u
#define FSL_SCB_SCR_SLEEPONEXIT(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SCR_SLEEPONEXIT_SHIFT))&FSL_SCB_SCR_SLEEPONEXIT_MASK)
#define FSL_SCB_SCR_SLEEPDEEP_MASK               0x4u
#define FSL_SCB_SCR_SLEEPDEEP_SHIFT              2u
#define FSL_SCB_SCR_SLEEPDEEP_WIDTH              1u
#define FSL_SCB_SCR_SLEEPDEEP(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SCR_SLEEPDEEP_SHIFT))&FSL_SCB_SCR_SLEEPDEEP_MASK)
#define FSL_SCB_SCR_SEVONPEND_MASK               0x10u
#define FSL_SCB_SCR_SEVONPEND_SHIFT              4u
#define FSL_SCB_SCR_SEVONPEND_WIDTH              1u
#define FSL_SCB_SCR_SEVONPEND(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SCR_SEVONPEND_SHIFT))&FSL_SCB_SCR_SEVONPEND_MASK)
/* CCR Bit Fields */
#define FSL_SCB_CCR_NONBASETHRDENA_MASK          0x1u
#define FSL_SCB_CCR_NONBASETHRDENA_SHIFT         0u
#define FSL_SCB_CCR_NONBASETHRDENA_WIDTH         1u
#define FSL_SCB_CCR_NONBASETHRDENA(x)            (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_NONBASETHRDENA_SHIFT))&FSL_SCB_CCR_NONBASETHRDENA_MASK)
#define FSL_SCB_CCR_USERSETMPEND_MASK            0x2u
#define FSL_SCB_CCR_USERSETMPEND_SHIFT           1u
#define FSL_SCB_CCR_USERSETMPEND_WIDTH           1u
#define FSL_SCB_CCR_USERSETMPEND(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_USERSETMPEND_SHIFT))&FSL_SCB_CCR_USERSETMPEND_MASK)
#define FSL_SCB_CCR_UNALIGN_TRP_MASK             0x8u
#define FSL_SCB_CCR_UNALIGN_TRP_SHIFT            3u
#define FSL_SCB_CCR_UNALIGN_TRP_WIDTH            1u
#define FSL_SCB_CCR_UNALIGN_TRP(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_UNALIGN_TRP_SHIFT))&FSL_SCB_CCR_UNALIGN_TRP_MASK)
#define FSL_SCB_CCR_DIV_0_TRP_MASK               0x10u
#define FSL_SCB_CCR_DIV_0_TRP_SHIFT              4u
#define FSL_SCB_CCR_DIV_0_TRP_WIDTH              1u
#define FSL_SCB_CCR_DIV_0_TRP(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_DIV_0_TRP_SHIFT))&FSL_SCB_CCR_DIV_0_TRP_MASK)
#define FSL_SCB_CCR_BFHFNMIGN_MASK               0x100u
#define FSL_SCB_CCR_BFHFNMIGN_SHIFT              8u
#define FSL_SCB_CCR_BFHFNMIGN_WIDTH              1u
#define FSL_SCB_CCR_BFHFNMIGN(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_BFHFNMIGN_SHIFT))&FSL_SCB_CCR_BFHFNMIGN_MASK)
#define FSL_SCB_CCR_STKALIGN_MASK                0x200u
#define FSL_SCB_CCR_STKALIGN_SHIFT               9u
#define FSL_SCB_CCR_STKALIGN_WIDTH               1u
#define FSL_SCB_CCR_STKALIGN(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CCR_STKALIGN_SHIFT))&FSL_SCB_CCR_STKALIGN_MASK)
/* SHPR1 Bit Fields */
#define FSL_SCB_SHPR1_PRI_4_MASK                 0xFFu
#define FSL_SCB_SHPR1_PRI_4_SHIFT                0u
#define FSL_SCB_SHPR1_PRI_4_WIDTH                8u
#define FSL_SCB_SHPR1_PRI_4(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR1_PRI_4_SHIFT))&FSL_SCB_SHPR1_PRI_4_MASK)
#define FSL_SCB_SHPR1_PRI_5_MASK                 0xFF00u
#define FSL_SCB_SHPR1_PRI_5_SHIFT                8u
#define FSL_SCB_SHPR1_PRI_5_WIDTH                8u
#define FSL_SCB_SHPR1_PRI_5(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR1_PRI_5_SHIFT))&FSL_SCB_SHPR1_PRI_5_MASK)
#define FSL_SCB_SHPR1_PRI_6_MASK                 0xFF0000u
#define FSL_SCB_SHPR1_PRI_6_SHIFT                16u
#define FSL_SCB_SHPR1_PRI_6_WIDTH                8u
#define FSL_SCB_SHPR1_PRI_6(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR1_PRI_6_SHIFT))&FSL_SCB_SHPR1_PRI_6_MASK)
/* SHPR2 Bit Fields */
#define FSL_SCB_SHPR2_PRI_11_MASK                0xFF000000u
#define FSL_SCB_SHPR2_PRI_11_SHIFT               24u
#define FSL_SCB_SHPR2_PRI_11_WIDTH               8u
#define FSL_SCB_SHPR2_PRI_11(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR2_PRI_11_SHIFT))&FSL_SCB_SHPR2_PRI_11_MASK)
/* SHPR3 Bit Fields */
#define FSL_SCB_SHPR3_PRI_14_MASK                0xFF0000u
#define FSL_SCB_SHPR3_PRI_14_SHIFT               16u
#define FSL_SCB_SHPR3_PRI_14_WIDTH               8u
#define FSL_SCB_SHPR3_PRI_14(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR3_PRI_14_SHIFT))&FSL_SCB_SHPR3_PRI_14_MASK)
#define FSL_SCB_SHPR3_PRI_15_MASK                0xFF000000u
#define FSL_SCB_SHPR3_PRI_15_SHIFT               24u
#define FSL_SCB_SHPR3_PRI_15_WIDTH               8u
#define FSL_SCB_SHPR3_PRI_15(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHPR3_PRI_15_SHIFT))&FSL_SCB_SHPR3_PRI_15_MASK)
/* SHCSR Bit Fields */
#define FSL_SCB_SHCSR_MEMFAULTACT_MASK           0x1u
#define FSL_SCB_SHCSR_MEMFAULTACT_SHIFT          0u
#define FSL_SCB_SHCSR_MEMFAULTACT_WIDTH          1u
#define FSL_SCB_SHCSR_MEMFAULTACT(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_MEMFAULTACT_SHIFT))&FSL_SCB_SHCSR_MEMFAULTACT_MASK)
#define FSL_SCB_SHCSR_BUSFAULTACT_MASK           0x2u
#define FSL_SCB_SHCSR_BUSFAULTACT_SHIFT          1u
#define FSL_SCB_SHCSR_BUSFAULTACT_WIDTH          1u
#define FSL_SCB_SHCSR_BUSFAULTACT(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_BUSFAULTACT_SHIFT))&FSL_SCB_SHCSR_BUSFAULTACT_MASK)
#define FSL_SCB_SHCSR_USGFAULTACT_MASK           0x8u
#define FSL_SCB_SHCSR_USGFAULTACT_SHIFT          3u
#define FSL_SCB_SHCSR_USGFAULTACT_WIDTH          1u
#define FSL_SCB_SHCSR_USGFAULTACT(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_USGFAULTACT_SHIFT))&FSL_SCB_SHCSR_USGFAULTACT_MASK)
#define FSL_SCB_SHCSR_SVCALLACT_MASK             0x80u
#define FSL_SCB_SHCSR_SVCALLACT_SHIFT            7u
#define FSL_SCB_SHCSR_SVCALLACT_WIDTH            1u
#define FSL_SCB_SHCSR_SVCALLACT(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_SVCALLACT_SHIFT))&FSL_SCB_SHCSR_SVCALLACT_MASK)
#define FSL_SCB_SHCSR_MONITORACT_MASK            0x100u
#define FSL_SCB_SHCSR_MONITORACT_SHIFT           8u
#define FSL_SCB_SHCSR_MONITORACT_WIDTH           1u
#define FSL_SCB_SHCSR_MONITORACT(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_MONITORACT_SHIFT))&FSL_SCB_SHCSR_MONITORACT_MASK)
#define FSL_SCB_SHCSR_PENDSVACT_MASK             0x400u
#define FSL_SCB_SHCSR_PENDSVACT_SHIFT            10u
#define FSL_SCB_SHCSR_PENDSVACT_WIDTH            1u
#define FSL_SCB_SHCSR_PENDSVACT(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_PENDSVACT_SHIFT))&FSL_SCB_SHCSR_PENDSVACT_MASK)
#define FSL_SCB_SHCSR_SYSTICKACT_MASK            0x800u
#define FSL_SCB_SHCSR_SYSTICKACT_SHIFT           11u
#define FSL_SCB_SHCSR_SYSTICKACT_WIDTH           1u
#define FSL_SCB_SHCSR_SYSTICKACT(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_SYSTICKACT_SHIFT))&FSL_SCB_SHCSR_SYSTICKACT_MASK)
#define FSL_SCB_SHCSR_USGFAULTPENDED_MASK        0x1000u
#define FSL_SCB_SHCSR_USGFAULTPENDED_SHIFT       12u
#define FSL_SCB_SHCSR_USGFAULTPENDED_WIDTH       1u
#define FSL_SCB_SHCSR_USGFAULTPENDED(x)          (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_USGFAULTPENDED_SHIFT))&FSL_SCB_SHCSR_USGFAULTPENDED_MASK)
#define FSL_SCB_SHCSR_MEMFAULTPENDED_MASK        0x2000u
#define FSL_SCB_SHCSR_MEMFAULTPENDED_SHIFT       13u
#define FSL_SCB_SHCSR_MEMFAULTPENDED_WIDTH       1u
#define FSL_SCB_SHCSR_MEMFAULTPENDED(x)          (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_MEMFAULTPENDED_SHIFT))&FSL_SCB_SHCSR_MEMFAULTPENDED_MASK)
#define FSL_SCB_SHCSR_BUSFAULTPENDED_MASK        0x4000u
#define FSL_SCB_SHCSR_BUSFAULTPENDED_SHIFT       14u
#define FSL_SCB_SHCSR_BUSFAULTPENDED_WIDTH       1u
#define FSL_SCB_SHCSR_BUSFAULTPENDED(x)          (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_BUSFAULTPENDED_SHIFT))&FSL_SCB_SHCSR_BUSFAULTPENDED_MASK)
#define FSL_SCB_SHCSR_SVCALLPENDED_MASK          0x8000u
#define FSL_SCB_SHCSR_SVCALLPENDED_SHIFT         15u
#define FSL_SCB_SHCSR_SVCALLPENDED_WIDTH         1u
#define FSL_SCB_SHCSR_SVCALLPENDED(x)            (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_SVCALLPENDED_SHIFT))&FSL_SCB_SHCSR_SVCALLPENDED_MASK)
#define FSL_SCB_SHCSR_MEMFAULTENA_MASK           0x10000u
#define FSL_SCB_SHCSR_MEMFAULTENA_SHIFT          16u
#define FSL_SCB_SHCSR_MEMFAULTENA_WIDTH          1u
#define FSL_SCB_SHCSR_MEMFAULTENA(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_MEMFAULTENA_SHIFT))&FSL_SCB_SHCSR_MEMFAULTENA_MASK)
#define FSL_SCB_SHCSR_BUSFAULTENA_MASK           0x20000u
#define FSL_SCB_SHCSR_BUSFAULTENA_SHIFT          17u
#define FSL_SCB_SHCSR_BUSFAULTENA_WIDTH          1u
#define FSL_SCB_SHCSR_BUSFAULTENA(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_BUSFAULTENA_SHIFT))&FSL_SCB_SHCSR_BUSFAULTENA_MASK)
#define FSL_SCB_SHCSR_USGFAULTENA_MASK           0x40000u
#define FSL_SCB_SHCSR_USGFAULTENA_SHIFT          18u
#define FSL_SCB_SHCSR_USGFAULTENA_WIDTH          1u
#define FSL_SCB_SHCSR_USGFAULTENA(x)             (((uint32_t)(((uint32_t)(x))<<FSL_SCB_SHCSR_USGFAULTENA_SHIFT))&FSL_SCB_SHCSR_USGFAULTENA_MASK)
/* CFSR Bit Fields */
#define FSL_SCB_CFSR_IACCVIOL_MASK               0x1u
#define FSL_SCB_CFSR_IACCVIOL_SHIFT              0u
#define FSL_SCB_CFSR_IACCVIOL_WIDTH              1u
#define FSL_SCB_CFSR_IACCVIOL(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_IACCVIOL_SHIFT))&FSL_SCB_CFSR_IACCVIOL_MASK)
#define FSL_SCB_CFSR_DACCVIOL_MASK               0x2u
#define FSL_SCB_CFSR_DACCVIOL_SHIFT              1u
#define FSL_SCB_CFSR_DACCVIOL_WIDTH              1u
#define FSL_SCB_CFSR_DACCVIOL(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_DACCVIOL_SHIFT))&FSL_SCB_CFSR_DACCVIOL_MASK)
#define FSL_SCB_CFSR_MUNSTKERR_MASK              0x8u
#define FSL_SCB_CFSR_MUNSTKERR_SHIFT             3u
#define FSL_SCB_CFSR_MUNSTKERR_WIDTH             1u
#define FSL_SCB_CFSR_MUNSTKERR(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_MUNSTKERR_SHIFT))&FSL_SCB_CFSR_MUNSTKERR_MASK)
#define FSL_SCB_CFSR_MSTKERR_MASK                0x10u
#define FSL_SCB_CFSR_MSTKERR_SHIFT               4u
#define FSL_SCB_CFSR_MSTKERR_WIDTH               1u
#define FSL_SCB_CFSR_MSTKERR(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_MSTKERR_SHIFT))&FSL_SCB_CFSR_MSTKERR_MASK)
#define FSL_SCB_CFSR_MLSPERR_MASK                0x20u
#define FSL_SCB_CFSR_MLSPERR_SHIFT               5u
#define FSL_SCB_CFSR_MLSPERR_WIDTH               1u
#define FSL_SCB_CFSR_MLSPERR(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_MLSPERR_SHIFT))&FSL_SCB_CFSR_MLSPERR_MASK)
#define FSL_SCB_CFSR_MMARVALID_MASK              0x80u
#define FSL_SCB_CFSR_MMARVALID_SHIFT             7u
#define FSL_SCB_CFSR_MMARVALID_WIDTH             1u
#define FSL_SCB_CFSR_MMARVALID(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_MMARVALID_SHIFT))&FSL_SCB_CFSR_MMARVALID_MASK)
#define FSL_SCB_CFSR_IBUSERR_MASK                0x100u
#define FSL_SCB_CFSR_IBUSERR_SHIFT               8u
#define FSL_SCB_CFSR_IBUSERR_WIDTH               1u
#define FSL_SCB_CFSR_IBUSERR(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_IBUSERR_SHIFT))&FSL_SCB_CFSR_IBUSERR_MASK)
#define FSL_SCB_CFSR_PRECISERR_MASK              0x200u
#define FSL_SCB_CFSR_PRECISERR_SHIFT             9u
#define FSL_SCB_CFSR_PRECISERR_WIDTH             1u
#define FSL_SCB_CFSR_PRECISERR(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_PRECISERR_SHIFT))&FSL_SCB_CFSR_PRECISERR_MASK)
#define FSL_SCB_CFSR_IMPRECISERR_MASK            0x400u
#define FSL_SCB_CFSR_IMPRECISERR_SHIFT           10u
#define FSL_SCB_CFSR_IMPRECISERR_WIDTH           1u
#define FSL_SCB_CFSR_IMPRECISERR(x)              (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_IMPRECISERR_SHIFT))&FSL_SCB_CFSR_IMPRECISERR_MASK)
#define FSL_SCB_CFSR_UNSTKERR_MASK               0x800u
#define FSL_SCB_CFSR_UNSTKERR_SHIFT              11u
#define FSL_SCB_CFSR_UNSTKERR_WIDTH              1u
#define FSL_SCB_CFSR_UNSTKERR(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_UNSTKERR_SHIFT))&FSL_SCB_CFSR_UNSTKERR_MASK)
#define FSL_SCB_CFSR_STKERR_MASK                 0x1000u
#define FSL_SCB_CFSR_STKERR_SHIFT                12u
#define FSL_SCB_CFSR_STKERR_WIDTH                1u
#define FSL_SCB_CFSR_STKERR(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_STKERR_SHIFT))&FSL_SCB_CFSR_STKERR_MASK)
#define FSL_SCB_CFSR_LSPERR_MASK                 0x2000u
#define FSL_SCB_CFSR_LSPERR_SHIFT                13u
#define FSL_SCB_CFSR_LSPERR_WIDTH                1u
#define FSL_SCB_CFSR_LSPERR(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_LSPERR_SHIFT))&FSL_SCB_CFSR_LSPERR_MASK)
#define FSL_SCB_CFSR_BFARVALID_MASK              0x8000u
#define FSL_SCB_CFSR_BFARVALID_SHIFT             15u
#define FSL_SCB_CFSR_BFARVALID_WIDTH             1u
#define FSL_SCB_CFSR_BFARVALID(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_BFARVALID_SHIFT))&FSL_SCB_CFSR_BFARVALID_MASK)
#define FSL_SCB_CFSR_UNDEFINSTR_MASK             0x10000u
#define FSL_SCB_CFSR_UNDEFINSTR_SHIFT            16u
#define FSL_SCB_CFSR_UNDEFINSTR_WIDTH            1u
#define FSL_SCB_CFSR_UNDEFINSTR(x)               (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_UNDEFINSTR_SHIFT))&FSL_SCB_CFSR_UNDEFINSTR_MASK)
#define FSL_SCB_CFSR_INVSTATE_MASK               0x20000u
#define FSL_SCB_CFSR_INVSTATE_SHIFT              17u
#define FSL_SCB_CFSR_INVSTATE_WIDTH              1u
#define FSL_SCB_CFSR_INVSTATE(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_INVSTATE_SHIFT))&FSL_SCB_CFSR_INVSTATE_MASK)
#define FSL_SCB_CFSR_INVPC_MASK                  0x40000u
#define FSL_SCB_CFSR_INVPC_SHIFT                 18u
#define FSL_SCB_CFSR_INVPC_WIDTH                 1u
#define FSL_SCB_CFSR_INVPC(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_INVPC_SHIFT))&FSL_SCB_CFSR_INVPC_MASK)
#define FSL_SCB_CFSR_NOCP_MASK                   0x80000u
#define FSL_SCB_CFSR_NOCP_SHIFT                  19u
#define FSL_SCB_CFSR_NOCP_WIDTH                  1u
#define FSL_SCB_CFSR_NOCP(x)                     (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_NOCP_SHIFT))&FSL_SCB_CFSR_NOCP_MASK)
#define FSL_SCB_CFSR_UNALIGNED_MASK              0x1000000u
#define FSL_SCB_CFSR_UNALIGNED_SHIFT             24u
#define FSL_SCB_CFSR_UNALIGNED_WIDTH             1u
#define FSL_SCB_CFSR_UNALIGNED(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_UNALIGNED_SHIFT))&FSL_SCB_CFSR_UNALIGNED_MASK)
#define FSL_SCB_CFSR_DIVBYZERO_MASK              0x2000000u
#define FSL_SCB_CFSR_DIVBYZERO_SHIFT             25u
#define FSL_SCB_CFSR_DIVBYZERO_WIDTH             1u
#define FSL_SCB_CFSR_DIVBYZERO(x)                (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CFSR_DIVBYZERO_SHIFT))&FSL_SCB_CFSR_DIVBYZERO_MASK)
/* HFSR Bit Fields */
#define FSL_SCB_HFSR_VECTTBL_MASK                0x2u
#define FSL_SCB_HFSR_VECTTBL_SHIFT               1u
#define FSL_SCB_HFSR_VECTTBL_WIDTH               1u
#define FSL_SCB_HFSR_VECTTBL(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_HFSR_VECTTBL_SHIFT))&FSL_SCB_HFSR_VECTTBL_MASK)
#define FSL_SCB_HFSR_FORCED_MASK                 0x40000000u
#define FSL_SCB_HFSR_FORCED_SHIFT                30u
#define FSL_SCB_HFSR_FORCED_WIDTH                1u
#define FSL_SCB_HFSR_FORCED(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_HFSR_FORCED_SHIFT))&FSL_SCB_HFSR_FORCED_MASK)
#define FSL_SCB_HFSR_DEBUGEVT_MASK               0x80000000u
#define FSL_SCB_HFSR_DEBUGEVT_SHIFT              31u
#define FSL_SCB_HFSR_DEBUGEVT_WIDTH              1u
#define FSL_SCB_HFSR_DEBUGEVT(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_HFSR_DEBUGEVT_SHIFT))&FSL_SCB_HFSR_DEBUGEVT_MASK)
/* DFSR Bit Fields */
#define FSL_SCB_DFSR_HALTED_MASK                 0x1u
#define FSL_SCB_DFSR_HALTED_SHIFT                0u
#define FSL_SCB_DFSR_HALTED_WIDTH                1u
#define FSL_SCB_DFSR_HALTED(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_HALTED_SHIFT))&FSL_SCB_DFSR_HALTED_MASK)
#define FSL_SCB_DFSR_BKPT_MASK                   0x2u
#define FSL_SCB_DFSR_BKPT_SHIFT                  1u
#define FSL_SCB_DFSR_BKPT_WIDTH                  1u
#define FSL_SCB_DFSR_BKPT(x)                     (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_BKPT_SHIFT))&FSL_SCB_DFSR_BKPT_MASK)
#define FSL_SCB_DFSR_DWTTRAP_MASK                0x4u
#define FSL_SCB_DFSR_DWTTRAP_SHIFT               2u
#define FSL_SCB_DFSR_DWTTRAP_WIDTH               1u
#define FSL_SCB_DFSR_DWTTRAP(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_DWTTRAP_SHIFT))&FSL_SCB_DFSR_DWTTRAP_MASK)
#define FSL_SCB_DFSR_VCATCH_MASK                 0x8u
#define FSL_SCB_DFSR_VCATCH_SHIFT                3u
#define FSL_SCB_DFSR_VCATCH_WIDTH                1u
#define FSL_SCB_DFSR_VCATCH(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_VCATCH_SHIFT))&FSL_SCB_DFSR_VCATCH_MASK)
#define FSL_SCB_DFSR_EXTERNAL_MASK               0x10u
#define FSL_SCB_DFSR_EXTERNAL_SHIFT              4u
#define FSL_SCB_DFSR_EXTERNAL_WIDTH              1u
#define FSL_SCB_DFSR_EXTERNAL(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_DFSR_EXTERNAL_SHIFT))&FSL_SCB_DFSR_EXTERNAL_MASK)
/* MMFAR Bit Fields */
#define FSL_SCB_MMFAR_ADDRESS_MASK               0xFFFFFFFFu
#define FSL_SCB_MMFAR_ADDRESS_SHIFT              0u
#define FSL_SCB_MMFAR_ADDRESS_WIDTH              32u
#define FSL_SCB_MMFAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_MMFAR_ADDRESS_SHIFT))&FSL_SCB_MMFAR_ADDRESS_MASK)
/* BFAR Bit Fields */
#define FSL_SCB_BFAR_ADDRESS_MASK                0xFFFFFFFFu
#define FSL_SCB_BFAR_ADDRESS_SHIFT               0u
#define FSL_SCB_BFAR_ADDRESS_WIDTH               32u
#define FSL_SCB_BFAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_BFAR_ADDRESS_SHIFT))&FSL_SCB_BFAR_ADDRESS_MASK)
/* AFSR Bit Fields */
#define FSL_SCB_AFSR_AUXFAULT_MASK               0xFFFFFFFFu
#define FSL_SCB_AFSR_AUXFAULT_SHIFT              0u
#define FSL_SCB_AFSR_AUXFAULT_WIDTH              32u
#define FSL_SCB_AFSR_AUXFAULT(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_AFSR_AUXFAULT_SHIFT))&FSL_SCB_AFSR_AUXFAULT_MASK)
/* CPACR Bit Fields */
#define FSL_SCB_CPACR_CP10_MASK                  0x300000u
#define FSL_SCB_CPACR_CP10_SHIFT                 20u
#define FSL_SCB_CPACR_CP10_WIDTH                 2u
#define FSL_SCB_CPACR_CP10(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPACR_CP10_SHIFT))&FSL_SCB_CPACR_CP10_MASK)
#define FSL_SCB_CPACR_CP11_MASK                  0xC00000u
#define FSL_SCB_CPACR_CP11_SHIFT                 22u
#define FSL_SCB_CPACR_CP11_WIDTH                 2u
#define FSL_SCB_CPACR_CP11(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_CPACR_CP11_SHIFT))&FSL_SCB_CPACR_CP11_MASK)
/* FPCCR Bit Fields */
#define FSL_SCB_FPCCR_LSPACT_MASK                0x1u
#define FSL_SCB_FPCCR_LSPACT_SHIFT               0u
#define FSL_SCB_FPCCR_LSPACT_WIDTH               1u
#define FSL_SCB_FPCCR_LSPACT(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_LSPACT_SHIFT))&FSL_SCB_FPCCR_LSPACT_MASK)
#define FSL_SCB_FPCCR_USER_MASK                  0x2u
#define FSL_SCB_FPCCR_USER_SHIFT                 1u
#define FSL_SCB_FPCCR_USER_WIDTH                 1u
#define FSL_SCB_FPCCR_USER(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_USER_SHIFT))&FSL_SCB_FPCCR_USER_MASK)
#define FSL_SCB_FPCCR_THREAD_MASK                0x8u
#define FSL_SCB_FPCCR_THREAD_SHIFT               3u
#define FSL_SCB_FPCCR_THREAD_WIDTH               1u
#define FSL_SCB_FPCCR_THREAD(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_THREAD_SHIFT))&FSL_SCB_FPCCR_THREAD_MASK)
#define FSL_SCB_FPCCR_HFRDY_MASK                 0x10u
#define FSL_SCB_FPCCR_HFRDY_SHIFT                4u
#define FSL_SCB_FPCCR_HFRDY_WIDTH                1u
#define FSL_SCB_FPCCR_HFRDY(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_HFRDY_SHIFT))&FSL_SCB_FPCCR_HFRDY_MASK)
#define FSL_SCB_FPCCR_MMRDY_MASK                 0x20u
#define FSL_SCB_FPCCR_MMRDY_SHIFT                5u
#define FSL_SCB_FPCCR_MMRDY_WIDTH                1u
#define FSL_SCB_FPCCR_MMRDY(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_MMRDY_SHIFT))&FSL_SCB_FPCCR_MMRDY_MASK)
#define FSL_SCB_FPCCR_BFRDY_MASK                 0x40u
#define FSL_SCB_FPCCR_BFRDY_SHIFT                6u
#define FSL_SCB_FPCCR_BFRDY_WIDTH                1u
#define FSL_SCB_FPCCR_BFRDY(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_BFRDY_SHIFT))&FSL_SCB_FPCCR_BFRDY_MASK)
#define FSL_SCB_FPCCR_MONRDY_MASK                0x100u
#define FSL_SCB_FPCCR_MONRDY_SHIFT               8u
#define FSL_SCB_FPCCR_MONRDY_WIDTH               1u
#define FSL_SCB_FPCCR_MONRDY(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_MONRDY_SHIFT))&FSL_SCB_FPCCR_MONRDY_MASK)
#define FSL_SCB_FPCCR_LSPEN_MASK                 0x40000000u
#define FSL_SCB_FPCCR_LSPEN_SHIFT                30u
#define FSL_SCB_FPCCR_LSPEN_WIDTH                1u
#define FSL_SCB_FPCCR_LSPEN(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_LSPEN_SHIFT))&FSL_SCB_FPCCR_LSPEN_MASK)
#define FSL_SCB_FPCCR_ASPEN_MASK                 0x80000000u
#define FSL_SCB_FPCCR_ASPEN_SHIFT                31u
#define FSL_SCB_FPCCR_ASPEN_WIDTH                1u
#define FSL_SCB_FPCCR_ASPEN(x)                   (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCCR_ASPEN_SHIFT))&FSL_SCB_FPCCR_ASPEN_MASK)
/* FPCAR Bit Fields */
#define FSL_SCB_FPCAR_ADDRESS_MASK               0xFFFFFFF8u
#define FSL_SCB_FPCAR_ADDRESS_SHIFT              3u
#define FSL_SCB_FPCAR_ADDRESS_WIDTH              29u
#define FSL_SCB_FPCAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPCAR_ADDRESS_SHIFT))&FSL_SCB_FPCAR_ADDRESS_MASK)
/* FPDSCR Bit Fields */
#define FSL_SCB_FPDSCR_RMode_MASK                0xC00000u
#define FSL_SCB_FPDSCR_RMode_SHIFT               22u
#define FSL_SCB_FPDSCR_RMode_WIDTH               2u
#define FSL_SCB_FPDSCR_RMode(x)                  (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPDSCR_RMode_SHIFT))&FSL_SCB_FPDSCR_RMode_MASK)
#define FSL_SCB_FPDSCR_FZ_MASK                   0x1000000u
#define FSL_SCB_FPDSCR_FZ_SHIFT                  24u
#define FSL_SCB_FPDSCR_FZ_WIDTH                  1u
#define FSL_SCB_FPDSCR_FZ(x)                     (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPDSCR_FZ_SHIFT))&FSL_SCB_FPDSCR_FZ_MASK)
#define FSL_SCB_FPDSCR_DN_MASK                   0x2000000u
#define FSL_SCB_FPDSCR_DN_SHIFT                  25u
#define FSL_SCB_FPDSCR_DN_WIDTH                  1u
#define FSL_SCB_FPDSCR_DN(x)                     (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPDSCR_DN_SHIFT))&FSL_SCB_FPDSCR_DN_MASK)
#define FSL_SCB_FPDSCR_AHP_MASK                  0x4000000u
#define FSL_SCB_FPDSCR_AHP_SHIFT                 26u
#define FSL_SCB_FPDSCR_AHP_WIDTH                 1u
#define FSL_SCB_FPDSCR_AHP(x)                    (((uint32_t)(((uint32_t)(x))<<FSL_SCB_FPDSCR_AHP_SHIFT))&FSL_SCB_FPDSCR_AHP_MASK)

/*!
 * @}
 */ /* end of group FSL_SCB_Register_Masks */


/*!
 * @}
 */ /* end of group FSL_SCB_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- FTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Peripheral_Access_Layer FTM Peripheral Access Layer
 * @{
 */


/** FTM - Size of Registers Arrays */
#define FTM_CnSC_COUNT                           8u
#define FTM_CnV_COUNT                            8u

/** FTM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< Status And Control, offset: 0x0 */
  __IO uint32_t CNT;                               /**< Counter, offset: 0x4 */
  __IO uint32_t MOD;                               /**< Modulo, offset: 0x8 */
  struct {                                         /* offset: 0xC, array step: 0x8 */
    __IO uint32_t CnSC;                              /**< Channel (n) Status And Control, array offset: 0xC, array step: 0x8 */
    __IO uint32_t CnV;                               /**< Channel (n) Value, array offset: 0x10, array step: 0x8 */
  } CONTROLS[8];
  __IO uint32_t CNTIN;                             /**< Counter Initial Value, offset: 0x4C */
  __IO uint32_t STATUS;                            /**< Capture And Compare Status, offset: 0x50 */
  __IO uint32_t MODE;                              /**< Features Mode Selection, offset: 0x54 */
  __IO uint32_t SYNC;                              /**< Synchronization, offset: 0x58 */
  __IO uint32_t OUTINIT;                           /**< Initial State For Channels Output, offset: 0x5C */
  __IO uint32_t OUTMASK;                           /**< Output Mask, offset: 0x60 */
  __IO uint32_t COMBINE;                           /**< Function For Linked Channels, offset: 0x64 */
  __IO uint32_t DEADTIME;                          /**< Deadtime Insertion Control, offset: 0x68 */
  __IO uint32_t EXTTRIG;                           /**< FTM External Trigger, offset: 0x6C */
  __IO uint32_t POL;                               /**< Channels Polarity, offset: 0x70 */
  __IO uint32_t FMS;                               /**< Fault Mode Status, offset: 0x74 */
  __IO uint32_t FILTER;                            /**< Input Capture Filter Control, offset: 0x78 */
  __IO uint32_t FLTCTRL;                           /**< Fault Control, offset: 0x7C */
  __IO uint32_t QDCTRL;                            /**< Quadrature Decoder Control And Status, offset: 0x80 */
  __IO uint32_t CONF;                              /**< Configuration, offset: 0x84 */
  __IO uint32_t FLTPOL;                            /**< FTM Fault Input Polarity, offset: 0x88 */
  __IO uint32_t SYNCONF;                           /**< Synchronization Configuration, offset: 0x8C */
  __IO uint32_t INVCTRL;                           /**< FTM Inverting Control, offset: 0x90 */
  __IO uint32_t SWOCTRL;                           /**< FTM Software Output Control, offset: 0x94 */
  __IO uint32_t PWMLOAD;                           /**< FTM PWM Load, offset: 0x98 */
  __IO uint32_t HCR;                               /**< Half Cycle Register, offset: 0x9C */
} FTM_Type, *FTM_MemMapPtr;

 /** Number of instances of the FTM module. */
#define FTM_INSTANCE_COUNT (4u)


/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base address */
#define FTM0_BASE                                (0x4004F000u)
/** Peripheral FTM0 base pointer */
#define FTM0                                     ((FTM_Type *)FTM0_BASE)
/** Peripheral FTM1 base address */
#define FTM1_BASE                                (0x400B6000u)
/** Peripheral FTM1 base pointer */
#define FTM1                                     ((FTM_Type *)FTM1_BASE)
#define FTM_BASE_ADDRS                           { FTM0_BASE, FTM1_BASE }
/** Array initializer of FTM peripheral base pointers */
#define FTM_BASE_PTRS                            { FTM0, FTM1 }
/** Interrupt vectors for the FTM peripheral type */
#define FTM_IRQS                                 { FTM0_IRQn, FTM1_IRQn }

/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Masks FTM Register Masks
 * @{
 */

/* SC Bit Fields */
#define FTM_SC_PS_MASK                           0x7u
#define FTM_SC_PS_SHIFT                          0u
#define FTM_SC_PS_WIDTH                          3u
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK)
#define FTM_SC_CLKS_MASK                         0x18u
#define FTM_SC_CLKS_SHIFT                        3u
#define FTM_SC_CLKS_WIDTH                        2u
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK)
#define FTM_SC_CPWMS_MASK                        0x20u
#define FTM_SC_CPWMS_SHIFT                       5u
#define FTM_SC_CPWMS_WIDTH                       1u
#define FTM_SC_CPWMS(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_SC_CPWMS_SHIFT))&FTM_SC_CPWMS_MASK)
#define FTM_SC_RIE_MASK                          0x40u
#define FTM_SC_RIE_SHIFT                         6u
#define FTM_SC_RIE_WIDTH                         1u
#define FTM_SC_RIE(x)                            (((uint32_t)(((uint32_t)(x))<<FTM_SC_RIE_SHIFT))&FTM_SC_RIE_MASK)
#define FTM_SC_RF_MASK                           0x80u
#define FTM_SC_RF_SHIFT                          7u
#define FTM_SC_RF_WIDTH                          1u
#define FTM_SC_RF(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_RF_SHIFT))&FTM_SC_RF_MASK)
#define FTM_SC_TOIE_MASK                         0x100u
#define FTM_SC_TOIE_SHIFT                        8u
#define FTM_SC_TOIE_WIDTH                        1u
#define FTM_SC_TOIE(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOIE_SHIFT))&FTM_SC_TOIE_MASK)
#define FTM_SC_TOF_MASK                          0x200u
#define FTM_SC_TOF_SHIFT                         9u
#define FTM_SC_TOF_WIDTH                         1u
#define FTM_SC_TOF(x)                            (((uint32_t)(((uint32_t)(x))<<FTM_SC_TOF_SHIFT))&FTM_SC_TOF_MASK)
#define FTM_SC_PWMEN0_MASK                       0x10000u
#define FTM_SC_PWMEN0_SHIFT                      16u
#define FTM_SC_PWMEN0_WIDTH                      1u
#define FTM_SC_PWMEN0(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_SC_PWMEN0_SHIFT))&FTM_SC_PWMEN0_MASK)
#define FTM_SC_PWMEN1_MASK                       0x20000u
#define FTM_SC_PWMEN1_SHIFT                      17u
#define FTM_SC_PWMEN1_WIDTH                      1u
#define FTM_SC_PWMEN1(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_SC_PWMEN1_SHIFT))&FTM_SC_PWMEN1_MASK)
#define FTM_SC_PWMEN2_MASK                       0x40000u
#define FTM_SC_PWMEN2_SHIFT                      18u
#define FTM_SC_PWMEN2_WIDTH                      1u
#define FTM_SC_PWMEN2(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_SC_PWMEN2_SHIFT))&FTM_SC_PWMEN2_MASK)
#define FTM_SC_PWMEN3_MASK                       0x80000u
#define FTM_SC_PWMEN3_SHIFT                      19u
#define FTM_SC_PWMEN3_WIDTH                      1u
#define FTM_SC_PWMEN3(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_SC_PWMEN3_SHIFT))&FTM_SC_PWMEN3_MASK)
#define FTM_SC_PWMEN4_MASK                       0x100000u
#define FTM_SC_PWMEN4_SHIFT                      20u
#define FTM_SC_PWMEN4_WIDTH                      1u
#define FTM_SC_PWMEN4(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_SC_PWMEN4_SHIFT))&FTM_SC_PWMEN4_MASK)
#define FTM_SC_PWMEN5_MASK                       0x200000u
#define FTM_SC_PWMEN5_SHIFT                      21u
#define FTM_SC_PWMEN5_WIDTH                      1u
#define FTM_SC_PWMEN5(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_SC_PWMEN5_SHIFT))&FTM_SC_PWMEN5_MASK)
#define FTM_SC_PWMEN6_MASK                       0x400000u
#define FTM_SC_PWMEN6_SHIFT                      22u
#define FTM_SC_PWMEN6_WIDTH                      1u
#define FTM_SC_PWMEN6(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_SC_PWMEN6_SHIFT))&FTM_SC_PWMEN6_MASK)
#define FTM_SC_PWMEN7_MASK                       0x800000u
#define FTM_SC_PWMEN7_SHIFT                      23u
#define FTM_SC_PWMEN7_WIDTH                      1u
#define FTM_SC_PWMEN7(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_SC_PWMEN7_SHIFT))&FTM_SC_PWMEN7_MASK)
/* CNT Bit Fields */
#define FTM_CNT_COUNT_MASK                       0xFFFFu
#define FTM_CNT_COUNT_SHIFT                      0u
#define FTM_CNT_COUNT_WIDTH                      16u
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK)
/* MOD Bit Fields */
#define FTM_MOD_MOD_MASK                         0xFFFFu
#define FTM_MOD_MOD_SHIFT                        0u
#define FTM_MOD_MOD_WIDTH                        16u
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK)
/* CnSC Bit Fields */
#define FTM_CnSC_DMA_MASK                        0x1u
#define FTM_CnSC_DMA_SHIFT                       0u
#define FTM_CnSC_DMA_WIDTH                       1u
#define FTM_CnSC_DMA(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_DMA_SHIFT))&FTM_CnSC_DMA_MASK)
#define FTM_CnSC_ICRST_MASK                      0x2u
#define FTM_CnSC_ICRST_SHIFT                     1u
#define FTM_CnSC_ICRST_WIDTH                     1u
#define FTM_CnSC_ICRST(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ICRST_SHIFT))&FTM_CnSC_ICRST_MASK)
#define FTM_CnSC_ELSA_MASK                       0x4u
#define FTM_CnSC_ELSA_SHIFT                      2u
#define FTM_CnSC_ELSA_WIDTH                      1u
#define FTM_CnSC_ELSA(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSA_SHIFT))&FTM_CnSC_ELSA_MASK)
#define FTM_CnSC_ELSB_MASK                       0x8u
#define FTM_CnSC_ELSB_SHIFT                      3u
#define FTM_CnSC_ELSB_WIDTH                      1u
#define FTM_CnSC_ELSB(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_ELSB_SHIFT))&FTM_CnSC_ELSB_MASK)
#define FTM_CnSC_MSA_MASK                        0x10u
#define FTM_CnSC_MSA_SHIFT                       4u
#define FTM_CnSC_MSA_WIDTH                       1u
#define FTM_CnSC_MSA(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSA_SHIFT))&FTM_CnSC_MSA_MASK)
#define FTM_CnSC_MSB_MASK                        0x20u
#define FTM_CnSC_MSB_SHIFT                       5u
#define FTM_CnSC_MSB_WIDTH                       1u
#define FTM_CnSC_MSB(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_MSB_SHIFT))&FTM_CnSC_MSB_MASK)
#define FTM_CnSC_CHIE_MASK                       0x40u
#define FTM_CnSC_CHIE_SHIFT                      6u
#define FTM_CnSC_CHIE_WIDTH                      1u
#define FTM_CnSC_CHIE(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHIE_SHIFT))&FTM_CnSC_CHIE_MASK)
#define FTM_CnSC_CHF_MASK                        0x80u
#define FTM_CnSC_CHF_SHIFT                       7u
#define FTM_CnSC_CHF_WIDTH                       1u
#define FTM_CnSC_CHF(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHF_SHIFT))&FTM_CnSC_CHF_MASK)
#define FTM_CnSC_TRIGMODE_MASK                   0x100u
#define FTM_CnSC_TRIGMODE_SHIFT                  8u
#define FTM_CnSC_TRIGMODE_WIDTH                  1u
#define FTM_CnSC_TRIGMODE(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_TRIGMODE_SHIFT))&FTM_CnSC_TRIGMODE_MASK)
#define FTM_CnSC_CHIS_MASK                       0x200u
#define FTM_CnSC_CHIS_SHIFT                      9u
#define FTM_CnSC_CHIS_WIDTH                      1u
#define FTM_CnSC_CHIS(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CnSC_CHIS_SHIFT))&FTM_CnSC_CHIS_MASK)
/* CnV Bit Fields */
#define FTM_CnV_VAL_MASK                         0xFFFFu
#define FTM_CnV_VAL_SHIFT                        0u
#define FTM_CnV_VAL_WIDTH                        16u
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK)
/* CNTIN Bit Fields */
#define FTM_CNTIN_INIT_MASK                      0xFFFFu
#define FTM_CNTIN_INIT_SHIFT                     0u
#define FTM_CNTIN_INIT_WIDTH                     16u
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK)
/* STATUS Bit Fields */
#define FTM_STATUS_CH0F_MASK                     0x1u
#define FTM_STATUS_CH0F_SHIFT                    0u
#define FTM_STATUS_CH0F_WIDTH                    1u
#define FTM_STATUS_CH0F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH0F_SHIFT))&FTM_STATUS_CH0F_MASK)
#define FTM_STATUS_CH1F_MASK                     0x2u
#define FTM_STATUS_CH1F_SHIFT                    1u
#define FTM_STATUS_CH1F_WIDTH                    1u
#define FTM_STATUS_CH1F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH1F_SHIFT))&FTM_STATUS_CH1F_MASK)
#define FTM_STATUS_CH2F_MASK                     0x4u
#define FTM_STATUS_CH2F_SHIFT                    2u
#define FTM_STATUS_CH2F_WIDTH                    1u
#define FTM_STATUS_CH2F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH2F_SHIFT))&FTM_STATUS_CH2F_MASK)
#define FTM_STATUS_CH3F_MASK                     0x8u
#define FTM_STATUS_CH3F_SHIFT                    3u
#define FTM_STATUS_CH3F_WIDTH                    1u
#define FTM_STATUS_CH3F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH3F_SHIFT))&FTM_STATUS_CH3F_MASK)
#define FTM_STATUS_CH4F_MASK                     0x10u
#define FTM_STATUS_CH4F_SHIFT                    4u
#define FTM_STATUS_CH4F_WIDTH                    1u
#define FTM_STATUS_CH4F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH4F_SHIFT))&FTM_STATUS_CH4F_MASK)
#define FTM_STATUS_CH5F_MASK                     0x20u
#define FTM_STATUS_CH5F_SHIFT                    5u
#define FTM_STATUS_CH5F_WIDTH                    1u
#define FTM_STATUS_CH5F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH5F_SHIFT))&FTM_STATUS_CH5F_MASK)
#define FTM_STATUS_CH6F_MASK                     0x40u
#define FTM_STATUS_CH6F_SHIFT                    6u
#define FTM_STATUS_CH6F_WIDTH                    1u
#define FTM_STATUS_CH6F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH6F_SHIFT))&FTM_STATUS_CH6F_MASK)
#define FTM_STATUS_CH7F_MASK                     0x80u
#define FTM_STATUS_CH7F_SHIFT                    7u
#define FTM_STATUS_CH7F_WIDTH                    1u
#define FTM_STATUS_CH7F(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_STATUS_CH7F_SHIFT))&FTM_STATUS_CH7F_MASK)
/* MODE Bit Fields */
#define FTM_MODE_FTMEN_MASK                      0x1u
#define FTM_MODE_FTMEN_SHIFT                     0u
#define FTM_MODE_FTMEN_WIDTH                     1u
#define FTM_MODE_FTMEN(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FTMEN_SHIFT))&FTM_MODE_FTMEN_MASK)
#define FTM_MODE_INIT_MASK                       0x2u
#define FTM_MODE_INIT_SHIFT                      1u
#define FTM_MODE_INIT_WIDTH                      1u
#define FTM_MODE_INIT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_MODE_INIT_SHIFT))&FTM_MODE_INIT_MASK)
#define FTM_MODE_WPDIS_MASK                      0x4u
#define FTM_MODE_WPDIS_SHIFT                     2u
#define FTM_MODE_WPDIS_WIDTH                     1u
#define FTM_MODE_WPDIS(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_MODE_WPDIS_SHIFT))&FTM_MODE_WPDIS_MASK)
#define FTM_MODE_PWMSYNC_MASK                    0x8u
#define FTM_MODE_PWMSYNC_SHIFT                   3u
#define FTM_MODE_PWMSYNC_WIDTH                   1u
#define FTM_MODE_PWMSYNC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_PWMSYNC_SHIFT))&FTM_MODE_PWMSYNC_MASK)
#define FTM_MODE_CAPTEST_MASK                    0x10u
#define FTM_MODE_CAPTEST_SHIFT                   4u
#define FTM_MODE_CAPTEST_WIDTH                   1u
#define FTM_MODE_CAPTEST(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_CAPTEST_SHIFT))&FTM_MODE_CAPTEST_MASK)
#define FTM_MODE_FAULTM_MASK                     0x60u
#define FTM_MODE_FAULTM_SHIFT                    5u
#define FTM_MODE_FAULTM_WIDTH                    2u
#define FTM_MODE_FAULTM(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK)
#define FTM_MODE_FAULTIE_MASK                    0x80u
#define FTM_MODE_FAULTIE_SHIFT                   7u
#define FTM_MODE_FAULTIE_WIDTH                   1u
#define FTM_MODE_FAULTIE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTIE_SHIFT))&FTM_MODE_FAULTIE_MASK)
/* SYNC Bit Fields */
#define FTM_SYNC_CNTMIN_MASK                     0x1u
#define FTM_SYNC_CNTMIN_SHIFT                    0u
#define FTM_SYNC_CNTMIN_WIDTH                    1u
#define FTM_SYNC_CNTMIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMIN_SHIFT))&FTM_SYNC_CNTMIN_MASK)
#define FTM_SYNC_CNTMAX_MASK                     0x2u
#define FTM_SYNC_CNTMAX_SHIFT                    1u
#define FTM_SYNC_CNTMAX_WIDTH                    1u
#define FTM_SYNC_CNTMAX(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_CNTMAX_SHIFT))&FTM_SYNC_CNTMAX_MASK)
#define FTM_SYNC_REINIT_MASK                     0x4u
#define FTM_SYNC_REINIT_SHIFT                    2u
#define FTM_SYNC_REINIT_WIDTH                    1u
#define FTM_SYNC_REINIT(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_REINIT_SHIFT))&FTM_SYNC_REINIT_MASK)
#define FTM_SYNC_SYNCHOM_MASK                    0x8u
#define FTM_SYNC_SYNCHOM_SHIFT                   3u
#define FTM_SYNC_SYNCHOM_WIDTH                   1u
#define FTM_SYNC_SYNCHOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SYNCHOM_SHIFT))&FTM_SYNC_SYNCHOM_MASK)
#define FTM_SYNC_TRIG0_MASK                      0x10u
#define FTM_SYNC_TRIG0_SHIFT                     4u
#define FTM_SYNC_TRIG0_WIDTH                     1u
#define FTM_SYNC_TRIG0(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG0_SHIFT))&FTM_SYNC_TRIG0_MASK)
#define FTM_SYNC_TRIG1_MASK                      0x20u
#define FTM_SYNC_TRIG1_SHIFT                     5u
#define FTM_SYNC_TRIG1_WIDTH                     1u
#define FTM_SYNC_TRIG1(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG1_SHIFT))&FTM_SYNC_TRIG1_MASK)
#define FTM_SYNC_TRIG2_MASK                      0x40u
#define FTM_SYNC_TRIG2_SHIFT                     6u
#define FTM_SYNC_TRIG2_WIDTH                     1u
#define FTM_SYNC_TRIG2(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_TRIG2_SHIFT))&FTM_SYNC_TRIG2_MASK)
#define FTM_SYNC_SWSYNC_MASK                     0x80u
#define FTM_SYNC_SWSYNC_SHIFT                    7u
#define FTM_SYNC_SWSYNC_WIDTH                    1u
#define FTM_SYNC_SWSYNC(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_SYNC_SWSYNC_SHIFT))&FTM_SYNC_SWSYNC_MASK)
/* OUTINIT Bit Fields */
#define FTM_OUTINIT_CH0OI_MASK                   0x1u
#define FTM_OUTINIT_CH0OI_SHIFT                  0u
#define FTM_OUTINIT_CH0OI_WIDTH                  1u
#define FTM_OUTINIT_CH0OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH0OI_SHIFT))&FTM_OUTINIT_CH0OI_MASK)
#define FTM_OUTINIT_CH1OI_MASK                   0x2u
#define FTM_OUTINIT_CH1OI_SHIFT                  1u
#define FTM_OUTINIT_CH1OI_WIDTH                  1u
#define FTM_OUTINIT_CH1OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH1OI_SHIFT))&FTM_OUTINIT_CH1OI_MASK)
#define FTM_OUTINIT_CH2OI_MASK                   0x4u
#define FTM_OUTINIT_CH2OI_SHIFT                  2u
#define FTM_OUTINIT_CH2OI_WIDTH                  1u
#define FTM_OUTINIT_CH2OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH2OI_SHIFT))&FTM_OUTINIT_CH2OI_MASK)
#define FTM_OUTINIT_CH3OI_MASK                   0x8u
#define FTM_OUTINIT_CH3OI_SHIFT                  3u
#define FTM_OUTINIT_CH3OI_WIDTH                  1u
#define FTM_OUTINIT_CH3OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH3OI_SHIFT))&FTM_OUTINIT_CH3OI_MASK)
#define FTM_OUTINIT_CH4OI_MASK                   0x10u
#define FTM_OUTINIT_CH4OI_SHIFT                  4u
#define FTM_OUTINIT_CH4OI_WIDTH                  1u
#define FTM_OUTINIT_CH4OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH4OI_SHIFT))&FTM_OUTINIT_CH4OI_MASK)
#define FTM_OUTINIT_CH5OI_MASK                   0x20u
#define FTM_OUTINIT_CH5OI_SHIFT                  5u
#define FTM_OUTINIT_CH5OI_WIDTH                  1u
#define FTM_OUTINIT_CH5OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH5OI_SHIFT))&FTM_OUTINIT_CH5OI_MASK)
#define FTM_OUTINIT_CH6OI_MASK                   0x40u
#define FTM_OUTINIT_CH6OI_SHIFT                  6u
#define FTM_OUTINIT_CH6OI_WIDTH                  1u
#define FTM_OUTINIT_CH6OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH6OI_SHIFT))&FTM_OUTINIT_CH6OI_MASK)
#define FTM_OUTINIT_CH7OI_MASK                   0x80u
#define FTM_OUTINIT_CH7OI_SHIFT                  7u
#define FTM_OUTINIT_CH7OI_WIDTH                  1u
#define FTM_OUTINIT_CH7OI(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTINIT_CH7OI_SHIFT))&FTM_OUTINIT_CH7OI_MASK)
/* OUTMASK Bit Fields */
#define FTM_OUTMASK_CH0OM_MASK                   0x1u
#define FTM_OUTMASK_CH0OM_SHIFT                  0u
#define FTM_OUTMASK_CH0OM_WIDTH                  1u
#define FTM_OUTMASK_CH0OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH0OM_SHIFT))&FTM_OUTMASK_CH0OM_MASK)
#define FTM_OUTMASK_CH1OM_MASK                   0x2u
#define FTM_OUTMASK_CH1OM_SHIFT                  1u
#define FTM_OUTMASK_CH1OM_WIDTH                  1u
#define FTM_OUTMASK_CH1OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH1OM_SHIFT))&FTM_OUTMASK_CH1OM_MASK)
#define FTM_OUTMASK_CH2OM_MASK                   0x4u
#define FTM_OUTMASK_CH2OM_SHIFT                  2u
#define FTM_OUTMASK_CH2OM_WIDTH                  1u
#define FTM_OUTMASK_CH2OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH2OM_SHIFT))&FTM_OUTMASK_CH2OM_MASK)
#define FTM_OUTMASK_CH3OM_MASK                   0x8u
#define FTM_OUTMASK_CH3OM_SHIFT                  3u
#define FTM_OUTMASK_CH3OM_WIDTH                  1u
#define FTM_OUTMASK_CH3OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH3OM_SHIFT))&FTM_OUTMASK_CH3OM_MASK)
#define FTM_OUTMASK_CH4OM_MASK                   0x10u
#define FTM_OUTMASK_CH4OM_SHIFT                  4u
#define FTM_OUTMASK_CH4OM_WIDTH                  1u
#define FTM_OUTMASK_CH4OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH4OM_SHIFT))&FTM_OUTMASK_CH4OM_MASK)
#define FTM_OUTMASK_CH5OM_MASK                   0x20u
#define FTM_OUTMASK_CH5OM_SHIFT                  5u
#define FTM_OUTMASK_CH5OM_WIDTH                  1u
#define FTM_OUTMASK_CH5OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH5OM_SHIFT))&FTM_OUTMASK_CH5OM_MASK)
#define FTM_OUTMASK_CH6OM_MASK                   0x40u
#define FTM_OUTMASK_CH6OM_SHIFT                  6u
#define FTM_OUTMASK_CH6OM_WIDTH                  1u
#define FTM_OUTMASK_CH6OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH6OM_SHIFT))&FTM_OUTMASK_CH6OM_MASK)
#define FTM_OUTMASK_CH7OM_MASK                   0x80u
#define FTM_OUTMASK_CH7OM_SHIFT                  7u
#define FTM_OUTMASK_CH7OM_WIDTH                  1u
#define FTM_OUTMASK_CH7OM(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_OUTMASK_CH7OM_SHIFT))&FTM_OUTMASK_CH7OM_MASK)
/* COMBINE Bit Fields */
#define FTM_COMBINE_COMBINE0_MASK                0x1u
#define FTM_COMBINE_COMBINE0_SHIFT               0u
#define FTM_COMBINE_COMBINE0_WIDTH               1u
#define FTM_COMBINE_COMBINE0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE0_SHIFT))&FTM_COMBINE_COMBINE0_MASK)
#define FTM_COMBINE_COMP0_MASK                   0x2u
#define FTM_COMBINE_COMP0_SHIFT                  1u
#define FTM_COMBINE_COMP0_WIDTH                  1u
#define FTM_COMBINE_COMP0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP0_SHIFT))&FTM_COMBINE_COMP0_MASK)
#define FTM_COMBINE_DECAPEN0_MASK                0x4u
#define FTM_COMBINE_DECAPEN0_SHIFT               2u
#define FTM_COMBINE_DECAPEN0_WIDTH               1u
#define FTM_COMBINE_DECAPEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN0_SHIFT))&FTM_COMBINE_DECAPEN0_MASK)
#define FTM_COMBINE_DECAP0_MASK                  0x8u
#define FTM_COMBINE_DECAP0_SHIFT                 3u
#define FTM_COMBINE_DECAP0_WIDTH                 1u
#define FTM_COMBINE_DECAP0(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP0_SHIFT))&FTM_COMBINE_DECAP0_MASK)
#define FTM_COMBINE_DTEN0_MASK                   0x10u
#define FTM_COMBINE_DTEN0_SHIFT                  4u
#define FTM_COMBINE_DTEN0_WIDTH                  1u
#define FTM_COMBINE_DTEN0(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN0_SHIFT))&FTM_COMBINE_DTEN0_MASK)
#define FTM_COMBINE_SYNCEN0_MASK                 0x20u
#define FTM_COMBINE_SYNCEN0_SHIFT                5u
#define FTM_COMBINE_SYNCEN0_WIDTH                1u
#define FTM_COMBINE_SYNCEN0(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN0_SHIFT))&FTM_COMBINE_SYNCEN0_MASK)
#define FTM_COMBINE_FAULTEN0_MASK                0x40u
#define FTM_COMBINE_FAULTEN0_SHIFT               6u
#define FTM_COMBINE_FAULTEN0_WIDTH               1u
#define FTM_COMBINE_FAULTEN0(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN0_SHIFT))&FTM_COMBINE_FAULTEN0_MASK)
#define FTM_COMBINE_COMBINE1_MASK                0x100u
#define FTM_COMBINE_COMBINE1_SHIFT               8u
#define FTM_COMBINE_COMBINE1_WIDTH               1u
#define FTM_COMBINE_COMBINE1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE1_SHIFT))&FTM_COMBINE_COMBINE1_MASK)
#define FTM_COMBINE_COMP1_MASK                   0x200u
#define FTM_COMBINE_COMP1_SHIFT                  9u
#define FTM_COMBINE_COMP1_WIDTH                  1u
#define FTM_COMBINE_COMP1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP1_SHIFT))&FTM_COMBINE_COMP1_MASK)
#define FTM_COMBINE_DECAPEN1_MASK                0x400u
#define FTM_COMBINE_DECAPEN1_SHIFT               10u
#define FTM_COMBINE_DECAPEN1_WIDTH               1u
#define FTM_COMBINE_DECAPEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN1_SHIFT))&FTM_COMBINE_DECAPEN1_MASK)
#define FTM_COMBINE_DECAP1_MASK                  0x800u
#define FTM_COMBINE_DECAP1_SHIFT                 11u
#define FTM_COMBINE_DECAP1_WIDTH                 1u
#define FTM_COMBINE_DECAP1(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP1_SHIFT))&FTM_COMBINE_DECAP1_MASK)
#define FTM_COMBINE_DTEN1_MASK                   0x1000u
#define FTM_COMBINE_DTEN1_SHIFT                  12u
#define FTM_COMBINE_DTEN1_WIDTH                  1u
#define FTM_COMBINE_DTEN1(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN1_SHIFT))&FTM_COMBINE_DTEN1_MASK)
#define FTM_COMBINE_SYNCEN1_MASK                 0x2000u
#define FTM_COMBINE_SYNCEN1_SHIFT                13u
#define FTM_COMBINE_SYNCEN1_WIDTH                1u
#define FTM_COMBINE_SYNCEN1(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN1_SHIFT))&FTM_COMBINE_SYNCEN1_MASK)
#define FTM_COMBINE_FAULTEN1_MASK                0x4000u
#define FTM_COMBINE_FAULTEN1_SHIFT               14u
#define FTM_COMBINE_FAULTEN1_WIDTH               1u
#define FTM_COMBINE_FAULTEN1(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN1_SHIFT))&FTM_COMBINE_FAULTEN1_MASK)
#define FTM_COMBINE_COMBINE2_MASK                0x10000u
#define FTM_COMBINE_COMBINE2_SHIFT               16u
#define FTM_COMBINE_COMBINE2_WIDTH               1u
#define FTM_COMBINE_COMBINE2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE2_SHIFT))&FTM_COMBINE_COMBINE2_MASK)
#define FTM_COMBINE_COMP2_MASK                   0x20000u
#define FTM_COMBINE_COMP2_SHIFT                  17u
#define FTM_COMBINE_COMP2_WIDTH                  1u
#define FTM_COMBINE_COMP2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP2_SHIFT))&FTM_COMBINE_COMP2_MASK)
#define FTM_COMBINE_DECAPEN2_MASK                0x40000u
#define FTM_COMBINE_DECAPEN2_SHIFT               18u
#define FTM_COMBINE_DECAPEN2_WIDTH               1u
#define FTM_COMBINE_DECAPEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN2_SHIFT))&FTM_COMBINE_DECAPEN2_MASK)
#define FTM_COMBINE_DECAP2_MASK                  0x80000u
#define FTM_COMBINE_DECAP2_SHIFT                 19u
#define FTM_COMBINE_DECAP2_WIDTH                 1u
#define FTM_COMBINE_DECAP2(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP2_SHIFT))&FTM_COMBINE_DECAP2_MASK)
#define FTM_COMBINE_DTEN2_MASK                   0x100000u
#define FTM_COMBINE_DTEN2_SHIFT                  20u
#define FTM_COMBINE_DTEN2_WIDTH                  1u
#define FTM_COMBINE_DTEN2(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN2_SHIFT))&FTM_COMBINE_DTEN2_MASK)
#define FTM_COMBINE_SYNCEN2_MASK                 0x200000u
#define FTM_COMBINE_SYNCEN2_SHIFT                21u
#define FTM_COMBINE_SYNCEN2_WIDTH                1u
#define FTM_COMBINE_SYNCEN2(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN2_SHIFT))&FTM_COMBINE_SYNCEN2_MASK)
#define FTM_COMBINE_FAULTEN2_MASK                0x400000u
#define FTM_COMBINE_FAULTEN2_SHIFT               22u
#define FTM_COMBINE_FAULTEN2_WIDTH               1u
#define FTM_COMBINE_FAULTEN2(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN2_SHIFT))&FTM_COMBINE_FAULTEN2_MASK)
#define FTM_COMBINE_COMBINE3_MASK                0x1000000u
#define FTM_COMBINE_COMBINE3_SHIFT               24u
#define FTM_COMBINE_COMBINE3_WIDTH               1u
#define FTM_COMBINE_COMBINE3(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMBINE3_SHIFT))&FTM_COMBINE_COMBINE3_MASK)
#define FTM_COMBINE_COMP3_MASK                   0x2000000u
#define FTM_COMBINE_COMP3_SHIFT                  25u
#define FTM_COMBINE_COMP3_WIDTH                  1u
#define FTM_COMBINE_COMP3(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_COMP3_SHIFT))&FTM_COMBINE_COMP3_MASK)
#define FTM_COMBINE_DECAPEN3_MASK                0x4000000u
#define FTM_COMBINE_DECAPEN3_SHIFT               26u
#define FTM_COMBINE_DECAPEN3_WIDTH               1u
#define FTM_COMBINE_DECAPEN3(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAPEN3_SHIFT))&FTM_COMBINE_DECAPEN3_MASK)
#define FTM_COMBINE_DECAP3_MASK                  0x8000000u
#define FTM_COMBINE_DECAP3_SHIFT                 27u
#define FTM_COMBINE_DECAP3_WIDTH                 1u
#define FTM_COMBINE_DECAP3(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DECAP3_SHIFT))&FTM_COMBINE_DECAP3_MASK)
#define FTM_COMBINE_DTEN3_MASK                   0x10000000u
#define FTM_COMBINE_DTEN3_SHIFT                  28u
#define FTM_COMBINE_DTEN3_WIDTH                  1u
#define FTM_COMBINE_DTEN3(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_DTEN3_SHIFT))&FTM_COMBINE_DTEN3_MASK)
#define FTM_COMBINE_SYNCEN3_MASK                 0x20000000u
#define FTM_COMBINE_SYNCEN3_SHIFT                29u
#define FTM_COMBINE_SYNCEN3_WIDTH                1u
#define FTM_COMBINE_SYNCEN3(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_SYNCEN3_SHIFT))&FTM_COMBINE_SYNCEN3_MASK)
#define FTM_COMBINE_FAULTEN3_MASK                0x40000000u
#define FTM_COMBINE_FAULTEN3_SHIFT               30u
#define FTM_COMBINE_FAULTEN3_WIDTH               1u
#define FTM_COMBINE_FAULTEN3(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_COMBINE_FAULTEN3_SHIFT))&FTM_COMBINE_FAULTEN3_MASK)
/* DEADTIME Bit Fields */
#define FTM_DEADTIME_DTVAL_MASK                  0x3Fu
#define FTM_DEADTIME_DTVAL_SHIFT                 0u
#define FTM_DEADTIME_DTVAL_WIDTH                 6u
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK)
#define FTM_DEADTIME_DTPS_MASK                   0xC0u
#define FTM_DEADTIME_DTPS_SHIFT                  6u
#define FTM_DEADTIME_DTPS_WIDTH                  2u
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK)
/* EXTTRIG Bit Fields */
#define FTM_EXTTRIG_CH2TRIG_MASK                 0x1u
#define FTM_EXTTRIG_CH2TRIG_SHIFT                0u
#define FTM_EXTTRIG_CH2TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH2TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH2TRIG_SHIFT))&FTM_EXTTRIG_CH2TRIG_MASK)
#define FTM_EXTTRIG_CH3TRIG_MASK                 0x2u
#define FTM_EXTTRIG_CH3TRIG_SHIFT                1u
#define FTM_EXTTRIG_CH3TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH3TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH3TRIG_SHIFT))&FTM_EXTTRIG_CH3TRIG_MASK)
#define FTM_EXTTRIG_CH4TRIG_MASK                 0x4u
#define FTM_EXTTRIG_CH4TRIG_SHIFT                2u
#define FTM_EXTTRIG_CH4TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH4TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH4TRIG_SHIFT))&FTM_EXTTRIG_CH4TRIG_MASK)
#define FTM_EXTTRIG_CH5TRIG_MASK                 0x8u
#define FTM_EXTTRIG_CH5TRIG_SHIFT                3u
#define FTM_EXTTRIG_CH5TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH5TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH5TRIG_SHIFT))&FTM_EXTTRIG_CH5TRIG_MASK)
#define FTM_EXTTRIG_CH0TRIG_MASK                 0x10u
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4u
#define FTM_EXTTRIG_CH0TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH0TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH0TRIG_SHIFT))&FTM_EXTTRIG_CH0TRIG_MASK)
#define FTM_EXTTRIG_CH1TRIG_MASK                 0x20u
#define FTM_EXTTRIG_CH1TRIG_SHIFT                5u
#define FTM_EXTTRIG_CH1TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH1TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH1TRIG_SHIFT))&FTM_EXTTRIG_CH1TRIG_MASK)
#define FTM_EXTTRIG_INITTRIGEN_MASK              0x40u
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6u
#define FTM_EXTTRIG_INITTRIGEN_WIDTH             1u
#define FTM_EXTTRIG_INITTRIGEN(x)                (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_INITTRIGEN_SHIFT))&FTM_EXTTRIG_INITTRIGEN_MASK)
#define FTM_EXTTRIG_TRIGF_MASK                   0x80u
#define FTM_EXTTRIG_TRIGF_SHIFT                  7u
#define FTM_EXTTRIG_TRIGF_WIDTH                  1u
#define FTM_EXTTRIG_TRIGF(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_TRIGF_SHIFT))&FTM_EXTTRIG_TRIGF_MASK)
#define FTM_EXTTRIG_CH6TRIG_MASK                 0x100u
#define FTM_EXTTRIG_CH6TRIG_SHIFT                8u
#define FTM_EXTTRIG_CH6TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH6TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH6TRIG_SHIFT))&FTM_EXTTRIG_CH6TRIG_MASK)
#define FTM_EXTTRIG_CH7TRIG_MASK                 0x200u
#define FTM_EXTTRIG_CH7TRIG_SHIFT                9u
#define FTM_EXTTRIG_CH7TRIG_WIDTH                1u
#define FTM_EXTTRIG_CH7TRIG(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_EXTTRIG_CH7TRIG_SHIFT))&FTM_EXTTRIG_CH7TRIG_MASK)
/* POL Bit Fields */
#define FTM_POL_POL0_MASK                        0x1u
#define FTM_POL_POL0_SHIFT                       0u
#define FTM_POL_POL0_WIDTH                       1u
#define FTM_POL_POL0(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL0_SHIFT))&FTM_POL_POL0_MASK)
#define FTM_POL_POL1_MASK                        0x2u
#define FTM_POL_POL1_SHIFT                       1u
#define FTM_POL_POL1_WIDTH                       1u
#define FTM_POL_POL1(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL1_SHIFT))&FTM_POL_POL1_MASK)
#define FTM_POL_POL2_MASK                        0x4u
#define FTM_POL_POL2_SHIFT                       2u
#define FTM_POL_POL2_WIDTH                       1u
#define FTM_POL_POL2(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL2_SHIFT))&FTM_POL_POL2_MASK)
#define FTM_POL_POL3_MASK                        0x8u
#define FTM_POL_POL3_SHIFT                       3u
#define FTM_POL_POL3_WIDTH                       1u
#define FTM_POL_POL3(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL3_SHIFT))&FTM_POL_POL3_MASK)
#define FTM_POL_POL4_MASK                        0x10u
#define FTM_POL_POL4_SHIFT                       4u
#define FTM_POL_POL4_WIDTH                       1u
#define FTM_POL_POL4(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL4_SHIFT))&FTM_POL_POL4_MASK)
#define FTM_POL_POL5_MASK                        0x20u
#define FTM_POL_POL5_SHIFT                       5u
#define FTM_POL_POL5_WIDTH                       1u
#define FTM_POL_POL5(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL5_SHIFT))&FTM_POL_POL5_MASK)
#define FTM_POL_POL6_MASK                        0x40u
#define FTM_POL_POL6_SHIFT                       6u
#define FTM_POL_POL6_WIDTH                       1u
#define FTM_POL_POL6(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL6_SHIFT))&FTM_POL_POL6_MASK)
#define FTM_POL_POL7_MASK                        0x80u
#define FTM_POL_POL7_SHIFT                       7u
#define FTM_POL_POL7_WIDTH                       1u
#define FTM_POL_POL7(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_POL_POL7_SHIFT))&FTM_POL_POL7_MASK)
/* FMS Bit Fields */
#define FTM_FMS_FAULTF0_MASK                     0x1u
#define FTM_FMS_FAULTF0_SHIFT                    0u
#define FTM_FMS_FAULTF0_WIDTH                    1u
#define FTM_FMS_FAULTF0(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF0_SHIFT))&FTM_FMS_FAULTF0_MASK)
#define FTM_FMS_FAULTF1_MASK                     0x2u
#define FTM_FMS_FAULTF1_SHIFT                    1u
#define FTM_FMS_FAULTF1_WIDTH                    1u
#define FTM_FMS_FAULTF1(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF1_SHIFT))&FTM_FMS_FAULTF1_MASK)
#define FTM_FMS_FAULTF2_MASK                     0x4u
#define FTM_FMS_FAULTF2_SHIFT                    2u
#define FTM_FMS_FAULTF2_WIDTH                    1u
#define FTM_FMS_FAULTF2(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF2_SHIFT))&FTM_FMS_FAULTF2_MASK)
#define FTM_FMS_FAULTF3_MASK                     0x8u
#define FTM_FMS_FAULTF3_SHIFT                    3u
#define FTM_FMS_FAULTF3_WIDTH                    1u
#define FTM_FMS_FAULTF3(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF3_SHIFT))&FTM_FMS_FAULTF3_MASK)
#define FTM_FMS_FAULTIN_MASK                     0x20u
#define FTM_FMS_FAULTIN_SHIFT                    5u
#define FTM_FMS_FAULTIN_WIDTH                    1u
#define FTM_FMS_FAULTIN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTIN_SHIFT))&FTM_FMS_FAULTIN_MASK)
#define FTM_FMS_WPEN_MASK                        0x40u
#define FTM_FMS_WPEN_SHIFT                       6u
#define FTM_FMS_WPEN_WIDTH                       1u
#define FTM_FMS_WPEN(x)                          (((uint32_t)(((uint32_t)(x))<<FTM_FMS_WPEN_SHIFT))&FTM_FMS_WPEN_MASK)
#define FTM_FMS_FAULTF_MASK                      0x80u
#define FTM_FMS_FAULTF_SHIFT                     7u
#define FTM_FMS_FAULTF_WIDTH                     1u
#define FTM_FMS_FAULTF(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_FMS_FAULTF_SHIFT))&FTM_FMS_FAULTF_MASK)
/* FILTER Bit Fields */
#define FTM_FILTER_CH0FVAL_MASK                  0xFu
#define FTM_FILTER_CH0FVAL_SHIFT                 0u
#define FTM_FILTER_CH0FVAL_WIDTH                 4u
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH0FVAL_SHIFT))&FTM_FILTER_CH0FVAL_MASK)
#define FTM_FILTER_CH1FVAL_MASK                  0xF0u
#define FTM_FILTER_CH1FVAL_SHIFT                 4u
#define FTM_FILTER_CH1FVAL_WIDTH                 4u
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH1FVAL_SHIFT))&FTM_FILTER_CH1FVAL_MASK)
#define FTM_FILTER_CH2FVAL_MASK                  0xF00u
#define FTM_FILTER_CH2FVAL_SHIFT                 8u
#define FTM_FILTER_CH2FVAL_WIDTH                 4u
#define FTM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH2FVAL_SHIFT))&FTM_FILTER_CH2FVAL_MASK)
#define FTM_FILTER_CH3FVAL_MASK                  0xF000u
#define FTM_FILTER_CH3FVAL_SHIFT                 12u
#define FTM_FILTER_CH3FVAL_WIDTH                 4u
#define FTM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH3FVAL_SHIFT))&FTM_FILTER_CH3FVAL_MASK)
/* FLTCTRL Bit Fields */
#define FTM_FLTCTRL_FAULT0EN_MASK                0x1u
#define FTM_FLTCTRL_FAULT0EN_SHIFT               0u
#define FTM_FLTCTRL_FAULT0EN_WIDTH               1u
#define FTM_FLTCTRL_FAULT0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT0EN_SHIFT))&FTM_FLTCTRL_FAULT0EN_MASK)
#define FTM_FLTCTRL_FAULT1EN_MASK                0x2u
#define FTM_FLTCTRL_FAULT1EN_SHIFT               1u
#define FTM_FLTCTRL_FAULT1EN_WIDTH               1u
#define FTM_FLTCTRL_FAULT1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT1EN_SHIFT))&FTM_FLTCTRL_FAULT1EN_MASK)
#define FTM_FLTCTRL_FAULT2EN_MASK                0x4u
#define FTM_FLTCTRL_FAULT2EN_SHIFT               2u
#define FTM_FLTCTRL_FAULT2EN_WIDTH               1u
#define FTM_FLTCTRL_FAULT2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT2EN_SHIFT))&FTM_FLTCTRL_FAULT2EN_MASK)
#define FTM_FLTCTRL_FAULT3EN_MASK                0x8u
#define FTM_FLTCTRL_FAULT3EN_SHIFT               3u
#define FTM_FLTCTRL_FAULT3EN_WIDTH               1u
#define FTM_FLTCTRL_FAULT3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FAULT3EN_SHIFT))&FTM_FLTCTRL_FAULT3EN_MASK)
#define FTM_FLTCTRL_FFLTR0EN_MASK                0x10u
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               4u
#define FTM_FLTCTRL_FFLTR0EN_WIDTH               1u
#define FTM_FLTCTRL_FFLTR0EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR0EN_SHIFT))&FTM_FLTCTRL_FFLTR0EN_MASK)
#define FTM_FLTCTRL_FFLTR1EN_MASK                0x20u
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               5u
#define FTM_FLTCTRL_FFLTR1EN_WIDTH               1u
#define FTM_FLTCTRL_FFLTR1EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR1EN_SHIFT))&FTM_FLTCTRL_FFLTR1EN_MASK)
#define FTM_FLTCTRL_FFLTR2EN_MASK                0x40u
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               6u
#define FTM_FLTCTRL_FFLTR2EN_WIDTH               1u
#define FTM_FLTCTRL_FFLTR2EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR2EN_SHIFT))&FTM_FLTCTRL_FFLTR2EN_MASK)
#define FTM_FLTCTRL_FFLTR3EN_MASK                0x80u
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               7u
#define FTM_FLTCTRL_FFLTR3EN_WIDTH               1u
#define FTM_FLTCTRL_FFLTR3EN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFLTR3EN_SHIFT))&FTM_FLTCTRL_FFLTR3EN_MASK)
#define FTM_FLTCTRL_FFVAL_MASK                   0xF00u
#define FTM_FLTCTRL_FFVAL_SHIFT                  8u
#define FTM_FLTCTRL_FFVAL_WIDTH                  4u
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFVAL_SHIFT))&FTM_FLTCTRL_FFVAL_MASK)
#define FTM_FLTCTRL_FSTATE_MASK                  0x8000u
#define FTM_FLTCTRL_FSTATE_SHIFT                 15u
#define FTM_FLTCTRL_FSTATE_WIDTH                 1u
#define FTM_FLTCTRL_FSTATE(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FSTATE_SHIFT))&FTM_FLTCTRL_FSTATE_MASK)
/* QDCTRL Bit Fields */
#define FTM_QDCTRL_QUADEN_MASK                   0x1u
#define FTM_QDCTRL_QUADEN_SHIFT                  0u
#define FTM_QDCTRL_QUADEN_WIDTH                  1u
#define FTM_QDCTRL_QUADEN(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADEN_SHIFT))&FTM_QDCTRL_QUADEN_MASK)
#define FTM_QDCTRL_TOFDIR_MASK                   0x2u
#define FTM_QDCTRL_TOFDIR_SHIFT                  1u
#define FTM_QDCTRL_TOFDIR_WIDTH                  1u
#define FTM_QDCTRL_TOFDIR(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_TOFDIR_SHIFT))&FTM_QDCTRL_TOFDIR_MASK)
#define FTM_QDCTRL_QUADIR_MASK                   0x4u
#define FTM_QDCTRL_QUADIR_SHIFT                  2u
#define FTM_QDCTRL_QUADIR_WIDTH                  1u
#define FTM_QDCTRL_QUADIR(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADIR_SHIFT))&FTM_QDCTRL_QUADIR_MASK)
#define FTM_QDCTRL_QUADMODE_MASK                 0x8u
#define FTM_QDCTRL_QUADMODE_SHIFT                3u
#define FTM_QDCTRL_QUADMODE_WIDTH                1u
#define FTM_QDCTRL_QUADMODE(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_QUADMODE_SHIFT))&FTM_QDCTRL_QUADMODE_MASK)
#define FTM_QDCTRL_PHBPOL_MASK                   0x10u
#define FTM_QDCTRL_PHBPOL_SHIFT                  4u
#define FTM_QDCTRL_PHBPOL_WIDTH                  1u
#define FTM_QDCTRL_PHBPOL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHBPOL_SHIFT))&FTM_QDCTRL_PHBPOL_MASK)
#define FTM_QDCTRL_PHAPOL_MASK                   0x20u
#define FTM_QDCTRL_PHAPOL_SHIFT                  5u
#define FTM_QDCTRL_PHAPOL_WIDTH                  1u
#define FTM_QDCTRL_PHAPOL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHAPOL_SHIFT))&FTM_QDCTRL_PHAPOL_MASK)
#define FTM_QDCTRL_PHBFLTREN_MASK                0x40u
#define FTM_QDCTRL_PHBFLTREN_SHIFT               6u
#define FTM_QDCTRL_PHBFLTREN_WIDTH               1u
#define FTM_QDCTRL_PHBFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHBFLTREN_SHIFT))&FTM_QDCTRL_PHBFLTREN_MASK)
#define FTM_QDCTRL_PHAFLTREN_MASK                0x80u
#define FTM_QDCTRL_PHAFLTREN_SHIFT               7u
#define FTM_QDCTRL_PHAFLTREN_WIDTH               1u
#define FTM_QDCTRL_PHAFLTREN(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_QDCTRL_PHAFLTREN_SHIFT))&FTM_QDCTRL_PHAFLTREN_MASK)
/* CONF Bit Fields */
#define FTM_CONF_LDFQ_MASK                       0x1Fu
#define FTM_CONF_LDFQ_SHIFT                      0u
#define FTM_CONF_LDFQ_WIDTH                      5u
#define FTM_CONF_LDFQ(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CONF_LDFQ_SHIFT))&FTM_CONF_LDFQ_MASK)
#define FTM_CONF_BDMMODE_MASK                    0xC0u
#define FTM_CONF_BDMMODE_SHIFT                   6u
#define FTM_CONF_BDMMODE_WIDTH                   2u
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_BDMMODE_SHIFT))&FTM_CONF_BDMMODE_MASK)
#define FTM_CONF_GTBEEN_MASK                     0x200u
#define FTM_CONF_GTBEEN_SHIFT                    9u
#define FTM_CONF_GTBEEN_WIDTH                    1u
#define FTM_CONF_GTBEEN(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEEN_SHIFT))&FTM_CONF_GTBEEN_MASK)
#define FTM_CONF_GTBEOUT_MASK                    0x400u
#define FTM_CONF_GTBEOUT_SHIFT                   10u
#define FTM_CONF_GTBEOUT_WIDTH                   1u
#define FTM_CONF_GTBEOUT(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_GTBEOUT_SHIFT))&FTM_CONF_GTBEOUT_MASK)
#define FTM_CONF_ITRIGR_MASK                     0x800u
#define FTM_CONF_ITRIGR_SHIFT                    11u
#define FTM_CONF_ITRIGR_WIDTH                    1u
#define FTM_CONF_ITRIGR(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_ITRIGR_SHIFT))&FTM_CONF_ITRIGR_MASK)
/* FLTPOL Bit Fields */
#define FTM_FLTPOL_FLT0POL_MASK                  0x1u
#define FTM_FLTPOL_FLT0POL_SHIFT                 0u
#define FTM_FLTPOL_FLT0POL_WIDTH                 1u
#define FTM_FLTPOL_FLT0POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT0POL_SHIFT))&FTM_FLTPOL_FLT0POL_MASK)
#define FTM_FLTPOL_FLT1POL_MASK                  0x2u
#define FTM_FLTPOL_FLT1POL_SHIFT                 1u
#define FTM_FLTPOL_FLT1POL_WIDTH                 1u
#define FTM_FLTPOL_FLT1POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT1POL_SHIFT))&FTM_FLTPOL_FLT1POL_MASK)
#define FTM_FLTPOL_FLT2POL_MASK                  0x4u
#define FTM_FLTPOL_FLT2POL_SHIFT                 2u
#define FTM_FLTPOL_FLT2POL_WIDTH                 1u
#define FTM_FLTPOL_FLT2POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT2POL_SHIFT))&FTM_FLTPOL_FLT2POL_MASK)
#define FTM_FLTPOL_FLT3POL_MASK                  0x8u
#define FTM_FLTPOL_FLT3POL_SHIFT                 3u
#define FTM_FLTPOL_FLT3POL_WIDTH                 1u
#define FTM_FLTPOL_FLT3POL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FLTPOL_FLT3POL_SHIFT))&FTM_FLTPOL_FLT3POL_MASK)
/* SYNCONF Bit Fields */
#define FTM_SYNCONF_HWTRIGMODE_MASK              0x1u
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             0u
#define FTM_SYNCONF_HWTRIGMODE_WIDTH             1u
#define FTM_SYNCONF_HWTRIGMODE(x)                (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWTRIGMODE_SHIFT))&FTM_SYNCONF_HWTRIGMODE_MASK)
#define FTM_SYNCONF_CNTINC_MASK                  0x4u
#define FTM_SYNCONF_CNTINC_SHIFT                 2u
#define FTM_SYNCONF_CNTINC_WIDTH                 1u
#define FTM_SYNCONF_CNTINC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_CNTINC_SHIFT))&FTM_SYNCONF_CNTINC_MASK)
#define FTM_SYNCONF_INVC_MASK                    0x10u
#define FTM_SYNCONF_INVC_SHIFT                   4u
#define FTM_SYNCONF_INVC_WIDTH                   1u
#define FTM_SYNCONF_INVC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_INVC_SHIFT))&FTM_SYNCONF_INVC_MASK)
#define FTM_SYNCONF_SWOC_MASK                    0x20u
#define FTM_SYNCONF_SWOC_SHIFT                   5u
#define FTM_SYNCONF_SWOC_WIDTH                   1u
#define FTM_SYNCONF_SWOC(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOC_SHIFT))&FTM_SYNCONF_SWOC_MASK)
#define FTM_SYNCONF_SYNCMODE_MASK                0x80u
#define FTM_SYNCONF_SYNCMODE_SHIFT               7u
#define FTM_SYNCONF_SYNCMODE_WIDTH               1u
#define FTM_SYNCONF_SYNCMODE(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SYNCMODE_SHIFT))&FTM_SYNCONF_SYNCMODE_MASK)
#define FTM_SYNCONF_SWRSTCNT_MASK                0x100u
#define FTM_SYNCONF_SWRSTCNT_SHIFT               8u
#define FTM_SYNCONF_SWRSTCNT_WIDTH               1u
#define FTM_SYNCONF_SWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWRSTCNT_SHIFT))&FTM_SYNCONF_SWRSTCNT_MASK)
#define FTM_SYNCONF_SWWRBUF_MASK                 0x200u
#define FTM_SYNCONF_SWWRBUF_SHIFT                9u
#define FTM_SYNCONF_SWWRBUF_WIDTH                1u
#define FTM_SYNCONF_SWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWWRBUF_SHIFT))&FTM_SYNCONF_SWWRBUF_MASK)
#define FTM_SYNCONF_SWOM_MASK                    0x400u
#define FTM_SYNCONF_SWOM_SHIFT                   10u
#define FTM_SYNCONF_SWOM_WIDTH                   1u
#define FTM_SYNCONF_SWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWOM_SHIFT))&FTM_SYNCONF_SWOM_MASK)
#define FTM_SYNCONF_SWINVC_MASK                  0x800u
#define FTM_SYNCONF_SWINVC_SHIFT                 11u
#define FTM_SYNCONF_SWINVC_WIDTH                 1u
#define FTM_SYNCONF_SWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWINVC_SHIFT))&FTM_SYNCONF_SWINVC_MASK)
#define FTM_SYNCONF_SWSOC_MASK                   0x1000u
#define FTM_SYNCONF_SWSOC_SHIFT                  12u
#define FTM_SYNCONF_SWSOC_WIDTH                  1u
#define FTM_SYNCONF_SWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_SWSOC_SHIFT))&FTM_SYNCONF_SWSOC_MASK)
#define FTM_SYNCONF_HWRSTCNT_MASK                0x10000u
#define FTM_SYNCONF_HWRSTCNT_SHIFT               16u
#define FTM_SYNCONF_HWRSTCNT_WIDTH               1u
#define FTM_SYNCONF_HWRSTCNT(x)                  (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWRSTCNT_SHIFT))&FTM_SYNCONF_HWRSTCNT_MASK)
#define FTM_SYNCONF_HWWRBUF_MASK                 0x20000u
#define FTM_SYNCONF_HWWRBUF_SHIFT                17u
#define FTM_SYNCONF_HWWRBUF_WIDTH                1u
#define FTM_SYNCONF_HWWRBUF(x)                   (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWWRBUF_SHIFT))&FTM_SYNCONF_HWWRBUF_MASK)
#define FTM_SYNCONF_HWOM_MASK                    0x40000u
#define FTM_SYNCONF_HWOM_SHIFT                   18u
#define FTM_SYNCONF_HWOM_WIDTH                   1u
#define FTM_SYNCONF_HWOM(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWOM_SHIFT))&FTM_SYNCONF_HWOM_MASK)
#define FTM_SYNCONF_HWINVC_MASK                  0x80000u
#define FTM_SYNCONF_HWINVC_SHIFT                 19u
#define FTM_SYNCONF_HWINVC_WIDTH                 1u
#define FTM_SYNCONF_HWINVC(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWINVC_SHIFT))&FTM_SYNCONF_HWINVC_MASK)
#define FTM_SYNCONF_HWSOC_MASK                   0x100000u
#define FTM_SYNCONF_HWSOC_SHIFT                  20u
#define FTM_SYNCONF_HWSOC_WIDTH                  1u
#define FTM_SYNCONF_HWSOC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SYNCONF_HWSOC_SHIFT))&FTM_SYNCONF_HWSOC_MASK)
/* INVCTRL Bit Fields */
#define FTM_INVCTRL_INV0EN_MASK                  0x1u
#define FTM_INVCTRL_INV0EN_SHIFT                 0u
#define FTM_INVCTRL_INV0EN_WIDTH                 1u
#define FTM_INVCTRL_INV0EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV0EN_SHIFT))&FTM_INVCTRL_INV0EN_MASK)
#define FTM_INVCTRL_INV1EN_MASK                  0x2u
#define FTM_INVCTRL_INV1EN_SHIFT                 1u
#define FTM_INVCTRL_INV1EN_WIDTH                 1u
#define FTM_INVCTRL_INV1EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV1EN_SHIFT))&FTM_INVCTRL_INV1EN_MASK)
#define FTM_INVCTRL_INV2EN_MASK                  0x4u
#define FTM_INVCTRL_INV2EN_SHIFT                 2u
#define FTM_INVCTRL_INV2EN_WIDTH                 1u
#define FTM_INVCTRL_INV2EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV2EN_SHIFT))&FTM_INVCTRL_INV2EN_MASK)
#define FTM_INVCTRL_INV3EN_MASK                  0x8u
#define FTM_INVCTRL_INV3EN_SHIFT                 3u
#define FTM_INVCTRL_INV3EN_WIDTH                 1u
#define FTM_INVCTRL_INV3EN(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_INVCTRL_INV3EN_SHIFT))&FTM_INVCTRL_INV3EN_MASK)
/* SWOCTRL Bit Fields */
#define FTM_SWOCTRL_CH0OC_MASK                   0x1u
#define FTM_SWOCTRL_CH0OC_SHIFT                  0u
#define FTM_SWOCTRL_CH0OC_WIDTH                  1u
#define FTM_SWOCTRL_CH0OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OC_SHIFT))&FTM_SWOCTRL_CH0OC_MASK)
#define FTM_SWOCTRL_CH1OC_MASK                   0x2u
#define FTM_SWOCTRL_CH1OC_SHIFT                  1u
#define FTM_SWOCTRL_CH1OC_WIDTH                  1u
#define FTM_SWOCTRL_CH1OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OC_SHIFT))&FTM_SWOCTRL_CH1OC_MASK)
#define FTM_SWOCTRL_CH2OC_MASK                   0x4u
#define FTM_SWOCTRL_CH2OC_SHIFT                  2u
#define FTM_SWOCTRL_CH2OC_WIDTH                  1u
#define FTM_SWOCTRL_CH2OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OC_SHIFT))&FTM_SWOCTRL_CH2OC_MASK)
#define FTM_SWOCTRL_CH3OC_MASK                   0x8u
#define FTM_SWOCTRL_CH3OC_SHIFT                  3u
#define FTM_SWOCTRL_CH3OC_WIDTH                  1u
#define FTM_SWOCTRL_CH3OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OC_SHIFT))&FTM_SWOCTRL_CH3OC_MASK)
#define FTM_SWOCTRL_CH4OC_MASK                   0x10u
#define FTM_SWOCTRL_CH4OC_SHIFT                  4u
#define FTM_SWOCTRL_CH4OC_WIDTH                  1u
#define FTM_SWOCTRL_CH4OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OC_SHIFT))&FTM_SWOCTRL_CH4OC_MASK)
#define FTM_SWOCTRL_CH5OC_MASK                   0x20u
#define FTM_SWOCTRL_CH5OC_SHIFT                  5u
#define FTM_SWOCTRL_CH5OC_WIDTH                  1u
#define FTM_SWOCTRL_CH5OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OC_SHIFT))&FTM_SWOCTRL_CH5OC_MASK)
#define FTM_SWOCTRL_CH6OC_MASK                   0x40u
#define FTM_SWOCTRL_CH6OC_SHIFT                  6u
#define FTM_SWOCTRL_CH6OC_WIDTH                  1u
#define FTM_SWOCTRL_CH6OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH6OC_SHIFT))&FTM_SWOCTRL_CH6OC_MASK)
#define FTM_SWOCTRL_CH7OC_MASK                   0x80u
#define FTM_SWOCTRL_CH7OC_SHIFT                  7u
#define FTM_SWOCTRL_CH7OC_WIDTH                  1u
#define FTM_SWOCTRL_CH7OC(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH7OC_SHIFT))&FTM_SWOCTRL_CH7OC_MASK)
#define FTM_SWOCTRL_CH0OCV_MASK                  0x100u
#define FTM_SWOCTRL_CH0OCV_SHIFT                 8u
#define FTM_SWOCTRL_CH0OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH0OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH0OCV_SHIFT))&FTM_SWOCTRL_CH0OCV_MASK)
#define FTM_SWOCTRL_CH1OCV_MASK                  0x200u
#define FTM_SWOCTRL_CH1OCV_SHIFT                 9u
#define FTM_SWOCTRL_CH1OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH1OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH1OCV_SHIFT))&FTM_SWOCTRL_CH1OCV_MASK)
#define FTM_SWOCTRL_CH2OCV_MASK                  0x400u
#define FTM_SWOCTRL_CH2OCV_SHIFT                 10u
#define FTM_SWOCTRL_CH2OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH2OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH2OCV_SHIFT))&FTM_SWOCTRL_CH2OCV_MASK)
#define FTM_SWOCTRL_CH3OCV_MASK                  0x800u
#define FTM_SWOCTRL_CH3OCV_SHIFT                 11u
#define FTM_SWOCTRL_CH3OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH3OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH3OCV_SHIFT))&FTM_SWOCTRL_CH3OCV_MASK)
#define FTM_SWOCTRL_CH4OCV_MASK                  0x1000u
#define FTM_SWOCTRL_CH4OCV_SHIFT                 12u
#define FTM_SWOCTRL_CH4OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH4OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH4OCV_SHIFT))&FTM_SWOCTRL_CH4OCV_MASK)
#define FTM_SWOCTRL_CH5OCV_MASK                  0x2000u
#define FTM_SWOCTRL_CH5OCV_SHIFT                 13u
#define FTM_SWOCTRL_CH5OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH5OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH5OCV_SHIFT))&FTM_SWOCTRL_CH5OCV_MASK)
#define FTM_SWOCTRL_CH6OCV_MASK                  0x4000u
#define FTM_SWOCTRL_CH6OCV_SHIFT                 14u
#define FTM_SWOCTRL_CH6OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH6OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH6OCV_SHIFT))&FTM_SWOCTRL_CH6OCV_MASK)
#define FTM_SWOCTRL_CH7OCV_MASK                  0x8000u
#define FTM_SWOCTRL_CH7OCV_SHIFT                 15u
#define FTM_SWOCTRL_CH7OCV_WIDTH                 1u
#define FTM_SWOCTRL_CH7OCV(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_SWOCTRL_CH7OCV_SHIFT))&FTM_SWOCTRL_CH7OCV_MASK)
/* PWMLOAD Bit Fields */
#define FTM_PWMLOAD_CH0SEL_MASK                  0x1u
#define FTM_PWMLOAD_CH0SEL_SHIFT                 0u
#define FTM_PWMLOAD_CH0SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH0SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH0SEL_SHIFT))&FTM_PWMLOAD_CH0SEL_MASK)
#define FTM_PWMLOAD_CH1SEL_MASK                  0x2u
#define FTM_PWMLOAD_CH1SEL_SHIFT                 1u
#define FTM_PWMLOAD_CH1SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH1SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH1SEL_SHIFT))&FTM_PWMLOAD_CH1SEL_MASK)
#define FTM_PWMLOAD_CH2SEL_MASK                  0x4u
#define FTM_PWMLOAD_CH2SEL_SHIFT                 2u
#define FTM_PWMLOAD_CH2SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH2SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH2SEL_SHIFT))&FTM_PWMLOAD_CH2SEL_MASK)
#define FTM_PWMLOAD_CH3SEL_MASK                  0x8u
#define FTM_PWMLOAD_CH3SEL_SHIFT                 3u
#define FTM_PWMLOAD_CH3SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH3SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH3SEL_SHIFT))&FTM_PWMLOAD_CH3SEL_MASK)
#define FTM_PWMLOAD_CH4SEL_MASK                  0x10u
#define FTM_PWMLOAD_CH4SEL_SHIFT                 4u
#define FTM_PWMLOAD_CH4SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH4SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH4SEL_SHIFT))&FTM_PWMLOAD_CH4SEL_MASK)
#define FTM_PWMLOAD_CH5SEL_MASK                  0x20u
#define FTM_PWMLOAD_CH5SEL_SHIFT                 5u
#define FTM_PWMLOAD_CH5SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH5SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH5SEL_SHIFT))&FTM_PWMLOAD_CH5SEL_MASK)
#define FTM_PWMLOAD_CH6SEL_MASK                  0x40u
#define FTM_PWMLOAD_CH6SEL_SHIFT                 6u
#define FTM_PWMLOAD_CH6SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH6SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH6SEL_SHIFT))&FTM_PWMLOAD_CH6SEL_MASK)
#define FTM_PWMLOAD_CH7SEL_MASK                  0x80u
#define FTM_PWMLOAD_CH7SEL_SHIFT                 7u
#define FTM_PWMLOAD_CH7SEL_WIDTH                 1u
#define FTM_PWMLOAD_CH7SEL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_CH7SEL_SHIFT))&FTM_PWMLOAD_CH7SEL_MASK)
#define FTM_PWMLOAD_HCSEL_MASK                   0x100u
#define FTM_PWMLOAD_HCSEL_SHIFT                  8u
#define FTM_PWMLOAD_HCSEL_WIDTH                  1u
#define FTM_PWMLOAD_HCSEL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_HCSEL_SHIFT))&FTM_PWMLOAD_HCSEL_MASK)
#define FTM_PWMLOAD_LDOK_MASK                    0x200u
#define FTM_PWMLOAD_LDOK_SHIFT                   9u
#define FTM_PWMLOAD_LDOK_WIDTH                   1u
#define FTM_PWMLOAD_LDOK(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_LDOK_SHIFT))&FTM_PWMLOAD_LDOK_MASK)
#define FTM_PWMLOAD_GLEN_MASK                    0x400u
#define FTM_PWMLOAD_GLEN_SHIFT                   10u
#define FTM_PWMLOAD_GLEN_WIDTH                   1u
#define FTM_PWMLOAD_GLEN(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_GLEN_SHIFT))&FTM_PWMLOAD_GLEN_MASK)
#define FTM_PWMLOAD_GLDOK_MASK                   0x800u
#define FTM_PWMLOAD_GLDOK_SHIFT                  11u
#define FTM_PWMLOAD_GLDOK_WIDTH                  1u
#define FTM_PWMLOAD_GLDOK(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_PWMLOAD_GLDOK_SHIFT))&FTM_PWMLOAD_GLDOK_MASK)
/* HCR Bit Fields */
#define FTM_HCR_HCVAL_MASK                       0xFFFFu
#define FTM_HCR_HCVAL_SHIFT                      0u
#define FTM_HCR_HCVAL_WIDTH                      16u
#define FTM_HCR_HCVAL(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_HCR_HCVAL_SHIFT))&FTM_HCR_HCVAL_MASK)

/*!
 * @}
 */ /* end of group FTM_Register_Masks */


/*!
 * @}
 */ /* end of group FTM_Peripheral_Access_Layer */

/* MC_ME registers definitions */

#define MC_ME_BASE_ADDR					(0x4004A000)
/* MC_ME_GS */
#define MC_ME_GS						(MC_ME_BASE_ADDR + 0x00000000)

#define MC_ME_GS_S_SYSCLK_FIRC			(0x0 << 0)
#define MC_ME_GS_S_SYSCLK_FXOSC			(0x1 << 0)
#define MC_ME_GS_S_SYSCLK_ARMPLL		(0x2 << 0)
#define MC_ME_GS_S_STSCLK_DISABLE		(0xF << 0)
#define MC_ME_GS_S_FIRC					(1 << 4)
#define MC_ME_GS_S_XOSC					(1 << 5)
#define MC_ME_GS_S_ARMPLL				(1 << 6)
#define MC_ME_GS_S_PERPLL				(1 << 7)
#define MC_ME_GS_S_ENETPLL				(1 << 8)
#define MC_ME_GS_S_DDRPLL				(1 << 9)
#define MC_ME_GS_S_VIDEOPLL				(1 << 10)
#define MC_ME_GS_S_MVR					(1 << 20)
#define MC_ME_GS_S_PDO					(1 << 23)
#define MC_ME_GS_S_MTRANS				(1 << 27)
#define MC_ME_GS_S_CRT_MODE_RESET		(0x0 << 28)
#define MC_ME_GS_S_CRT_MODE_TEST		(0x1 << 28)
#define MC_ME_GS_S_CRT_MODE_DRUN		(0x3 << 28)
#define MC_ME_GS_S_CRT_MODE_RUN0		(0x4 << 28)
#define MC_ME_GS_S_CRT_MODE_RUN1		(0x5 << 28)
#define MC_ME_GS_S_CRT_MODE_RUN2		(0x6 << 28)
#define MC_ME_GS_S_CRT_MODE_RUN3		(0x7 << 28)

/* MC_ME_MCTL */
#define MC_ME_MCTL						(MC_ME_BASE_ADDR + 0x00000004)

#define MC_ME_MCTL_KEY					(0x00005AF0)
#define MC_ME_MCTL_INVERTEDKEY			(0x0000A50F)
#define MC_ME_MCTL_RESET				(0x0 << 28)
#define MC_ME_MCTL_TEST					(0x1 << 28)
#define MC_ME_MCTL_DRUN					(0x3 << 28)
#define MC_ME_MCTL_RUN0					(0x4 << 28)
#define MC_ME_MCTL_RUN1					(0x5 << 28)
#define MC_ME_MCTL_RUN2					(0x6 << 28)
#define MC_ME_MCTL_RUN3					(0x7 << 28)


/* MC_ME_ME */
#define MC_ME_ME						(MC_ME_BASE_ADDR + 0x00000008)

#define MC_ME_ME_RESET_FUNC				(1 << 0)
#define MC_ME_ME_TEST					(1 << 1)
#define MC_ME_ME_DRUN					(1 << 3)
#define MC_ME_ME_RUN0					(1 << 4)
#define MC_ME_ME_RUN1					(1 << 5)
#define MC_ME_ME_RUN2					(1 << 6)
#define MC_ME_ME_RUN3					(1 << 7)

/* MC_ME_RUN_PCn */
#define MC_ME_RUN_PCn(n)				(MC_ME_BASE_ADDR + 0x00000080 + 0x4 * (n))

#define MC_ME_RUN_PCn_RESET				(1 << 0)
#define MC_ME_RUN_PCn_TEST				(1 << 1)
#define MC_ME_RUN_PCn_DRUN				(1 << 3)
#define MC_ME_RUN_PCn_RUN0				(1 << 4)
#define MC_ME_RUN_PCn_RUN1				(1 << 5)
#define MC_ME_RUN_PCn_RUN2				(1 << 6)
#define MC_ME_RUN_PCn_RUN3				(1 << 7)

/*
 * MC_ME_RESET_MC/MC_ME_TEST_MC
 * MC_ME_DRUN_MC
 * MC_ME_RUNn_MC
 */
#define MC_ME_RESET_MC						(MC_ME_BASE_ADDR + 0x00000020)
#define MC_ME_TEST_MC						(MC_ME_BASE_ADDR + 0x00000024)
#define MC_ME_DRUN_MC						(MC_ME_BASE_ADDR + 0x0000002C)
#define MC_ME_RUNn_MC(n)					(MC_ME_BASE_ADDR + 0x00000030 + 0x4 * (n))

#define MC_ME_RUNMODE_MC_SYSCLK(val)	(MC_ME_RUNMODE_MC_SYSCLK_MASK & (val))
#define MC_ME_RUNMODE_MC_SYSCLK_MASK	(0x0000000F)
#define MC_ME_RUNMODE_MC_FIRCON			(1 << 4)
#define MC_ME_RUNMODE_MC_XOSCON			(1 << 5)
#define MC_ME_RUNMODE_MC_PLL(pll)		(1 << (6 + (pll)))
#define MC_ME_RUNMODE_MC_MVRON			(1 << 20)
#define MC_ME_RUNMODE_MC_PDO			(1 << 23)
#define MC_ME_RUNMODE_MC_PWRLVL0		(1 << 28)
#define MC_ME_RUNMODE_MC_PWRLVL1		(1 << 29)
#define MC_ME_RUNMODE_MC_PWRLVL2		(1 << 30)

/* MC_ME_DRUN_SEC_CC_I */
#define MC_ME_DRUN_SEC_CC_I					(MC_ME_BASE_ADDR + 0x260)
/* MC_ME_RUNn_SEC_CC_I */
#define MC_ME_RUNn_SEC_CC_I(n)				(MC_ME_BASE_ADDR + 0x270 + (n) * 0x10)
#define MC_ME_RUNMODE_SEC_CC_I_SYSCLK(val,offset)	((MC_ME_RUNMODE_SEC_CC_I_SYSCLK_MASK & (val)) << offset)
#define MC_ME_RUNMODE_SEC_CC_I_SYSCLK1_OFFSET	(4)
#define MC_ME_RUNMODE_SEC_CC_I_SYSCLK2_OFFSET	(8)
#define MC_ME_RUNMODE_SEC_CC_I_SYSCLK3_OFFSET	(12)
#define MC_ME_RUNMODE_SEC_CC_I_SYSCLK_MASK		(0x3)

/* MC_CGM registers definitions */

#define MC_CGM0_BASE_ADDRESS		(0x4003C000)
#define MC_CGM2_BASE_ADDRESS		(0x40042000)

/* MC_CGM_SC_SS */
#define CGM_SC_SS(cgm_addr)			( ((cgm_addr) + 0x000007E4) )
#define MC_CGM_SC_SEL_FIRC			(0x0)
#define MC_CGM_SC_SEL_XOSC			(0x1)
#define MC_CGM_SC_SEL_ARMPLL		(0x2)
#define MC_CGM_SC_SEL_CLKDISABLE	(0xF)

/* MC_CGM_SC_DCn */
#define CGM_SC_DCn(cgm_addr,dc)		( ((cgm_addr) + 0x000007E8) + ((dc) * 0x4) )
#define MC_CGM_SC_DCn_PREDIV(val)	(MC_CGM_SC_DCn_PREDIV_MASK & ((val) << MC_CGM_SC_DCn_PREDIV_OFFSET))
#define MC_CGM_SC_DCn_PREDIV_MASK	(0x00070000)
#define MC_CGM_SC_DCn_PREDIV_OFFSET	(16)
#define MC_CGM_SC_DCn_DE			(1 << 31)
#define MC_CGM_SC_SEL_MASK			(0x0F000000)
#define MC_CGM_SC_SEL_OFFSET		(24)

/* MC_CGM_ACn_DCm */
#define CGM_ACn_DCm(cgm_addr,ac,dc)		( ((cgm_addr) + 0x00000808) + ((ac) * 0x20) + ((dc) * 0x4) )
#define MC_CGM_ACn_DCm_PREDIV(val)		(MC_CGM_ACn_DCm_PREDIV_MASK & ((val) << MC_CGM_ACn_DCm_PREDIV_OFFSET))

/*
 * MC_CGM_ACn_DCm_PREDIV_MASK is on 5 bits because practical test has shown
 * that the 5th bit is always ignored during writes if the current
 * MC_CGM_ACn_DCm_PREDIV field has only 4 bits
 *
 * The manual states only selectors 1, 5 and 15 have DC0_PREDIV on 5 bits
 *
 * This should be changed if any problems occur.
 */
#define MC_CGM_ACn_DCm_PREDIV_MASK		(0x001F0000)
#define MC_CGM_ACn_DCm_PREDIV_OFFSET	(16)
#define MC_CGM_ACn_DCm_DE				(1 << 31)

/*
 * MC_CGM_ACn_SC/MC_CGM_ACn_SS
 */
#define CGM_ACn_SC(cgm_addr,ac)			((cgm_addr + 0x00000800) + ((ac) * 0x20))
#define CGM_ACn_SS(cgm_addr,ac)			((cgm_addr + 0x00000804) + ((ac) * 0x20))
#define MC_CGM_ACn_SEL_MASK				(0x0F000000)
#define MC_CGM_ACn_SEL_SET(source)		(MC_CGM_ACn_SEL_MASK & (((source) & 0xF) << MC_CGM_ACn_SEL_OFFSET))
#define MC_CGM_ACn_SEL_OFFSET			(24)

#define MC_CGM_ACn_SEL_FIRC				(0x0)
#define MC_CGM_ACn_SEL_XOSC				(0x1)
#define MC_CGM_ACn_SEL_ARMPLL			(0x2)
/*
 * According to the manual some PLL can be divided by X (X={1,3,5}):
 * PERPLLDIVX, VIDEOPLLDIVX.
 */
#define MC_CGM_ACn_SEL_PERPLLDIVX		(0x3)
#define MC_CGM_ACn_SEL_ENETPLL			(0x4)
#define MC_CGM_ACn_SEL_DDRPLL			(0x5)
#define MC_CGM_ACn_SEL_EXTSRCPAD		(0x7)
#define MC_CGM_ACn_SEL_SYSCLK			(0x8)
#define MC_CGM_ACn_SEL_VIDEOPLLDIV2		(0x9)
#define MC_CGM_ACn_SEL_PERCLK			(0xA)


#define FXOSC_BASE_ADDRESS				(0x4003C000)
#define FXOSC							(FXOSC_BASE_ADDRESS + 0x00000280)

#ifdef __MWERKS__
#pragma pop
#endif

#ifdef  __cplusplus
}
#endif
#endif