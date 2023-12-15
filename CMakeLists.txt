#minimum version of cmake
cmake_minimum_required(VERSION 3.13)

#project name
project(GoogleTestForProject)

#use c++11
set(CMAKE_CXX_STANDARD 11)

#c++ flags for coverage
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

#google test library import
find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

# avltree library 
add_library(AvlTree src/avltree.cc)

# set library (inherit avltree class)
add_library(Set src/set.cc)
target_link_libraries(Set AvlTree)

#make subdirectory
add_subdirectory(test)
add_subdirectory(src)
