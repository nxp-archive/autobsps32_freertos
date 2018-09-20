#
#  Copyright 2018 NXP
#

CORE_LIST := z4a

ifeq ($(filter $(CORE),$(CORE_LIST)),)
    $(error Undefined CORE: '$(CORE)', use one from: $(CORE_LIST))
endif

ifeq ("$(CORE)","z4a")
core_master := 1
core_id := 0
endif

export core_master
export core_id
