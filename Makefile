CC := g++
CFLAGS := -std=c++11 -Wall -Wextra -g
LDFLAGS :=  # Additional linker flags
PRODUCTION_CFLAGS := -O3 -DNDEBUG  # Production-specific flags

SRC := main.cpp AVLTree.cpp User.cpp hashTable.cpp treeGram.cpp
OBJ := $(SRC:.cpp=.o) 

TARGET := main

# LIBS := -lraylib

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

production: CFLAGS += $(PRODUCTION_CFLAGS)
production: clean all

clean:
	rm -f $(TARGET) $(OBJ)

