# CMakeLists.txt for a simple C++ project

cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(CMAKE_CXX_STANDARD 11)

# Add the main executable
add_executable(MyExecutable main.cpp)

# Enable testing
enable_testing()

# Include Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(unit_tests tests/unit_tests.cpp)
target_link_libraries(unit_tests gtest gtest_main)

# Register tests
add_test(NAME unit_tests COMMAND unit_tests)
