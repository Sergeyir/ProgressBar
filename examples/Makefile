# Set the shell.
SHELL=/usr/bin/env bash

# Include the configuration.
-include Makefile.inc

_mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
I := $(patsubst %/,%,$(dir $(_mkfile_path)))

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
	@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
     -nrRf $(firstword $(MAKEFILE_LIST)) \
     ECHO="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
ECHO = python3 $(I)/makefile_progress.py --stepno=$C --nsteps=$T
endif

# Rules without physical targets (secondary expansion for specific rules).
.SECONDEXPANSION:
.PHONY: all clean

.SILENT:

all: test style possibilities speed style handle_output

%: %.cpp
	@$(ECHO) Building CXX executable $@ 
	$(CXX) $< $(CXX_COMMON_EXE) -o $@ \
	$(PBAR_INCLUDE) $(PBAR_LIB) \
	&& chmod +x $@

clean: 
	@echo Cleaning: removing executables
	rm -rf test style possibilities speed style handle_output

endif
