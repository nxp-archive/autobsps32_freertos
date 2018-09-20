#
#  Copyright 2018 NXP
#

CORE_LIST := z4a z4b z2a

ifeq ($(filter $(CORE),$(CORE_LIST)),)
    $(error Undefined CORE: '$(CORE)', use one from: $(CORE_LIST))
endif

ifeq ("$(CORE)","z4a")
core_master := 1
core_id := 0
endif

ifeq ("$(CORE)","z4b")
core_master := 0
core_id := 1
endif

ifeq ("$(CORE)","z2a")
core_master := 0
core_id := 2
endif

export core_master
export core_id
