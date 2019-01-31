#ifndef HW_SYSTEM_H
#define HW_SYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif
#define OS_TICK                 0x20000

/* register access */
#define SYS_REG32(address)      ( *(volatile int   *)(address) ) /**<  32-bit register */
#define SYS_REG16(address)      ( *(volatile short *)(address) ) /**<  16-bit register */
#define SYS_REG8(address)       ( *(volatile char  *)(address) ) /**<   8-bit register */

/** STM */
#define STM_BASE(id)                        (0x4011C000 + (id) * 0x4000)
#define STM_ENABLE(id, div)                 (SYS_REG32(STM_BASE(id)) = 3 + ((0xff & (div)) << 8))
#define STM_ENABLE_CHAN(id, chan, cmp)      {                                                                       \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x14) = 1;                 \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x18) = (cmp);             \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x10) = 1;                 \
                                            }
#define STM_UPDATE_CHAN(id, chan, new)      {                                                                       \
                                                uint32_t oldVal = SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x18);   \
                                                oldVal += (new);                                                    \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x14) = 1;                 \
                                                SYS_REG32(STM_BASE(id) + 0x10 * (chan) + 0x18) = oldVal;            \
                                            }
                                               
#define SWT4_BASE           (0x40200000)
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

/* Interrupt Router base address */
#define IR_BASE_ADDR 0x40198000UL

#define IR_SPRC(x) SYS_REG16( IR_BASE_ADDR + 0x880 + ((x)<<1) ) /**< Interrupt Router Shared Peripheral Routing Control */
#define IR_ROUTE_INT(id,cluster)    IR_SPRC(id)=(cluster)       /**< route interrupt to cluster, id=0->111, cluster={0,1} */


#define IR_ROUTE_2_CLUSTER0     (1UL)
#define IR_ROUTE_2_CLUSTER1     (2UL)

#define IR_ROUTE_NO_INT     (248UL)

/* route all interrupts to selected cluster */
#define IR_ROUTE_ALL_2_CPU(cluster)                 \
            {                                       \
                int x;                              \
                for (x=0; x<IR_ROUTE_NO_INT; x++) { \
                        IR_ROUTE_INT(x, (cluster)); \
                    }                               \
            }                                       \

#define OSSTRING(x) #x
#define OSREG32( address )  ( *(volatile uint32_t*)(address) )

/** coprocessor access macros */
/* write 32bit to coprocessor */
#define __MCR(coproc, opcode1, Rd, CRn, CRm, opcode2) \
            __asm volatile(" "OSSTRING(mcr p##coproc)", "OSSTRING(opcode1)", %0, "OSSTRING(c##CRn)", "OSSTRING(c##CRm)", "OSSTRING(opcode2)" ": : "r"(Rd))
/* read 32bit from coprocessor */
#define __MRC(coproc, opcode1, CRn, CRm, opcode2) ({ \
            register uint32_t _tempRegRt; \
            __asm volatile(" "OSSTRING(mrc p##coproc)", "OSSTRING(opcode1)", %0, "OSSTRING(c##CRn)", "OSSTRING(c##CRm)", "OSSTRING(opcode2)" ": "=r"(_tempRegRt));   \
            _tempRegRt; })
/* write 64bit to coprocessor */
#define __MCRR(coproc, opcode1, Rd, Rd2, CRm) ({ \
            __asm volatile(" "OSSTRING(mcrr p##coproc)", "OSSTRING(opcode1)", %0, %1, "OSSTRING(c##CRm)" ": : "r"(Rd), "r"(Rd2)); })
/* read 64bit from coprocessor */
#define __MRRC(coproc, opcode1, CRm) ({ \
            uint32_t Rd, Rd2;                           \
            uint64_t retval;                            \
            __asm volatile(" "OSSTRING(mrrc p##coproc)", "OSSTRING(opcode1)", %0, %1, "OSSTRING(c##CRm)" ": "=r"(Rd), "=r"(Rd2): ); \
            retval = ((uint64_t)Rd2);                   \
            retval = (retval << 32);                    \
            retval |= Rd;                               \
            retval;})

/** GIC V3 */

#define OSINTC_GIC_GET_BASE  __MRC( 15,  1, 15,  3,  0)

#define OSINTC_GIC_PRIO_BITS    (5u)
#define OSINTC_GIC_PRIO_LEVELS  (1UL << OSINTC_GIC_PRIO_BITS)
#define OSINTC_GIC_PRIO_SHIFT   (8u - OSINTC_GIC_PRIO_BITS)

#define OSINTC_GICD_OFFSET            (0x00000000ul)
#define OSINTC_GICR_CTRL_0            (0x00100000ul)
#define OSINTC_GICR_PPI_0             (0x00110000ul)
#define OSINTC_GICR_CTRL_1            (0x00120000ul)
#define OSINTC_GICR_PPI_1             (0x00130000ul)
#define OSINTC_GICR_CTRL_2            (0x00140000ul)
#define OSINTC_GICR_PPI_2             (0x00150000ul)
#define OSINTC_GICR_CTRL_3            (0x00160000ul)
#define OSINTC_GICR_PPI_3             (0x00170000ul)
#define OSINTC_GICR_CTRL_4            (0x00180000ul)
#define OSINTC_GICR_PPI_4             (0x00190000ul)

/* distribuitor offsets */
/* Table 9-4 Distributor Registers (GICD) summary */
#define OSINTC_GICD_CTLR              (0ul)
#define OSINTC_D_RWP                  (1ul << 31)
#define OSINTC_D_GROUP_0              (1ul << 0)
#define OSINTC_D_GROUP_1              (1ul << 1)
#define OSINTC_GICD_TYPER             (4ul)
#define OSINTC_GICD_IIDR              (8ul)
/* base address for this registers decremented with 32-bits in order to accommodate interrupts with id >=32 */
#define OSINTC_GICD_IGROUPR1          (0x80ul) /* 1-30, 0x84-0xf8 */
#define OSINTC_GICD_ISENABLER1        (0x100ul) /* 1-30, 0x104-0x178 */
#define OSINTC_GICD_ICENABLER1        (0x180ul) /* 1-30, 0x184-0x1f8 */
#define OSINTC_GICD_ISPENDR1          (0x200ul) /* 1-30, 0x204-0x278 */
#define OSINTC_GICD_ICPENDR1          (0x280ul) /* 1-30, 0x284-0x2f8 */
#define OSINTC_GICD_ISACTIVER1        (0x300ul) /* 1-30, 0x304-0x378 */
#define OSINTC_GICD_ICACTIVER1        (0x380ul) /* 1-30, 0x384-0x3f8 */
#define OSINTC_GICD_IPRIORITYR8       (0x400ul) /* 8-247, 0x420-0x7dc */
#define OSINTC_GICD_ICFGR2            (0xc00ul) /* 2-61, 0xc08-0xcf4 */
#define OSINTC_GICD_IROUTER32         (0x6000ul) /* 32-991, 0x6100-0x7ef8 */
#define OSINTC_GICD_PIDR0             (0xffe0ul)
#define OSINTC_GICD_PIDR1             (0xffe4ul)
#define OSINTC_GICD_PIDR2             (0xffe8ul)
#define OSINTC_GICD_PIDR3             (0xffecul)
#define OSINTC_GICD_PIDR4             (0xffd0ul)
#define OSINTC_GICD_PIDR5             (0xffd4ul)
#define OSINTC_GICD_PIDR6             (0xffd8ul)
#define OSINTC_GICD_PIDR7             (0xffdcul)
#define OSINTC_GICD_CIDR0             (0xfff0ul)
#define OSINTC_GICD_CIDR1             (0xfff4ul)
#define OSINTC_GICD_CIDR2             (0xfff8ul)
#define OSINTC_GICD_CIDR3             (0xfffcul)
/* redistributor offsets */
/* Table 9-21 Redistributor Registers (GICR) for Control summary */
#define OSINTC_GICR_CTLR              (0ul)
#define OSINTC_R_RWP                  (1 << 3)
#define OSINTC_GICR_IIDR              (4ul)
#define OSINTC_GICR_TYPER             (8ul)
#define OSINTC_GICR_WAKER             (0x14ul)
#define OSINTC_CLD_ASLEEP             (1 << 2)
#define OSINTC_PROC_SLEEP             (1 << 1)
#define OSINTC_GICR_PIDR0             (0xffe0ul)
#define OSINTC_GICR_PIDR1             (0xffe4ul)
#define OSINTC_GICR_PIDR2             (0xffe8ul)
#define OSINTC_GICR_PIDR3             (0xffecul)
#define OSINTC_GICR_PIDR4             (0xffd0ul)
#define OSINTC_GICR_PIDR5             (0xffd4ul)
#define OSINTC_GICR_PIDR6             (0xffd8ul)
#define OSINTC_GICR_PIDR7             (0xffdcul)
#define OSINTC_GICR_CIDR0             (0xfff0ul)
#define OSINTC_GICR_CIDR1             (0xfff4ul)
#define OSINTC_GICR_CIDR2             (0xfff8ul)
#define OSINTC_GICR_CIDR3             (0xfffcul)

/* Table 9-22 Redistributor Registers (GICR) for SGIs and PPIs summary */
#define OSINTC_GICR_IGROUPR0          (0x80ul)
#define OSINTC_GICR_ISENABLER0        (0x100ul)
#define OSINTC_GICR_ICENABLER0        (0x180ul)
#define OSINTC_GICR_ISPENDR0          (0x200ul)
#define OSINTC_GICR_ICPENDR0          (0x280ul)
#define OSINTC_GICR_ISACTIVER0        (0x300ul)
#define OSINTC_GICR_ICACTIVER0        (0x380ul)
#define OSINTC_GICR_IPRIORITYR0       (0x400ul) /*0 - 7, 400 41c */
#define OSINTC_GICR_ICFGR0            (0xc00ul)
#define OSINTC_GICR_ICFGR1            (0xc04ul)

#define OSINTC_CORE_OFFSET                0x20000



/*
 * OS interface to GIC
 */

/*
 * Convert from low number value means low prio to
 * low number value means high prio - the way NVIC works
 *
 * 0x00 means 0xFF in hw - this level will never generate an interrupt (>= in basepri)
 */

/* these values to be used only through conversion macros */
#define OSINTC_GIC_MIN_PRIO                0x00u
#define OSINTC_GIC_MAX_PRIO                0xFFu

#define OSINTC_GIC_CONVERT_PRIO_SET(prio)  ((((prio) & 0x1Fu) ^ 0x1Fu) << OSINTC_GIC_PRIO_SHIFT)
#define OSINTC_GIC_CONVERT_PRIO_GET(prio)  ((((prio) & 0xF8u) ^ 0xF8u) >> OSINTC_GIC_PRIO_SHIFT)

#define OSINTC_GIC_ROUTE_INTX(intId, target) {                                           \
    if ((intId) > 31) {                                                                  \
        uint32_t reg_adr = OSINTC_GIC_GET_BASE + OSINTC_GICD_IROUTER32 + ((intId) << 3);  \
        OSREG32(reg_adr) = 0;                                                            \
        OSREG32(reg_adr) = ((target) & 0x7);                                             \
    }                                                                                    \
}

#define OSINTC_GIC_GROUP_INTX(intId, group) {                                            \
    uint32_t reg_adr = OSINTC_GIC_GET_BASE;    /* get base address */                     \
    if ((intId) < 32) {                                                                  \
        reg_adr += (OSINTC_GICR_PPI_0 +                                                    \
             + OSINTC_GICR_IGROUPR0);                                                    \
    }                                                                                    \
    else {                                                                               \
        reg_adr += (OSINTC_GICD_OFFSET + OSINTC_GICD_IGROUPR1 + (((intId) >> 5) << 2));  \
    }                                                                                    \
    if (!(group)) {                                                                      \
        OSREG32(reg_adr) &= ~(1 << ((intId) & 31));                                      \
    }                                                                                    \
    else {                                                                               \
        OSREG32(reg_adr) |= (1 << ((intId) & 31));                                       \
    }                                                                                    \
}

#define OSINTC_GIC_CONFIG_INTX(intId, cfg) {                                             \
    uint32_t reg_adr = OSINTC_GIC_GET_BASE;    /* get base address */                     \
    if ((intId) < 32) {                                                                  \
        reg_adr += (OSINTC_GICR_PPI_0 +           \
             OSINTC_GICR_ICFGR0 + (((intId) >> 4) << 2));                                \
    }                                                                                    \
    else {                                                                               \
        reg_adr += (OSINTC_GICD_OFFSET + OSINTC_GICD_ICFGR2 + (((intId) >> 4) << 2));    \
    }                                                                                    \
    OSREG32(reg_adr) &= ~(3 << (((intId) & 15) << 1));                                   \
    OSREG32(reg_adr) |= (((cfg) & 2) << (((intId) & 15) << 1));                          \
}
/* enable  interrupt X */
/* PPI, SGI id => reg depends on target, core and cluster */
/* SPI id => reg = GICD_ISENABLER1 + ((id / 32) * 4) alligned address, id = id % 32 */
#define OSINTC_GIC_ENABLE_INTX(id)          {                                            \
    uint32_t reg_adr = OSINTC_GIC_GET_BASE;    /* get base address */                     \
    if ((id) < 32) {                                                                     \
        reg_adr += (OSINTC_GICR_PPI_0                   \
                    + OSINTC_GICR_ISENABLER0);                                           \
    }                                                                                    \
    else {                                                                               \
        reg_adr += (OSINTC_GICD_OFFSET + OSINTC_GICD_ISENABLER1 + (((id) >> 5) << 2));   \
    }                                                                                    \
    OSREG32(reg_adr) = (1 << ((id) & 31));                                               \
}

/* disable interrupt X */
#define OSINTC_GIC_DISABLE_INTX(id) {                                                    \
    uint32_t reg_adr = OSINTC_GIC_GET_BASE;    /* get base address */                     \
    if (id < 32) {                                                                       \
        reg_adr += (OSINTC_GICR_PPI_0                    \
                    + OSINTC_GICR_ICENABLER0);                                           \
        while (OSREG32(reg_adr - OSINTC_GICR_ICENABLER0) & OSINTC_R_RWP) {};             \
    }                                                                                    \
    else {                                                                               \
        while (OSREG32(reg_adr + OSINTC_GICD_OFFSET) & OSINTC_D_RWP) {};                 \
        reg_adr += (OSINTC_GICD_OFFSET + OSINTC_GICD_ICENABLER1 + ((id >> 5) << 2));     \
    }                                                                                    \
    OSREG32(reg_adr) = (1ul << (id & 31));                                               \
}

/* fast version */
/* set   interrupt pending X */
#define OSINTC_GIC_SET_PENDING_INTX(id) {                                                \
    uint32_t reg_adr = OSINTC_GIC_GET_BASE;    /* get base address */                     \
    if (id < 32) {                                                                       \
        reg_adr += (OSINTC_GICR_PPI_0                   \
                    + OSINTC_GICR_ISPENDR0);                                             \
    }                                                                                    \
    else {                                                                               \
        reg_adr += (OSINTC_GICD_OFFSET + OSINTC_GICD_ISPENDR1 + ((id >> 5) << 2));       \
    }                                                                                    \
    OSREG32(reg_adr) = (1 << (id & 31));                                                 \
}

/* clear interrupt pending X */
#define OSINTC_GIC_CLEAR_PENDING_INTX(id) {                                              \
    uint32_t reg_adr = OSINTC_GIC_GET_BASE;    /* get base address */                     \
    if (id < 32) {                                                                       \
        reg_adr += (OSINTC_GICR_PPI_0                   \
                    + OSINTC_GICR_ICPENDR0);                                             \
    }                                                                                    \
    else {                                                                               \
        reg_adr += (OSINTC_GICD_OFFSET + OSINTC_GICD_ICPENDR1 + ((id >> 5) << 2));       \
    }                                                                                    \
    OSREG32(reg_adr) = (1 << (id & 31));                                                 \
}

/* interrupt X PENDING status  */
#define OSINTC_GIC_PENDING_STATUS_INTX(id) {                                             \
    (((id) < 32) ?                                                                       \
        ((OSREG32(OSINTC_GIC_GET_BASE + OSINTC_GICR_PPI_0 +                              \
        OSINTC_GICR_ICPENDR0) >> ((id) & 31ul)) & 1ul) :          \
        ((OSREG32(OSINTC_GIC_GET_BASE + OSINTC_GICD_OFFSET + OSINTC_GICD_ICPENDR1 + ((id >> 5) << 2))    \
        >> ((id) & 31ul)) & 1ul) )                                                       \
}

/* interrupt X ACTIVE status  */
#define OSINTC_GIC_ACTIVE_STATUS_INTX(id) {                                              \
    (((id) < 32) ?                                                                       \
        ((OSREG32(OSINTC_GIC_GET_BASE + OSINTC_GICR_PPI_0 +        \
        OSINTC_GICR_ICACTIVER0) >> ((id) & 31ul)) & 1ul) :     \
        ((OSREG32(OSINTC_GIC_GET_BASE + OSINTC_GICD_OFFSET + OSINTC_GICD_ICACTIVER1 + ((id >> 5) << 2))   \
        >> ((id) & 31ul)) & 1ul) )                                                       \
}

/* interrupt X PENDING or ACTIVE status  */
#define OSINTC_GIC_PEND_OR_ACTIVE_STATUS_INTX(id) (OSINTC_GIC_PENDING_STATUS_INTX(id) || OSINTC_GIC_ACTIVE_STATUS_INTX(id))

/* set interrupt priority */
#define OSINTC_SET_PRIO_INTX(id, val) {                                                  \
    uint32_t reg_adr = OSINTC_GIC_GET_BASE;    /* get base address */                     \
    uint32_t reg_val = 0ul;                                                               \
    if ((id) < 32) {                                                                     \
        reg_adr += OSINTC_GICR_PPI_0 + (OSINTC_GICR_IPRIORITYR0 + ((id) & ~(3ul)));         \
    }                                                                                    \
    else {                                                                               \
        reg_adr += (OSINTC_GICD_IPRIORITYR8 + ((id) & ~(3ul)));                          \
    }                                                                                    \
    reg_val = OSREG32(reg_adr);                                                          \
    reg_val &= ~((0xfful) << (8 * ((id) & 3)));                                          \
    reg_val |= ((val) << (8 * ((id) & 3)));                                              \
    OSREG32(reg_adr) = reg_val;                                                          \
}

#define SET_GIC_GROUP(group, val) {   /* enable / disable FIQ0, IRQ1 signal */           \
    uint32_t reg_adr = OSINTC_GIC_GET_BASE;    /* get base address */                     \
    while (OSREG32(reg_adr + OSINTC_GICD_OFFSET) & OSINTC_D_RWP) {};                     \
    if (!(val)) {                                                                        \
        if (OSINTC_D_GROUP_0 == (group)) {                                               \
            OSREG32(reg_adr + OSINTC_GICD_OFFSET) &= ~OSINTC_D_GROUP_0;                  \
        }                                                                                \
        else if (OSINTC_D_GROUP_1 == (group)){                                           \
            OSREG32(reg_adr + OSINTC_GICD_OFFSET) &= ~OSINTC_D_GROUP_1;                  \
        }                                                                                \
        else { /* to prevent the misra violation - rule 14.8 */ }                        \
    }                                                                                    \
    else {                                                                               \
        if (OSINTC_D_GROUP_0 == (group)) {                                               \
            OSREG32(reg_adr + OSINTC_GICD_OFFSET) |= OSINTC_D_GROUP_0;                   \
        }                                                                                \
        else if (OSINTC_D_GROUP_1 == (group)){                                           \
            OSREG32(reg_adr + OSINTC_GICD_OFFSET) |= OSINTC_D_GROUP_1;                   \
        }                                                                                \
        else { /* to prevent the misra violation - rule 14.8 */ }                        \
    }                                                                                    \
}

#define GET_GIC_GROUPS_STATUS  (OSREG32(OSINTC_GIC_GET_BASE +  OSINTC_GICD_OFFSET) & (OSINTC_D_GROUP_0  | OSINTC_D_GROUP_1))

#define WAKE_UP_PE {                                                                            \
    uint32_t reg_adr = OSINTC_GIC_GET_BASE + OSINTC_GICR_CTRL_0;    /* get base address */       \
    reg_adr += (OSINTC_GICR_WAKER);                                                                     \
    OSREG32(reg_adr) &= ~OSINTC_PROC_SLEEP;                                                     \
    while (OSREG32(reg_adr) & OSINTC_CLD_ASLEEP) {};                                            \
}

/* CPU INTERFACE */
#define OSINTC_GET_ICC_IAR0 __MRC(15, 0, 12, 8, 0)
#define OSINTC_GET_ICC_IAR1 __MRC(15, 0, 12, 12, 0)
#define OSINTC_SET_ICC_EOIR0(id) __MCR(15, 0, (id), 12, 8, 1)
#define OSINTC_SET_ICC_EOIR1(id) __MCR(15, 0, (id), 12, 12, 1)
#define OSINTC_GET_ICC_BPR0 __MRC(15, 0, 12, 8, 3)
#define OSINTC_SET_ICC_BPR0(val) __MCR(15, 0, ((val) & 7), 12, 8, 3)
#define OSINTC_GET_ICC_BPR1 __MRC(15, 0, 12, 12, 3)
#define OSINTC_SET_ICC_BPR1(val) __MCR(15, 0, ((val) & 7), 12, 12, 3)
#define OSINTC_SET_ICC_DIR(val) __MCR(15, 0, (val), 12, 11, 1)
#define OSINTC_SET_ICC_PMR(mask) __MCR(15, 0, mask, 4, 6, 0)
#define OSINTC_GET_ICC_PMR __MRC(15, 0, 4, 6, 0)
#define OSINTC_GET_INT_PRI_MASK OSINTC_GET_ICC_PMR
#define OSINTC_SET_INT_PRI_MASK(mask) OSINTC_SET_ICC_PMR(mask)
#define OSINTC_GET_ICC_RPR __MRC(15, 0, 12, 11, 3)
#define OSINTC_GET_ICC_CTRL __MRC(15, 0, 12, 12, 4)
#define OSINTC_SET_ICC_CTRL(val) __MCR(15, 0, (val), 12, 12, 4)
#define OSINTC_GET_ICC_SRE __MRC(15, 0, 12, 12, 5)
#define OSINTC_SET_ICC_SRE __MCR(15, 0, (val), 12, 12, 5)
#define OSINTC_GET_ICC_HSRE __MRC(15, 4, 12, 9, 5)
#define OSINTC_SET_ICC_HSRE(val) __MCR(15, 4, (val), 12, 9, 5)
#define OSINTC_GET_ICC_GRPEN0 __MRC(15, 0, 12, 12, 6)
#define OSINTC_SET_ICC_GRPEN0(val) __MCR(15, 0, (val), 12, 12, 6)
#define OSINTC_GET_ICC_GRPEN1 __MRC(15, 0, 12, 12, 7)
#define OSINTC_SET_ICC_GRPEN1(val) __MCR(15, 0, (val), 12, 12, 7)
#define OSINTC_SET_ICC_SGI0R(id, target) __MCRR(15, 2, ((((unsigned long long int)(id)) << 24) | (target)), 0, 12)
#define OSINTC_SET_ICC_SGI1R(id, target) __MCRR(15, 0, ((((unsigned long long int)(id)) << 24) | (target)), 0, 12)
#define OSINTC_SET_ICC_ASGI1R(id, target) __MCRR(15, 1, ((((unsigned long long int)(id)) << 24) | (target)), 0, 12)

#define OSINTC_GET_ICC_AP0R0 __MRC(15, 0, 12, 12, 6)
#define OSINTC_SET_ICC_AP0R0(val) __MCR(15, 0, (val), 12, 8, 4)
#define OSINTC_GET_ICC_AP0R1 __MRC(15, 0, 12, 12, 7)
#define OSINTC_SET_ICC_AP0R1(val) __MCR(15, 0, (val), 12, 9, 0)


/* timer support routines */
#define SYSTYMER_GET_CNTFRQ __MRC(15, 0, 14, 0, 0)
#define SYSTYMER_SET_CNTFRQ(val) __MCR(15, 0, (val), 14, 0, 0)
#define SYSTIMER_GET_CNTPCT __MRRC(15, 0, 14)
#define SYSTIMER_GET_CNTKCTL __MRC(15, 0, 14, 1, 0)
#define SYSTIMER_SET_CNTKCTL(val) __MCR(15, 0, (val), 14, 1, 0)
#define SYSTIMER_GET_CNTP_TVAL __MRC(15, 0, 14, 2, 0)
#define SYSTIMER_SET_CNTP_TVAL(val) __MCR(15, 0, (val), 14, 2, 0)
#define SYSTIMER_GET_CNTP_CTL __MRC(15, 0, 14, 2, 1)
#define SYSTIMER_SET_CNTP_CTL(val) __MCR(15, 0, (val), 14, 2, 1)
#define SYSTIMER_GET_CNTV_TVAL __MRC(15, 0, 14, 3, 0)
#define SYSTIMER_SET_CNTV_TVAL(val) __MCR(15, 0, (val), 14, 3, 0)
#define SYSTIMER_GET_CNTV_CTL __MRC(15, 0, 14, 3, 1)
#define SYSTIMER_SET_CNTV_CTL(val) __MCR(15, 0, (val), 14, 3, 1)
#define SYSTIMER_GET_CNTVCT __MRRC(15, 1, 14)
#define SYSTIMER_GET_CNTP_CVAL __MRRC(15, 2, 14)
#define SYSTIMER_SET_CNTP_CVAL(val, val2) __MCRR(15, 2, (val), (val2), 14)
#define SYSTIMER_GET_CNTV_CVAL __MRRC(15, 3, 14)
#define SYSTIMER_SET_CNTV_CVAL(val, val2) __MCRR(15, 3, (val), (val2), 14)
#define SYSTIMER_GET_CNTVOFF __MRRC(15, 4, 14)
#define SYSTIMER_SET_CNTVOFF(val, val2) __MCRR(15, 4, (val), (val2), 14)
#define SYSTIMER_GET_CNTHCTL __MRC(15, 4, 14, 1, 0)
#define SYSTIMER_SET_CNTHCTL(val) __MCR(15, 4, (val), 14, 1, 0)
#define SYSTIMER_GET_CNTHP_TVAL __MRC(15, 4, 14, 2, 0)
#define SYSTIMER_SET_CNTHP_TVAL(val) __MCR(15, 4, (val), 14, 2, 0)
#define SYSTIMER_GET_CNTHP_CTL __MRC(15, 4, 14, 2, 1)
#define SYSTIMER_SET_CNTHP_CTL(val) __MCR(15, 4, (val), 14, 2, 1)
#define SYSTIMER_GET_CNTHP_CVAL __MRRC(15, 6, 14)
#define SYSTIMER_SET_CNTHP_CVAL(val, val2) __MCRR(15, 6, (val), (val2), 14)

/*
CNTP_CTL, Counter-timer Physical Timer Control register fields
*/
#define ENABLE                  (1 << 0)
#define IMASK                   (1 << 1)
#define ISTATUS                 (1 << 2)

typedef struct
{
    int m_TimerId;
    int m_ChannelId;
    int m_Val;
    int m_Div;
} TimerCfg_t;

typedef struct
{
    void* mp_Handler;
    int m_Priority;
} InterruptCfg_t;


extern void vGicEnableInterrupt(int, int);
extern void vGicInit(void);
extern void vUpdateTimer(void);
extern void prvSetupTimerInterrupt(void);
extern void vInitInterruptTable(int, void*);
extern void vSetupStm(TimerCfg_t*, InterruptCfg_t*);

#ifdef __cplusplus
}
#endif

#endif /** HW_SYSTEM_H */