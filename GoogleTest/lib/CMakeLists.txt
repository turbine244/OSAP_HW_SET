#define SOURCES
set(SOURCES
    library_code.cc
    library_code.h
)

# build static library
add_library(common_library STATIC ${SOURCES})

# add header file directory
target_include_directories(common_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})