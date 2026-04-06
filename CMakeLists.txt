cmake_minimum_required(VERSION 3.21)
project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL") 
endif()

add_library(MyLibrary
    add.cpp      
)
target_include_directories(MyLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(MyExecutable main.cpp)
target_link_libraries(MyExecutable PRIVATE MyLibrary)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(unit_tests
    tests/unit_tests.cpp
    add.cpp  
)
target_link_libraries(unit_tests
    PRIVATE
    MyLibrary
    gtest_main
)

add_test(NAME unit_tests COMMAND unit_tests)
