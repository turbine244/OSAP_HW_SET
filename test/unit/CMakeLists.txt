# add every .cc file in UNIT_TEST_SOURCES
file(GLOB UNIT_TEST_SOURCES "*.cc")

# Make Unit Test file (name : UnitTests)
add_executable(UnitTests ${UNIT_TEST_SOURCES} ../lib/library_code.cc)

# c++ flags for coverage
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

#executable file linking 
target_link_libraries(UnitTests common_library ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} AvlTree Set)

# Test discovery
include(GoogleTest)
gtest_discover_tests(UnitTests)

# coverage print
add_custom_target(coverage
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/coverage

    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage
    
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/coverage gcov ../test/unit/CMakeFiles/UnitTests.dir/avltree_test

    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/coverage gcov ../test/unit/CMakeFiles/UnitTests.dir/do_erase_test

    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/coverage gcov ../test/unit/CMakeFiles/UnitTests.dir/do_insert_test

    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/coverage gcov ../test/unit/CMakeFiles/UnitTests.dir/get_root_test
  
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/coverage gcov ../test/unit/CMakeFiles/UnitTests.dir/get_size_test
  
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/coverage gcov ../test/unit/CMakeFiles/UnitTests.dir/return_depth_test
   
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/coverage gcov ../test/unit/CMakeFiles/UnitTests.dir/return_maximum_test
  
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR}/coverage gcov ../test/unit/CMakeFiles/UnitTests.dir/return_minimum_test

    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)