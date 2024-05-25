install: src/ProgressBar.cpp
	g++ src/ProgressBar.cpp -O2 -pipe -fPIC -c -o lib/ProgressBar.o && \
	ar rcs lib/libProgressBar.a lib/ProgressBar.o && \
	g++ -shared -o lib/ProgressBar.so lib/ProgressBar.o

clean: 
	rm -rf lib/*
