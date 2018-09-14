/*
*   Copyright 2018 NXP
*/

#if defined(CORE_SLAVE)
#define START __startSlave
#define MAIN main
#define DEBUG_SECONDARY_CORE 1
#define IVPR_ADDR 1
#define I_CACHE  1
#define D_CACHE  1
#define __SP_INIT__ __SP_INIT1__
#include "startup.s"
#endif
