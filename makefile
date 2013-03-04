#
#
# Makefile for dxf_2D
#
#

# ------------------------------- compiler ---------------------------
CXX = g++


# --------------------------- compiler flags--------------------------
CXXFLAGS = -c -Wall -Werror -fpic


# ----------------------- dynamic linking flags ----------------------
DYN_LINKFLAGS = -L. -Wall


# ----------------------- specify library path -----------------------
PATH := ~/testing


# ------------------------- library dxf_2D.so ------------------------
LIB = libdxf_2D.so


# --------------------- library source cpp files ---------------------
LIB_CPP_SRCS := $(PATH)/src/*.cpp


# ----------------------- library object files -----------------------
LIB_OBJS := $(PATH)/src/*.o 


# ------------------------ main output program -----------------------

MAIN = test


# --------------------------- main cpp file --------------------------
MAIN_CPP = example.cpp


# -------------------------- main object file ------------------------
MAIN_OBJ = example.o


# ------------------------------ remove ------------------------------
RM = rm -f



all:  run

run: $(MAIN)
	export LD_LIBRARY_PATH=$(PATH)/src:$ LD_LIBRARY_PATH && ./$(MAIN) 


$(MAIN): $(MAIN_OBJ) $(LIB)
	$(CXX) $(DYN_LINKFLAGS) -o $(MAIN) $(MAIN_OBJ) -ldxf_2D 


$(MAIN_OBJ): $(MAIN_CPP)
	$(CXX) -c $(MAIN_CPP)


$(LIB): $(LIB_OBJS)
	$(CXX) -shared -o $(LIB) $(LIB_OBJS) 


$(LIB_OBJS): $(LIB_CPP_SRCS)
	$(CXX) $(CXXFLAGS) $(LIB_CPP_SRCS)

clean:
	$(RM) *.o temp



