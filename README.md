# Minimal Working Example

When I install OpenImageIO with vcpkg, and link it to a library, the library builds and links without issue.  When I then link that library with an executable, the linker (`ld`) on ubuntu fails with many `undefined reference to 'boost::filesystem::` errors.  This does not happen on Windows with MSVC.

An example image is included so that the program can be run:

## Build on Windows (works fine):

### Visual Studio:
- Have vcpkg installed and integrated
- Allow VS to run CMake Configuration and Build All.  This will also copy an included image to the final output directory:
- Run `myapp.exe` and the output should be `500 x 500 x 3`

### From powershell:
- Have vcpkg installed
- Run the following commands from within the cloned repository:
```
mkdir windows/
cd windows/
cmake -DCMAKE_TOOLCHAIN_FILE=<path/to/vcpkg>/scripts/buildsystems/vcpkg.cmake ../
cmake --build .
```

- Run the program using:
```
cd Debug;
.\myapp.exe ..\data\example.jpg
```

and the output should be `500 x 500 x 3`

## Build on Ubuntu (fails to link):
- Have vcpkg installed
- Run the following commands from within the cloned repository:

```
mkdir build/
cd build/
cmake -DCMAKE_TOOLCHAIN_FILE=<path/to/vcpkg>/scripts/buildsystems/vcpkg.cmake ../
cmake --build .
```

This succeeds to build and link `libmylib.so`, but fails to link executable myapp.  This is the build output:

```
[ 25%] Building CXX object source/mylib/CMakeFiles/mylib.dir/mylib.cpp.o
[ 50%] Linking CXX shared library libmylib.so
[ 50%] Built target mylib
[ 75%] Building CXX object source/myapp/CMakeFiles/myapp.dir/main.cpp.o
[100%] Linking CXX executable ../../myapp
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::thread::physical_concurrency()'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::recursive_directory_iterator_construct(boost::filesystem::recursive_directory_iterator&, boost::filesystem::path const&, unsigned int, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::temp_directory_path(boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::directory_iterator_construct(boost::filesystem::directory_iterator&, boost::filesystem::path const&, unsigned int, boost::filesystem::detail::directory_iterator_params*, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::dir_itr_imp::~dir_itr_imp()'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::unique_path(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::path_algorithms::extension_v3(boost::filesystem::path const&)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::status(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::path_algorithms::filename_v3(boost::filesystem::path const&)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::absolute(boost::filesystem::path const&, boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::path_algorithms::find_parent_path_size(boost::filesystem::path const&)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::directory_iterator_increment(boost::filesystem::directory_iterator&, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::copy(boost::filesystem::path const&, boost::filesystem::path const&, unsigned int, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::file_size(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::dir_itr_imp::operator delete(void*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::remove_all(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::path_algorithms::find_root_directory(boost::filesystem::path const&)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::remove(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::detail::get_tss_data(void const*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::path_algorithms::replace_extension_v3(boost::filesystem::path&, boost::filesystem::path const&)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::path_algorithms::append_v3(boost::filesystem::path&, char const*, char const*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::recursive_directory_iterator_increment(boost::filesystem::recursive_directory_iterator&, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::create_directory(boost::filesystem::path const&, boost::filesystem::path const*, boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::detail::set_tss_data(void const*, void (*)(void (*)(void*), void*), void (*)(void*), void*, bool)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::current_path(boost::system::error_code*)'
/usr/bin/ld: ../mylib/libmylib.so: undefined reference to `boost::filesystem::detail::rename(boost::filesystem::path const&, boost::filesystem::path const&, boost::system::error_code*)'
collect2: error: ld returned 1 exit status
make[2]: *** [source/myapp/CMakeFiles/myapp.dir/build.make:98: myapp] Error 1
make[1]: *** [CMakeFiles/Makefile2:142: source/myapp/CMakeFiles/myapp.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
```
