@echo off
setlocal

echo == Create build directory ==
if not exist build mkdir build

echo == Enter build directory ==
cd build

echo == Run CMake ==
cmake .. -DCMAKE_BUILD_TYPE=Debug

echo == Build project ==
cmake --build . --config Debug

echo == Run tests ==
ctest --output-on-failure -C Debug

endlocal
