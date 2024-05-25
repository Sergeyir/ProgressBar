-include Makefile.inc
test: test.cc
	$(CXX) test.cc $(CXX_FLAGS) $(PROGRESS_BAR_LIB) -o test.exe

style: style.cc
	$(CXX) style.cc $(CXX_FLAGS) $(PROGRESS_BAR_LIB) -o style.exe

mt: mt.cc
	$(CXX) mt.cc $(CXX_FLAGS) $(PROGRESS_BAR_LIB) -o mt.exe

speed: speed.cc
	$(CXX) speed.cc $(CXX_FLAGS) $(PROGRESS_BAR_LIB) -o speed.exe

clean: 
	rm *.exe
