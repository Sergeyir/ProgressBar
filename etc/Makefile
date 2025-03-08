# Set the shell.
SHELL=/usr/bin/env bash

# Include the configuration.
-include Makefile.inc

# Rules without physical targets (secondary expansion for specific rules).
.SECONDEXPANSION:
.PHONY: all clean

.SILENT:

all: PBar test style possibilities speed handle_output mt

PBar: lib/libPBar.so
test: bin/test
style: bin/style
possibilities: bin/possibilities
speed: bin/speed
handle_output: bin/handle_output
mt: bin/mt

lib: 
	mkdir -p $@

lib/PBar.o: src/PBar.cpp | lib
	@echo Building CXX object $@
	$(CXX) $< $(CXX_COMMON_LIB) -o $@

lib/lib%.so: lib/%.o
	@echo Building CXX shared library $@
	$(CXX) -shared -o $@ $<

bin/%: examples/%.cpp PBar
	@echo Building CXX executable $@ 
	$(CXX) $< $(CXX_COMMON_EXE) -o $@ \
	$(PBAR_INCLUDE) $(PBAR_LIB) \
	&& chmod +x $@

clean: 
	@echo Cleaning
	rm -r lib/*
