CXX=g++
CXX_COMMON_LIB=-Wall -Werror -Wpedantic -pipe -O2 -fPIC -c

PBAR_LIB_DIR=`pwd`/lib
PBAR_INCLUDE=-I`pwd`/include
PBAR_LIB=-L $(PBAR_LIB_DIR) -Wl,-rpath,$(PBAR_LIB_DIR) -lPBar
