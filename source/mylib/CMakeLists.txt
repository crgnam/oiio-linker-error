find_package(OpenImageIO CONFIG REQUIRED)

add_library(mylib SHARED mylib.cpp)
target_link_libraries(mylib PRIVATE OpenImageIO::OpenImageIO)