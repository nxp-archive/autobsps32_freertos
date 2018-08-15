/*
*   Copyright 2018 NXP
*/

#include "hw_base.h"

extern void __start(void);

#define RCHWDATA __attribute__((section(".rchwdata")))

RCHWDATA_Init();
