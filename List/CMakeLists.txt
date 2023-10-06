cmake_minimum_required(VERSION 3.10) 

project(List) 

project(List VERSION 1.0)  

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED True) 

configure_file(ListConfig.h.in ListConfig.h)  


add_executable(List main.cpp)

target_include_directories(List PUBLIC
                           "${PROJECT_BINARY_DIR}"
		   ) 

