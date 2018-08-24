#
#  Copyright 2018 NXP
#

# list MCU supported
mcu_list := mpc5746c mpc5748g s32r274 s32r372 mpc5746r

ifeq ($(filter $(MCU),$(mcu_list)),)
    $(error Undefined MCU: '$(MCU)', use one from: $(mcu_list))
endif

include SOURCES_HARDWARE/$(MCU)/core_config.mk
