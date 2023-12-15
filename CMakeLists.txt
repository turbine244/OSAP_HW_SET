cmake_minimum_required(VERSION 3.13)
project(GoogleTestForProject)
set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

# Typedef 라이브러리 생성
add_library(AvlTree src/avltree.cc)

# Set 라이브러리 생성 (Set은 Typedef를 상속)
add_library(Set src/set.cc)
target_link_libraries(Set AvlTree)

add_subdirectory(test)
add_subdirectory(src)