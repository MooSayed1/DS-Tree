CC := g++
CFLAGS := -std=c++11 -Wall -Wextra -g

SRC := main.cpp  User.cpp hashTable.cpp treeGram.cpp
OBJ := $(SRC:.cpp=.o)  # Object files

TARGET := main

# LIBS := -lraylib

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

