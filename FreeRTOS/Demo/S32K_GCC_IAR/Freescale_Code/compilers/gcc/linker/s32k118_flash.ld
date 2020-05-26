
/* Entry Point */
ENTRY(Reset_Handler)
/*
To use "new" operator with EWL in C++ project the following symbol shall be defined
*/
/*EXTERN(_ZN10__cxxabiv119__terminate_handlerE)*/

HEAP_SIZE  = DEFINED(__heap_size__)  ? __heap_size__  : 0x00000400;
STACK_SIZE = DEFINED(__stack_size__) ? __stack_size__ : 0x00000400;

/* If symbol __flash_vector_table__=1 is defined at link time
 * the interrupt vector will not be copied to RAM.
 * Warning: Using the interrupt vector from Flash will not allow
 * INT_SYS_InstallHandler because the section is Read Only.
 */
M_VECTOR_RAM_SIZE = DEFINED(__flash_vector_table__) ? 0x0 : 0x00C0;

/* Specify the memory areas */
MEMORY
{
    /* Flash */
    m_interrupts          (RX)  : ORIGIN = 0x00000000, LENGTH = 0x00000400
    m_flash_config        (RX)  : ORIGIN = 0x00000400, LENGTH = 0x00000010
    m_text                (RX)  : ORIGIN = 0x00000410, LENGTH = 0x0003FBF0

    /* SRAM_L */

    /* SRAM_U */
    m_data                (RW)  : ORIGIN = 0x1ffffc00, LENGTH = 0x00002d80
    m_data_2              (RW)  : ORIGIN = 0x20002980, LENGTH = 0x00002d00
}

/* Define output sections */
SECTIONS
{

    .intvec :
    {
        __vector_table = .;
        __VECTOR_TABLE = .;
        . = ALIGN (0x4);
                /* KEEP(*(.vectors_rom))
                . = ALIGN (0x4); */
    } > m_interrupts

    .flash_config :
    {
        . = ALIGN(4);
        KEEP(*(.FlashConfig))    /* Flash Configuration Field (FCF) */
        . = ALIGN(4);
    } > m_flash_config

    /* The program code and other data goes into internal flash */
    .text :
    {
        . = ALIGN(4);
        *(.text)                 /* .text sections (code) */
        *(.text*)                /* .text* sections (code) */
        *(.rodata)               /* .rodata sections (constants, strings, etc.) */
        *(.rodata*)              /* .rodata* sections (constants, strings, etc.) */
        *(.glue_7)               /* glue arm to thumb code */
        *(.glue_7t)              /* glue thumb to arm code */
        *(.eh_frame)
        KEEP (*(.init))
        KEEP (*(.fini))
        . = ALIGN(4);
    } > m_text

    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > m_text

    .ARM :
    {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } > m_text

    .ctors :
    {
        __CTOR_LIST__ = .;
        /* gcc uses crtbegin.o to find the start of
             the constructors, so we make sure it is
             first.  Because this is a wildcard, it
             doesn't matter if the user does not
             actually link against crtbegin.o; the
             linker won't look for a file to match a
             wildcard.  The wildcard also means that it
             doesn't matter which directory crtbegin.o
             is in.  */
        KEEP (*crtbegin.o(.ctors))
        KEEP (*crtbegin?.o(.ctors))
        /* We don't want to include the .ctor section from
             from the crtend.o file until after the sorted ctors.
             The .ctor section from the crtend file contains the
             end of ctors marker and it must be last */
        KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*(.ctors))
        __CTOR_END__ = .;
    } > m_text

    .dtors :
    {
        __DTOR_LIST__ = .;
        KEEP (*crtbegin.o(.dtors))
        KEEP (*crtbegin?.o(.dtors))
        KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*(.dtors))
        __DTOR_END__ = .;
    } > m_text

    .preinit_array :
    {
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP (*(.preinit_array*))
        PROVIDE_HIDDEN (__preinit_array_end = .);
    } > m_text

    .init_array :
    {
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array*))
        PROVIDE_HIDDEN (__init_array_end = .);
    } > m_text

    .fini_array :
    {
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP (*(SORT(.fini_array.*)))
        KEEP (*(.fini_array*))
        PROVIDE_HIDDEN (__fini_array_end = .);
    } > m_text

    __etext = .;    /* Define a global symbol at end of code. */
    __DATA_ROM = .; /* Symbol is used by startup for data initialization. */
    .interrupts_ram :
    {
        . = ALIGN(4);
        __VECTOR_RAM__ = .;
        __RAM_START = .;
        __interrupts_ram_start__ = .; /* Create a global symbol at data start. */
        *(.m_interrupts_ram)          /* This is a user defined section. */
        . += M_VECTOR_RAM_SIZE;
        . = ALIGN(4);
        __interrupts_ram_end__ = .;   /* Define a global symbol at data end. */
    } > m_data

    __VECTOR_RAM = DEFINED(__flash_vector_table__) ? ORIGIN(m_interrupts) : __VECTOR_RAM__ ;
    __RAM_VECTOR_TABLE_SIZE = DEFINED(__flash_vector_table__) ? 0x0 : (__interrupts_ram_end__ - __interrupts_ram_start__) ;

    .data : AT(__DATA_ROM)
    {
        . = ALIGN(4);
        __DATA_RAM = .;
        __data_start__ = .;      /* Create a global symbol at data start. */
        *(.data)                 /* .data sections */
        *(.data*)                /* .data* sections */
        KEEP(*(.jcr*))
        . = ALIGN(4);
        __data_end__ = .;        /* Define a global symbol at data end. */
    } > m_data

    __DATA_END = __DATA_ROM + (__data_end__ - __data_start__);
    __CODE_ROM = __DATA_END; /* Symbol is used by code initialization. */
    .code : AT(__CODE_ROM)
    {
        . = ALIGN(4);
        __CODE_RAM = .;
        __code_start__ = .;      /* Create a global symbol at code start. */
        __code_ram_start__ = .;
        *(.code_ram)             /* Custom section for storing code in RAM */
        . = ALIGN(4);
        __code_end__ = .;        /* Define a global symbol at code end. */
        __code_ram_end__ = .;
    } > m_data

    __CODE_END = __CODE_ROM + (__code_end__ - __code_start__);

    /* Custom Section Block that can be used to place data at absolute address. */
    /* Use __attribute__((section (".customSection"))) to place data here. */
    .customSectionBlock  ORIGIN(m_data_2) :
    {
        __customSection_start__ = .;
        KEEP(*(.customSection))  /* Keep section even if not referenced. */
        __customSection_end__ = .;
    } > m_data_2

    /* Uninitialized data section. */
    .bss :
    {
        /* This is used by the startup in order to initialize the .bss section. */
        . = ALIGN(4);
        __START_BSS = .;
        __SP_INIT = .;
        __bss_start__ = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end__ = .;
        __END_BSS = .;
    } > m_data_2

    /* Initializes stack on the end of block */

        .heap (COPY):
        {
                __HeapBase = .;
                __end__ = .;
                end = __end__;
                KEEP(*(.heap*))
                __HeapLimit = .;
        } > m_data_2

        __stack_end__ = .;

    .stack :
    {
        . = ALIGN(8);
        __stack_start__ = .;
        . += STACK_SIZE;
    } > m_data_2

    __StackTop = ORIGIN(m_data_2) + LENGTH(m_data_2);
    __BOOT_STACK_ADDRESS = __StackTop;
    __StackLimit = __BOOT_STACK_ADDRESS - STACK_SIZE;

    PROVIDE(__stack = __StackTop);
    __RAM_END = __StackTop;
    .ARM.attributes 0 : { *(.ARM.attributes) }

}
