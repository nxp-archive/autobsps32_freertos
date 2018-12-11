/*
*   Copyright 2018 NXP
*/

#define START __start
#if defined(CORE_MASTER)
    #undefine HW_INIT
    #define __SP_INIT__ __SP_INIT0__
#else
    #define HW_INIT 1
    #define DEBUG_SECONDARY_CORE 1
    #define __SP_INIT__ __SP_INIT1__
#endif

#define MAIN main
#define IVPR_ADDR 1
#define _INIT 1
#define START_FROM_FLASH  1
#define I_CACHE  1
#define D_CACHE  1
#include "startup.s"
