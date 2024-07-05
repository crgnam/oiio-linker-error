cmake_minimum_required(VERSION 3.19)

if(UNIX AND NOT APPLE)
    # If on Linux:
    if (NOT (CMAKE_BUILD_TYPE STREQUAL "Debug") AND NOT (CMAKE_BUILD_TYPE STREQUAL "Release"))
        set(CMAKE_BUILD_TYPE "Debug")
    endif()

	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message("Debug build")
		set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
	elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
        message("Release Build")
    	set(CMAKE_CXX_FLAGS "-Wall -mtune=native -march=native")
		set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fno-math-errno -fno-signed-zeros -fno-trapping-math -freciprocal-math -fno-rounding-math -fno-signaling-nans -fexcess-precision=fast")
	endif()
endif()

project(vira LANGUAGES CXX VERSION 0.8.0)
set(CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Add the included directories:
include_directories(include)

# Add source directories:
add_subdirectory(source/mylib)
add_subdirectory(source/myapp)

# Copy example data so that example program can run:
file(COPY data DESTINATION ${CMAKE_BINARY_DIR})