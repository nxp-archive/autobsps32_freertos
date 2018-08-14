/*
*   Copyright 2018 NXP
*/

#include <string.h>

void CBootstrap(void) __attribute__ ((section (".startup")));

void CBootstrap(void)
{

    /* SBSS */
    extern  char * __sbss_start__;
    extern  char * __sbss_end__;

    /* SBSS */
    extern  char * __bss_start__;
    extern  char * __bss_end__;

    memset( (char*)&__sbss_start__, 0x0, (size_t)((char*)&__sbss_end__ - (char*)&__sbss_start__) );
    memset( (char*)&__bss_start__,  0x0, (size_t)((char*)&__bss_end__  - (char*)&__bss_start__ ) );

    /* DATA */
    extern  char * __data_flash_start__;
    extern  char * __user_data_start__;

    /* SDATA */
    extern  char * __sdata_end__;

    memcpy((void *)&__user_data_start__,  /* DST */
           (const void *)&__data_flash_start__,  /* SRC */
           (size_t)((char*)&__sdata_end__ - (char*)&__user_data_start__) /* SIZE */);
}

