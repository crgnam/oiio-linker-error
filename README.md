# Minimal Working Example

When I install OpenImageIO with vcpkg, and link it to a library, the library builds and links without issue.  When I then link that library with an executable, the linker (`ld`) on ubuntu fails with many `undefined reference to 'boost::filesystem::` errors.  This does not happen on Windows with MSVC.

An example image is included so that the program can be run:

## Success Build on Windows (works fine):

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

## Build on Ubuntu (static lib.  fails to link):
- Have vcpkg installed
- Run the following commands from within the cloned repository:

```
mkdir build/
cd build/
cmake -DCMAKE_TOOLCHAIN_FILE=<path/to/vcpkg>/scripts/buildsystems/vcpkg.cmake ../
cmake --build .
```

This succeeds to build and link `libmylib.a`, but fails to link executable myapp.  This is the build output:

```
[ 25%] Building CXX object source/mylib/CMakeFiles/mylib.dir/mylib.cpp.o
[ 50%] Linking CXX static library libmylib.a
[ 50%] Built target mylib
[ 75%] Building CXX object source/myapp/CMakeFiles/myapp.dir/main.cpp.o
[100%] Linking CXX executable ../../myapp
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_d.a(imageinput.cpp.o): in function `boost::thread_specific_ptr<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::~thread_specific_ptr()':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/thread/tss.hpp:61: undefined reference to `boost::detail::set_tss_data(void const*, void (*)(void (*)(void*), void*), void (*)(void*), void*, bool)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_d.a(imageinput.cpp.o): in function `boost::thread_specific_ptr<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::get() const':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/thread/tss.hpp:66: undefined reference to `boost::detail::get_tss_data(void const*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_d.a(imageinput.cpp.o): in function `boost::thread_specific_ptr<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >::reset(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/thread/tss.hpp:87: undefined reference to `boost::detail::set_tss_data(void const*, void (*)(void (*)(void*), void*), void (*)(void*), void*, bool)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_d.a(imagecache.cpp.o): in function `boost::thread_specific_ptr<OpenImageIO_v2_5::pvt::ImageCachePerThreadInfo>::~thread_specific_ptr()':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/thread/tss.hpp:61: undefined reference to `boost::detail::set_tss_data(void const*, void (*)(void (*)(void*), void*), void (*)(void*), void*, bool)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_d.a(imagecache.cpp.o): in function `boost::thread_specific_ptr<OpenImageIO_v2_5::pvt::ImageCachePerThreadInfo>::get() const':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/thread/tss.hpp:66: undefined reference to `boost::detail::get_tss_data(void const*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_d.a(imagecache.cpp.o): in function `boost::thread_specific_ptr<OpenImageIO_v2_5::pvt::ImageCachePerThreadInfo>::reset(OpenImageIO_v2_5::pvt::ImageCachePerThreadInfo*)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/thread/tss.hpp:87: undefined reference to `boost::detail::set_tss_data(void const*, void (*)(void (*)(void*), void*), void (*)(void*), void*, bool)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::path::filename() const':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/path.hpp:1732: undefined reference to `boost::filesystem::detail::path_algorithms::filename_v3(boost::filesystem::path const&)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::path::extension() const':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/path.hpp:1742: undefined reference to `boost::filesystem::detail::path_algorithms::extension_v3(boost::filesystem::path const&)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::path::replace_extension(boost::filesystem::path const&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/path.hpp:1721: undefined reference to `boost::filesystem::detail::path_algorithms::replace_extension_v3(boost::filesystem::path&, boost::filesystem::path const&)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::path::append(boost::filesystem::path const&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/path.hpp:1691: undefined reference to `boost::filesystem::detail::path_algorithms::append_v3(boost::filesystem::path&, char const*, char const*)'
/usr/bin/ld: /mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/path.hpp:1691: undefined reference to `boost::filesystem::detail::path_algorithms::append_v3(boost::filesystem::path&, char const*, char const*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::path::parent_path() const':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/path.hpp:1071: undefined reference to `boost::filesystem::detail::path_algorithms::find_parent_path_size(boost::filesystem::path const&)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::path::has_root_directory() const':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/path.hpp:1084: undefined reference to `boost::filesystem::detail::path_algorithms::find_root_directory(boost::filesystem::path const&)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::directory_iterator::directory_iterator(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/directory.hpp:705: undefined reference to `boost::filesystem::detail::directory_iterator_construct(boost::filesystem::directory_iterator&, boost::filesystem::path const&, unsigned int, boost::filesystem::detail::directory_iterator_params*, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::directory_iterator::increment(boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/directory.hpp:731: undefined reference to `boost::filesystem::detail::directory_iterator_increment(boost::filesystem::directory_iterator&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::directory_iterator::increment()':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/directory.hpp:746: undefined reference to `boost::filesystem::detail::directory_iterator_increment(boost::filesystem::directory_iterator&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::recursive_directory_iterator::recursive_directory_iterator(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/directory.hpp:907: undefined reference to `boost::filesystem::detail::recursive_directory_iterator_construct(boost::filesystem::recursive_directory_iterator&, boost::filesystem::path const&, unsigned int, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::recursive_directory_iterator::increment(boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/directory.hpp:953: undefined reference to `boost::filesystem::detail::recursive_directory_iterator_increment(boost::filesystem::recursive_directory_iterator&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::status(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:181: undefined reference to `boost::filesystem::detail::status(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::exists(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:201: undefined reference to `boost::filesystem::detail::status(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::is_regular_file(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:211: undefined reference to `boost::filesystem::detail::status(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::is_directory(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:221: undefined reference to `boost::filesystem::detail::status(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::current_path()':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:347: undefined reference to `boost::filesystem::detail::current_path(boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::current_path(boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:352: undefined reference to `boost::filesystem::detail::current_path(boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::absolute(boost::filesystem::path const&, boost::filesystem::path const&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:367: undefined reference to `boost::filesystem::detail::absolute(boost::filesystem::path const&, boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::copy(boost::filesystem::path const&, boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:422: undefined reference to `boost::filesystem::detail::copy(boost::filesystem::path const&, boost::filesystem::path const&, unsigned int, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::create_directory(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:514: undefined reference to `boost::filesystem::detail::create_directory(boost::filesystem::path const&, boost::filesystem::path const*, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::file_size(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:574: undefined reference to `boost::filesystem::detail::file_size(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::remove(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:644: undefined reference to `boost::filesystem::detail::remove(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::remove_all(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:654: undefined reference to `boost::filesystem::detail::remove_all(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::rename(boost::filesystem::path const&, boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:664: undefined reference to `boost::filesystem::detail::rename(boost::filesystem::path const&, boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::temp_directory_path(boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:731: undefined reference to `boost::filesystem::detail::temp_directory_path(boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `boost::filesystem::unique_path(boost::filesystem::path const&, boost::system::error_code&)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/filesystem/operations.hpp:741: undefined reference to `boost::filesystem::detail::unique_path(boost::filesystem::path const&, boost::system::error_code*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(filesystem.cpp.o): in function `void boost::sp_adl_block::intrusive_ptr_release<boost::filesystem::detail::dir_itr_imp, boost::sp_adl_block::thread_safe_counter>(boost::sp_adl_block::intrusive_ref_counter<boost::filesystem::detail::dir_itr_imp, boost::sp_adl_block::thread_safe_counter> const*)':
/mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/smart_ptr/intrusive_ref_counter.hpp:173: undefined reference to `boost::filesystem::detail::dir_itr_imp::~dir_itr_imp()'
/usr/bin/ld: /mnt/c/Users/cgnam/source/repos/vira/out/ubuntu/vcpkg_installed/x64-linux/include/boost/smart_ptr/intrusive_ref_counter.hpp:173: undefined reference to `boost::filesystem::detail::dir_itr_imp::operator delete(void*)'
/usr/bin/ld: ../../vcpkg_installed/x64-linux/debug/lib/libOpenImageIO_Util_d.a(sysutil.cpp.o): in function `OpenImageIO_v2_5::Sysutil::physical_concurrency()':
/mnt/c/Users/cgnam/vcpkg/buildtrees/openimageio/src/v2.5.8.0-82b574f2ba.clean/src/libutil/sysutil.cpp:612: undefined reference to `boost::thread::physical_concurrency()'
collect2: error: ld returned 1 exit status
make[2]: *** [source/myapp/CMakeFiles/myapp.dir/build.make:112: myapp] Error 1
make[1]: *** [CMakeFiles/Makefile2:142: source/myapp/CMakeFiles/myapp.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
```

## Build on Ubuntu (shared lib.  fails to link):
Optionally, you can build as a shared lib by setting `BUILD_SHARED_LIBS`.  To do this on Ubuntu, simply run:

```
mkdir build/
cd build/
cmake -DCMAKE_TOOLCHAIN_FILE=<path/to/vcpkg>/scripts/buildsystems/vcpkg.cmake -DBUILD_SHARED_LIBS=ON ../
cmake --build .
```

(*NOTE: On windows, this will set `CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS` to `ON`.  But everything still builds an links successfully*).  

On Ubuntu, doing this will successfully build and link `libmylib.so`, however still fails to link with the executable giving the following errors:

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
