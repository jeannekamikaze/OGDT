cmake_minimum_required (VERSION 2.6)

set (CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
set (OGDT_AVOID_NORMALISATION False CACHE BOOL "Turn off vector normalisations for improved speed")
set (CMAKE_DEBUG_POSTFIX "d")

project (OGDT)

FIND_LIBRARY (glew GLEW)
	IF (${glew} STREQUAL glew-NOTFOUND)
		MESSAGE (FATAL_ERROR
			"GLEW library (http://glew.sourceforge.net/) not found.")
	ENDIF (${glew} STREQUAL glew-NOTFOUND)

FIND_LIBRARY (assimp assimp)
	IF (${assimp} STREQUAL assimp-NOTFOUND)
		MESSAGE (FATAL_ERROR
			"Assimp library (http://assimp.sourceforge.net/) not found."
			"To-do: Make assimp an optional dependency.")
	ENDIF (${assimp} STREQUAL assimp-NOTFOUND)

FIND_LIBRARY (glfw glfw)
	IF (glfw STREQUAL glfw-NOTFOUND)
		MESSAGE (FATAL_ERROR
			"GLFW library (http://www.glfw.org/) not found."
			"To-do: Make glfw an optional dependency.")
	ENDIF (glfw STREQUAL glfw-NOTFOUND)

include_directories (../include)
file (GLOB_RECURSE SOURCES ../src/*.cc ../src/*.c)
add_library (OGDT STATIC ${SOURCES})

set (CMAKE_CXX_FLAGS "--std=c++0x")
set (LIBRARY_OUTPUT_PATH "../bin")

