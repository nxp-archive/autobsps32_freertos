/*
*   Copyright 2018 NXP
*/

#define START __start
#if defined(CORE_MASTER)
    #undefine HW_INIT
    #define MAIN main
    #define IVPR_ADDR 1
#else
    #define HW_INIT 1
    #define MAIN loop
#endif

#define _INIT 1
#define START_FROM_FLASH  1
#define I_CACHE  1
#define D_CACHE  1
#define __SP_INIT__ __SP_INIT0__
#include "startup.s"
