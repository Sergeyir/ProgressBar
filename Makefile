CURRENT_DIRECTORY=`pwd`

install: src/PBar.cpp
	mkdir lib ; g++ src/PBar.cpp -Wall -Werror -Wpedantic -pipe -O2 -fPIC -c -o lib/PBar.o && \
	ar rcs lib/libPBar.a lib/PBar.o && \
	g++ -shared -o lib/PBar.so lib/PBar.o

clean: 
	rm -rf lib/* \
	rm -rf examples/*.exe
