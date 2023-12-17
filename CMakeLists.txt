cmake_minimum_required(VERSION 3.5)

project(DS-Tree)

add_library(main_lib
	./AVLTree.cpp
	DynamicArray.cpp
  hashTable.cpp
)

add_executable(main
main.cpp

)
target_compile_options(main_lib PRIVATE -std=c++11 -Wall -Wextra -pedantic)

target_compile_options(main PRIVATE -std=c++11 -Wall -Wextra -pedantic)

link_libraries(
	main
	PRIVATE 
	main_lib

)
