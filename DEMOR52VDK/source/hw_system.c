#include <stdint.h>
#include "hw_system.h"

unsigned long SystemCoreClock = 100000000UL;

#define BASE_ADDRESS_MC_ME      0x40088000u
#define MC_ME_CTL_KEY           *(volatile unsigned int*)(BASE_ADDRESS_MC_ME + 0x000u)
#define MC_ME_PRTN0_PCONF       *(volatile unsigned int*)(BASE_ADDRESS_MC_ME + 0x100u)
#define MC_ME_PRTN0_PUPD        *(volatile unsigned int*)(BASE_ADDRESS_MC_ME + 0x104u)

/*
 * system initialization : system clock, interrupt router ...
 */
void SystemInit(void)
{
#if defined(OS_FOR_VDK)
    /* SWT4 is not available in the FPGA thus it can be disabled */
    volatile swt_t * SWT4 = (volatile swt_t *)SWT4_BASE;

    /* SWT4 is not available in the FPGA thus it can be disabled */
    SWT4->SR = SWT_UNLOCK_SEQ1_U32;
    SWT4->SR = SWT_UNLOCK_SEQ2_U32;
    SWT4->CR = SWT4->CR & ~SWT_WDG_ENABLED_U32;
#endif

    /* enable clock for both FTMs */
    MC_ME_PRTN0_PUPD = 0x1; /* PCUD */
    MC_ME_PRTN0_PCONF = 0x1; /* PCE */
    MC_ME_CTL_KEY = 0x5AF0;
    MC_ME_CTL_KEY = 0xA50F;
}

extern void SysTick_Handler(void);
extern void vInitInterruptTable(int, void*);

#define TIMER_INT_ID        30

void vUpdateTimer(void)
{
    uint64_t cnt_val = SYSTIMER_GET_CNTPCT;
	uint32_t val, val2;
	cnt_val += (uint64_t)OS_TICK;
	val = cnt_val;
	val2 = (cnt_val >> 32);
    SYSTIMER_SET_CNTP_CVAL(val, val2);
}

void prvSetupTimerInterrupt(void)
{
	uint64_t cnt_val = SYSTIMER_GET_CNTPCT;
	uint32_t val, val2;
	cnt_val += (uint64_t)OS_TICK;
	val = cnt_val;
	val2 = (cnt_val >> 32);
    SYSTIMER_SET_CNTP_CVAL(val, val2);
	vInitInterruptTable(TIMER_INT_ID, SysTick_Handler);
	SYSTIMER_SET_CNTP_CTL(SYSTIMER_GET_CNTP_CTL | ENABLE);
	vGicEnableInterrupt(TIMER_INT_ID, 1);
}

#define STM_INT(id)             (56 + (id))
void vSetupStm(TimerCfg_t* pTimerCfg, InterruptCfg_t* pIntCfg)
{
#if defined(CLUSTER0)
    IR_ROUTE_INT(STM_INT(pTimerCfg->m_TimerId) - 32, IR_ROUTE_2_CLUSTER0);
#elif defined(CLUSTER1)
    IR_ROUTE_INT(STM_INT(pTimerCfg->m_TimerId) - 32, IR_ROUTE_2_CLUSTER1);
#else
    #error "no cluster defined"
#endif
    vInitInterruptTable(STM_INT(pTimerCfg->m_TimerId), pIntCfg->mp_Handler);
    STM_ENABLE_CHAN(pTimerCfg->m_TimerId, pTimerCfg->m_ChannelId, pTimerCfg->m_Val);
    STM_ENABLE(pTimerCfg->m_TimerId, pTimerCfg->m_Div);
    vGicEnableInterrupt(STM_INT(pTimerCfg->m_TimerId), pIntCfg->m_Priority);
}

void vGicInit(void)
{
	/** check if the Group0 is disabled and Group1 is enabled */
	uint32_t i = GET_GIC_GROUPS_STATUS;
	
	if ((OSINTC_D_GROUP_0 & i)) {
		SET_GIC_GROUP(OSINTC_D_GROUP_0, 0); /* disable group 0 FIQ */
	}
	if (!(OSINTC_D_GROUP_1 & i)) {
		SET_GIC_GROUP(OSINTC_D_GROUP_1, 1); /* enable group 1 IRQ */
	}
	/* Redistributor settings */
	WAKE_UP_PE;
	/* default priority mask. */
	OSINTC_SET_INT_PRI_MASK(OSINTC_GIC_CONVERT_PRIO_SET( OSINTC_GIC_MIN_PRIO ));
	/* reset EOImode & CBPR*/
	i = OSINTC_GET_ICC_CTRL & (~3ul);
	OSINTC_SET_ICC_CTRL(i);
	
	/* Core interface disable Fiq enable Irq */
	if (OSINTC_GET_ICC_GRPEN0 & 1) {
		OSINTC_SET_ICC_GRPEN0(0);
	}
	
	if (!(OSINTC_GET_ICC_GRPEN1 & 1)) {
		OSINTC_SET_ICC_GRPEN1(1);
	}
	
	
	/*set to 1 to supports interrupt grouping for group1*/
	OSINTC_SET_ICC_CTRL(1);
	
	/* clear redistributor interrupts */
	for (i = 0; i < 32; i ++) {
		OSINTC_GIC_DISABLE_INTX(i);        /**< disable interrupt       */
		OSINTC_GIC_CLEAR_PENDING_INTX(i);  /**< clear pending interrupt */
		OSINTC_SET_PRIO_INTX(i, OSINTC_GIC_CONVERT_PRIO_SET( OSINTC_GIC_MIN_PRIO ));     /**< set priority to MIN */
	}
	for (i = 32; i < 1024; i ++) {
		OSINTC_GIC_DISABLE_INTX(i);        /**< disable interrupt       */
		OSINTC_GIC_CLEAR_PENDING_INTX(i);  /**< clear pending interrupt */
		OSINTC_SET_PRIO_INTX(i, OSINTC_GIC_CONVERT_PRIO_SET( OSINTC_GIC_MIN_PRIO ));     /**< set priority to MIN */
	}
}

void vGicEnableInterrupt(int index, int prio)
{
	OSINTC_GIC_GROUP_INTX(index, 1);
	OSINTC_GIC_CONFIG_INTX(index, 0);
	OSINTC_SET_PRIO_INTX(index, OSINTC_GIC_CONVERT_PRIO_SET(prio)); /**<  set priority */
	OSINTC_GIC_ROUTE_INTX(index, (0));
	OSINTC_GIC_ENABLE_INTX(index); /**< enable interrupt       */
}
