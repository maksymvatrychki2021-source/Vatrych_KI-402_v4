@echo off
mkdir build
cd build
cmake ..
cmake --build .
chmod +x .\* 
ctest
