ENTRY(__start)

HEAP_SIZE  = DEFINED(__heap_size__)  ? __heap_size__  : 0x0400;
STACK_SIZE = DEFINED(__stack_size__) ? __stack_size__ : 0x0400;

MEMORY
{
	VECTOR_region	(RX):	ORIGIN = 0x00000000, LENGTH = 0x00000410
	ROM_region		(RX):	ORIGIN = 0x00000410, LENGTH = 0x0007FBF0
	RAM_region		(RW):	ORIGIN = 0x1FFF0410, LENGTH = 0x0000FBF0
	RAM2_region		(RW):	ORIGIN = 0x20000000, LENGTH = 0x00010000
}

SECTIONS
{
	__VECTOR_TABLE = 0x00000000;
	__VECTOR_RAM = 0x1FFF0000;

	.intvec :
	{
		__vector_table = .;
		. = ALIGN (0x4);
        /* KEEP(*(.vectors_rom))
        . = ALIGN (0x4); */
	} > VECTOR_region

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
    } > ROM_region

	.ARM.extab :
	{
		*(.ARM.extab* .gnu.linkonce.armextab.*)
	} > ROM_region

	.ARM :
	{
		__exidx_start = .;
		*(.ARM.exidx*)
		__exidx_end = .;
	} > ROM_region

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
	} > ROM_region

	.dtors :
	{
		__DTOR_LIST__ = .;
		KEEP (*crtbegin.o(.dtors))
		KEEP (*crtbegin?.o(.dtors))
		KEEP (*(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
		__DTOR_END__ = .;
	} > ROM_region

	.preinit_array :
	{
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP (*(.preinit_array*))
		PROVIDE_HIDDEN (__preinit_array_end = .);
	} > ROM_region

	.init_array :
	{
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP (*(SORT(.init_array.*)))
		KEEP (*(.init_array*))
		PROVIDE_HIDDEN (__init_array_end = .);
	} > ROM_region

	.fini_array :
	{
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP (*(SORT(.fini_array.*)))
		KEEP (*(.fini_array*))
		PROVIDE_HIDDEN (__fini_array_end = .);
	} > ROM_region

	__DATA_ROM = .;

	.data : AT(__DATA_ROM)
	{
		. = ALIGN(4);
		__DATA_RAM = .;
		__data_start__ = .;      /* create a global symbol at data start */
		*(.data)                 /* .data sections */
		*(.data*)                /* .data* sections */
		KEEP(*(.jcr*))
		. = ALIGN(4);
		__data_end__ = .;        /* define a global symbol at data end */
	} > RAM_region

	__DATA_END = __DATA_ROM + (__data_end__ - __data_start__);

	/* Uninitialized data section */
	.bss :
	{
		/* This is used by the startup in order to initialize the .bss section */
		. = ALIGN(4);
		__START_BSS = .;
		__bss_start__ = .;
		*(.bss)
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		__bss_end__ = .;
		__END_BSS = .;
	} > RAM_region

	.heap :
	{
		. = ALIGN(8);
		__end__ = .;
		PROVIDE(end = .);
		__HeapBase = .;
		. += HEAP_SIZE;
		__HeapLimit = .;
	} > RAM2_region

	.stack :
	{
		. = ALIGN(8);
		. += STACK_SIZE;
	} > RAM2_region

	__BOOT_STACK_ADDRESS = ORIGIN(RAM2_region) + LENGTH(RAM2_region);
	__StackLimit = __BOOT_STACK_ADDRESS - STACK_SIZE;
	PROVIDE(__stack = __BOOT_STACK_ADDRESS);

	.ARM.attributes 0 : { *(.ARM.attributes) }

	ASSERT(__StackLimit >= __HeapLimit, "RAM2_region overflowed with stack and heap")
}
