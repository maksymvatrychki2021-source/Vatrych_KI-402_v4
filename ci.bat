@echo off

echo == Create build directory ==
if not exist build mkdir build

echo == Enter build directory ==
cd build

echo == Run CMake ==
cmake ..

echo == Build project ==
cmake --build .

echo == Run tests ==
ctest --output-on-failure
