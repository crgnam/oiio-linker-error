cmake_minimum_required(VERSION 3.19)

project(example LANGUAGES CXX VERSION 0.8.0)
set(CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(.)


# Build and link my library:
add_library(mylib STATIC mylib.cpp)

find_package(OpenImageIO CONFIG REQUIRED)
target_link_libraries(mylib PRIVATE OpenImageIO::OpenImageIO)

# THESE APPEAR TO WORK WHEN OPENIMAGEIO IS INSTALLED WITH: sudo apt install libopenimageio-dev:
#find_library(OIIO OpenImageIO)
#target_link_libraries(mylib PRIVATE ${OIIO})


# Build and link Executable:
add_executable(myapp myapp.cpp)
target_link_libraries(myapp PRIVATE mylib)