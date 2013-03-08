#
#
# Makefile for dxf_2D
#
#
#------------------------------dirs-----------------------------------

OBJ_DIR := ./obj
LIB_DIR := ./lib
TEST_DIR := ./test


# ------------------------------- compiler ---------------------------

CXX = g++


# --------------------------- compiler flags--------------------------

CXXFLAGS = -c -Wall -Werror -fpic


#-------------------------shared library flags -----------------------

SHLIB = -shared -o


# ----------------------- dynamic linking flags ----------------------

DYN_LINKFLAGS = -L. -Wall


# ------------------------- library dxf_2D.so ------------------------

LIB = libdxf_2D.so


#-------------------name of library at linking time -----------------

LINKLIB = -ldxf_2D 


# --------------------- library source cpp files ---------------------

LIB_CPP_SRCS := ./src/dxf_base.cpp \
		./src/dxf_circle.cpp \
		./src/dxf_line.cpp


# ----------------------- library object files -----------------------

LIB_OBJS = dxf_base.o dxf_circle.o dxf_line.o


# ------------------------ main output program -----------------------

MAIN = prog


# --------------------------- main cpp file --------------------------

MAIN_CPP = test/example.cpp


# -------------------------- main object file ------------------------

MAIN_OBJ = example.o


#-------------------------------- move -------------------------------

MV = mv


# ------------------------------ remove ------------------------------

RM = rm -f




all: run


run: $(MAIN)
	export LD_LIBRARY_PATH=$(LIB_DIR):$ LD_LIBRARY_PATH && ./$(MAIN)


$(MAIN): $(MAIN_OBJ) $(LIB)
	$(CXX) $(DYN_LINKFLAGS) -o $(MAIN) $(MAIN_OBJ) $(LINKLIB) && \
	$(MV) $(MAIN_OBJ) $(TEST_DIR) && \
	$(MV) $(LIB) $(LIB_DIR)


$(MAIN_OBJ): $(MAIN_CPP)
	$(CXX) -c $(MAIN_CPP) 


$(LIB): $(LIB_OBJS)
	$(CXX) $(SHLIB) $(LIB) $(LIB_OBJS) && \
	$(MV) $(LIB_OBJS) $(OBJ_DIR)


$(LIB_OBJS): $(LIB_CPP_SRCS)
	$(CXX) $(CXXFLAGS) $(LIB_CPP_SRCS) 


clean:
	$(RM) *.o temp



