SHELL=/usr/bin/env bash

-include Makefile.inc

test_macros = test possibilities handle_output style mt speed

all: test possibilities handle_output style mt speed

$(test_macros): %: %.cpp
	$(CXX) $^ $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o $@.exe

clean: 
	rm *.exe
