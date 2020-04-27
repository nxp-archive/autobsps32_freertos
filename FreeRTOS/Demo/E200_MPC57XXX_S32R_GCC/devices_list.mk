#
#  Copyright 2018 NXP
#

# list MCU supported
mcu_list := mpc5744p mpc5746c mpc5746r mpc5748g mpc5777c s32r274 s32r372 s32r264

ifeq ($(filter $(MCU),$(mcu_list)),)
    $(error Undefined MCU: '$(MCU)', use one from: $(mcu_list))
endif

include specific/$(MCU)/src_hw/core_config.mk
