find_package(OpenImageIO CONFIG REQUIRED)

if (BUILD_SHARED_LIBS)
	add_library(mylib SHARED mylib.cpp)
else()
	add_library(mylib STATIC mylib.cpp)
endif()

target_link_libraries(mylib PRIVATE OpenImageIO::OpenImageIO)