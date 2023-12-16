cmake_minimum_required(VERSION 3.5)

project(DS-Tree)

add_library(main_lib
	./AVLTree.cpp
	
)

add_executable(main
main.cpp

)
link_libraries(
	main
	PRIVATE 
	main_lib

)
