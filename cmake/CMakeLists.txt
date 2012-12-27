cmake_minimum_required (VERSION 2.6)

set (CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
set (CMAKE_DEBUG_POSTFIX "d")

project (OGDT)

include_directories (../include)
file (GLOB_RECURSE SOURCES ../src/*.cc ../src/*.c)
add_library (OGDT STATIC ${SOURCES})

set (CMAKE_CXX_FLAGS "--std=c++0x")
set (LIBRARY_OUTPUT_PATH "../bin")
