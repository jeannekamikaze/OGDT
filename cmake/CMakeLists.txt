cmake_minimum_required (VERSION 2.6)

set (CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
set (OGDT_AVOID_NORMALISATION False CACHE BOOL "Turn on vector normalisation optimisations")
set (CMAKE_DEBUG_POSTFIX "d")

project (OGDT)

FIND_LIBRARY (assimp assimp)
	IF (assimp EQUAL assimp-NOTFOUND)
		MESSAGE( FATAL_ERROR
			"Assimp library (http://assimp.sourceforge.net/) not found. "
			"To-do: Make assimp an optional dependency."
		)
	ENDIF (assimp EQUAL assimp-NOTFOUND)

FIND_LIBRARY (glfw glfw)
	IF (glfw EQUAL glfw-NOTFOUND)
		MESSAGE( FATAL_ERROR
			"GLFW library (http://www.glfw.org/) not found. "
			"To-do: Make glfw an optional dependency."
		)
	ENDIF (glfw EQUAL glfw-NOTFOUND)

include_directories (../include)
file (GLOB_RECURSE SOURCES ../src/*.cc ../src/*.c)
add_library (OGDT STATIC ${SOURCES})

set (CMAKE_CXX_FLAGS "--std=c++0x")
set (LIBRARY_OUTPUT_PATH "../bin")
