/*
*   Copyright 2018 NXP
*/

.global __start

.extern __IVPR_ADDR          /* address base used for IVPR register */

/* load immediate word, 2 instructions needed */
.macro e_lwi reg,val
    e_lis       \reg,\val@H
    e_or2i      \reg,\val@L
.endm

.section .startup, "ax"
.type __start, %function
;# Reset vector must be 4 byte aligned
.align 2
__start:

;# disable SWTA
    e_lis   r4, 0xFFF3
    e_or2i  r4, 0x8000

    e_li    r3, 0xC520
    e_stw   r3, 0x10(r4)

    e_li    r3, 0xD928
    e_stw   r3, 0x10(r4)

    e_lis   r3, 0xFF00
    e_or2i  r3, 0x010A
    e_stw   r3, 0(r4)

;#*********************** Turn off Core Watchdog Timer*************************
        e_li    r3, 0x0000
        mtspr   340, r3

;#********************************* Enable BTB ********************************
;# Flush & Enable BTB - Set BBFI bit in BUCSR
        e_li    r3, 0x201
        mtspr   1013, r3
        se_isync

;#***************************** Init Core Registers *****************************
    /* GPRs 0-31 */
    e_li        r0, 0
    e_li        r1, 0
    e_li        r2, 0
    e_li        r3, 0
    e_li        r4, 0
    e_li        r5, 0
    e_li        r6, 0
    e_li        r7, 0
    e_li        r8, 0
    e_li        r9, 0
    e_li        r10, 0
    e_li        r11, 0
    e_li        r12, 0
    e_li        r13, 0
    e_li        r14, 0
    e_li        r15, 0
    e_li        r16, 0
    e_li        r17, 0
    e_li        r18, 0
    e_li        r19, 0
    e_li        r20, 0
    e_li        r21, 0
    e_li        r22, 0
    e_li        r23, 0
    e_li        r24, 0
    e_li        r25, 0
    e_li        r26, 0
    e_li        r27, 0
    e_li        r28, 0
    e_li        r29, 0
    e_li        r30, 0
    e_li        r31, 0

    /* Init any other CPU register which might be stacked (before being used). */
    mtspr       1, r1       ;#XER
    mtcrf       0xFF, r1
    mtspr       CTR, r1
    mtspr       272, r1     ;#SPRG0
    mtspr       273, r1     ;#SPRG1
    mtspr       274, r1     ;#SPRG2
    mtspr       275, r1     ;#SPRG3
    mtspr       58, r1      ;#CSRR0
    mtspr       59, r1      ;#CSRR1
    mtspr       570, r1     ;#MCSRR0
    mtspr       571, r1     ;#MCSRR1
    mtspr       61, r1      ;#DEAR
    mtspr       63, r1      ;#IVPR
    mtspr       256, r1     ;#USPRG0
    mtspr       62, r1      ;#ESR
    mtspr       8,r31       ;#LR

;#***************************** Initialise SRAM ECC *****************************
;# Store number of 128Byte (32GPRs) segments in Counter
    e_lwi       r5, __SRAM_SIZE # Initialize r5 to size of SRAM (Bytes)
    e_srwi      r5, r5, 0x7     # Divide SRAM size by 128
    mtctr       r5              # Move to counter for use with "bdnz"

    # Base Address of the internal SRAM
    e_lwi       r5, __SRAM_BASE_ADDR

;# Fill SRAM with writes of 32GPRs
sram_loop:
    e_stmw      r0,0(r5)    # Write all 32 registers to SRAM
    e_addi      r5,r5,128   # Increment the RAM pointer to next 128bytes
    e_bdnz      sram_loop   # Loop for all of SRAM

;#*************************** Enable ME Bit in MSR *****************************
    mfmsr   r6
    e_or2i  r6,0x1000
    mtmsr   r6

;#*************************** Enable SPE Bit in MSR *****************************
    mfmsr r3
    e_or2is r3,0x0200
    mtmsr r3

;#****************** Invalidate and Enable the Instruction cache **************
__icache_cfg:
    e_li    r5, 0x2
    mtspr   1011,r5

    e_li    r7, 0x4
    e_li    r8, 0x2
    e_lis   r11,0xFFFF
    e_or2i  r11,0xFFFB

__icache_inv:
    mfspr   r9, 1011
    and.    r10, r7, r9
    e_beq   __icache_no_abort
    and.    r10, r11, r9
    mtspr   1011, r10
    e_b     __icache_cfg

__icache_no_abort:
    and.    r10, r8, r9
    e_bne   __icache_inv

    mfspr   r5, 1011
    e_ori   r5, r5, 0x0001
    se_isync
    mtspr   1011, r5

;#****************** Invalidate and Enable the Data cache **************
__dcache_cfg:
    e_li r5, 0x2
    mtspr 1010,r5

    e_li r7, 0x4
    e_li r8, 0x2
    e_lis   r11,0xFFFF
    e_or2i  r11,0xFFFB

__dcache_inv:
    mfspr r9, 1010
    and.  r10, r7, r9
    e_beq   __dcache_no_abort
    and.  r10, r11, r9
    mtspr 1010, r10
    e_b __dcache_cfg

__dcache_no_abort:
    and.  r10, r8, r9
    e_bne __dcache_inv

    mfspr r5, 1010
    e_ori   r5, r5, 0x0001
    se_isync
    msync
    mtspr 1010, r5

;#****************************** Configure Stack ********************************
    e_lwi       r1,  __SP_INIT__ ;# Initialize stack pointer r1 to value in linker command file.
    e_lwi       r13, _SDA_BASE_  ;# Initialize r13 to sdata base (provided by linker).
    e_lwi       r2,  _SDA2_BASE_ ;# Initialize r2 to sdata2 base (provided by linker).

    e_li        r0, 0xFFFF@l /* load up r0 with 0xFFFFFFFF */
    e_stwu      r0,-8(r1)    /* Create a root frame header to terminate stack */
    e_stw       r0, 4(r1)    /* Make an illegal return address of 0xFFFFFFFF */
    e_stw       r0, 0(r1)    /* Make an illegal back chain address of 0xFFFFFFFF */

;#****************************** Interrupts setup *******************************
    e_lwi       r4, __IVPR_ADDR
    mtIVPR      r4

    e_add16i r3,r4, 0x0
    mtspr 400,r3
    e_add16i r3,r4, 0x10
    mtspr 401,r3
    e_add16i r3,r4, 0x20
    mtspr 402,r3
    e_add16i r3,r4, 0x30
    mtspr 403,r3
    e_add16i r3,r4, 0x40
    mtspr 404,r3
    e_add16i r3,r4, 0x50
    mtspr 405,r3
    e_add16i r3,r4, 0x60
    mtspr 406,r3
    e_add16i r3,r4, 0x70
    mtspr 407,r3
    e_add16i r3,r4, 0x80
    mtspr 408,r3
    e_add16i r3,r4, 0x90
    mtspr 409,r3
    e_add16i r3,r4, 0xA0
    mtspr 410,r3
    e_add16i r3,r4, 0xB0
    mtspr 411,r3
    e_add16i r3,r4, 0xC0
    mtspr 412,r3
    e_add16i r3,r4, 0xD0
    mtspr 413,r3
    e_add16i r3,r4, 0xE0
    mtspr 414,r3
    e_add16i r3,r4, 0xF0
    mtspr 415,r3

;#****************************** Prepare C environment **************************
    e_lwi       r3, CBootstrap
    mtlr        r3
    se_blrl

;#****************************** Jump to Main ***********************************
    e_b         main

.global __init
__init:
    se_blr
