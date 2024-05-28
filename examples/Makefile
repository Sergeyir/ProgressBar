-include Makefile.inc
test: test.cpp
	$(CXX) test.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o test.exe

possibilities: possibilities.cpp
	$(CXX) possibilities.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o possibilities.exe

handle_output: handle_output.cpp
	$(CXX) handle_output.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o handle_output.exe

style: style.cpp
	$(CXX) style.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o style.exe

mt: mt.cpp
	$(CXX) mt.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o mt.exe

speed: speed.cpp
	$(CXX) speed.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o speed.exe

clean: 
	rm *.exe
