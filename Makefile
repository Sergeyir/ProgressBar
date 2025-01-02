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
.PHONY: all clean PBar

.SILENT:

all: PBar

PBar: lib/PBar.o lib/libPBar.so

lib: 
	mkdir -p $@

lib/PBar.o: src/PBar.cpp | lib
	@$(ECHO) Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

lib/lib%.so: lib/%.o
	@$(ECHO) Building CXX shared library $@
	$(CXX) -shared -o $@ $<

clean: 
	@echo Cleaning
	rm -r lib

endif
