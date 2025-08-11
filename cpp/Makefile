#targets:
TARGETNAME = $(shell basename -a $(wildcard ./src/*.cpp))
TESTNAME = $(basename $(TARGETNAME) .cpp)
#gcc:
CC = g++ 
#gcc flags:
CFLAGS = -std=c++11 -pedantic-errors -Wall -Wextra -fPIC
INCLUDE = -I ./inc
LDFLAGS = -lcpp -L $(DBG_DIR)/. -Wl,-rpath=$(DBG_DIR)/. -lm
DEBUG = -g
REL = -DNDEBUG -O3
#compiler:
GD := $(CC) $(CFLAGS) $(DEBUG) $(INCLUDE)
GC := $(CC) $(CFLAGS) $(REL) $(INCLUDE)
#dirs:
SRC_DIR = src
BIN_DIR = bin
DBG_DIR = bin/debug
DBG_OBJ_DIR = bin/debug/obj
REL_DIR = bin/release
REL_OBJ_DIR = bin/release/obj
TEST_DIR = bin/test
#files:
SOURCES =  $(wildcard $(SRC_DIR)/*.cpp)
DEBUG_OBJ = $(subst $(SRC_DIR),$(DBG_OBJ_DIR),$(SOURCES:.cpp=.o))
REL_OBJ = $(subst $(SRC_DIR),$(REL_OBJ_DIR),$(SOURCES:.cpp=.o))
#library
LIB = libcpp.so

.PHONY: debug release test clean all

#so:
all: debug release test
	
debug: $(DEBUG_OBJ)
	$(GD) -shared -o $(DBG_DIR)/$(LIB) $?

release: $(REL_OBJ)
	$(GC) -shared -o $(REL_DIR)/$(LIB) $?
	
#exe:	
test : debug $(TEST_OBJ) 
	$(foreach d, $(TESTNAME), $(GD) ./test/$d_test.cpp -o ./$d.out \
							    $(LDFLAGS);)

#obj:
$(REL_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(REL_OBJ_DIR)
	$(GC) -c -o $@ $<

$(DBG_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(DBG_OBJ_DIR)
	$(GD) -c -o $@ $<

clean: 
	rm -rf *.out ./$(DBG_OBJ_DIR) ./$(REL_OBJ_DIR) 

