#
#  Copyright 2018 NXP
#

# list MCU supported
mcu_list := s32r274 s32r372 s32r264 s32r294

ifeq ($(filter $(MCU),$(mcu_list)),)
    $(error Undefined MCU: '$(MCU)', use one from: $(mcu_list))
endif

include specific/$(MCU)/src_hw/core_config.mk
