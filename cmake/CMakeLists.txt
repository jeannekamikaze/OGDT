cmake_minimum_required (VERSION 2.6)
project (OGDT)

include_directories (../include)

set (CMAKE_CXX_FLAGS "--std=c++0x")

file (GLOB_RECURSE SOURCES ../src/*.cc ../src/*.c)
add_library (OGDT STATIC ${SOURCES})

