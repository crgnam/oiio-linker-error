cmake_minimum_required(VERSION 3.19)

option(BUILD_SHARED_LIBS "Build mylib as shared library" OFF)

project(example LANGUAGES CXX VERSION 0.8.0)
set(CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
if (BUILD_SHARED_LIBS)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# Add the included directories:
include_directories(include)

# Add source directories:
add_subdirectory(source/mylib)
add_subdirectory(source/myapp)

# Copy example data so that example program can run:
file(COPY data DESTINATION ${CMAKE_BINARY_DIR})