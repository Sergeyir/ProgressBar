-include Makefile.inc
test: test.cpp
	$(CXX) test.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o test.exe

possibilities: possibilities.cpp
	$(CXX) possibilities.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o possibilities.exe

style: style.cpp
	$(CXX) style.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o style.exe

mt: mt.cpp
	$(CXX) mt.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o mt.exe

speed: speed.cpp
	$(CXX) speed.cpp $(CXX_FLAGS) $(PBAR_INCLUDE) $(PBAR_LIB) -o speed.exe

clean: 
	rm *.exe
