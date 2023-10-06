cmake_minimum_required(VERSION 3.10) 

project(LinkedList) 

project(LinkedList VERSION 1.0)  

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True) 

configure_file(LinkedListConfig.h.in LinkedListConfig.h)  


add_executable(LinkedList main.cpp)

target_include_directories(LinkedList PUBLIC
                           "${PROJECT_BINARY_DIR}"
		   ) 

