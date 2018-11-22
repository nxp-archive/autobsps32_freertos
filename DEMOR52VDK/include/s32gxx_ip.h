#ifndef _S32GXX_IP_H_
#define _S32GXX_IP_H_
/**************************************************************************************
*
*   Freescale(TM) and the Freescale logo are trademarks of Freescale Semiconductor, Inc.
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2016 Freescale Semiconductor Inc.
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided "as is", without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct derivation
*      thereof.
*
*  Description:  S32GXX peripherals
*
**************************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/* register access */
#define SYS_REG32(address)      ( *(volatile int   *)(address) ) /**<  32-bit register */
#define SYS_REG16(address)      ( *(volatile short *)(address) ) /**<  16-bit register */
#define SYS_REG8(address)       ( *(volatile char  *)(address) ) /**<   8-bit register */

typedef unsigned char uint8_t;
typedef volatile unsigned int vuint32_t;

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


#define SWT_UNLOCK_SEQ1_U32 (0x0000C520UL)
#define SWT_UNLOCK_SEQ2_U32 (0x0000D928UL)
#define SWT_WDG_ENABLED_U32 (0x00000001UL)

typedef struct {
    unsigned int CR;
    unsigned int IR;
    unsigned int TO;
    unsigned int WN;
    unsigned int SR;
    unsigned int KO;
    unsigned int SK;
} swt_t;



#ifdef __cplusplus
}
#endif

#endif /* _S32GXX_IP_H_ */

