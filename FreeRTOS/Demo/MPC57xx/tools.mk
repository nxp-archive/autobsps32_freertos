# Copyright 2017 NXP

# Check that CYGWIN_PATH is set
$(if $(CYGWIN_PATH),,$(error Path to Cygwin's bin directory is not. Please define CYGWIN_PATH in your computer's environment variables with the path using '/' as path separator and try again))

# Cygwin often used commands
CYGPATH := $(CYGWIN_PATH)/cygpath.exe
MKDIR   := $(CYGWIN_PATH)/mkdir.exe
RM      := $(CYGWIN_PATH)/rm.exe
ECHO    := $(CYGWIN_PATH)/echo.exe
FIND    := $(CYGWIN_PATH)/find.exe
SED     := $(CYGWIN_PATH)/sed.exe
