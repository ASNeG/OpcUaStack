
rmdir ./build

set BOOST_LIBRARYDIR=C:\local\boost_1_58_0\lib64-msvc-12.0

cmake.exe -G"Visual Studio 12 2013" -H./src/ -B./build
pause