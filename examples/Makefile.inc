CXX=g++
CXX_COMMON_EXE=-Wall -Wpedantic -pipe -O2 -g -ldl

PBAR_LIB_DIR=../lib
PBAR_INCLUDE=-I../include
PBAR_LIB=-L $(PBAR_LIB_DIR) -Wl,-rpath,$(PBAR_LIB_DIR) -lPBar
