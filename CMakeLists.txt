cmake_minimum_required(VERSION 3.21)
project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# --- Встановлюємо однакову Runtime Library для MSVC ---
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL") # MDd для Debug
endif()

# --- Основна бібліотека з функціями ---
add_library(MyLibrary
    add.cpp       # Реалізація функцій
    # Додати інші .cpp файли за потреби
)
target_include_directories(MyLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# --- Головний виконуваний файл ---
add_executable(MyExecutable main.cpp)
target_link_libraries(MyExecutable PRIVATE MyLibrary)

# --- GoogleTest через FetchContent ---
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- Unit Tests ---
add_executable(unit_tests
    tests/unit_tests.cpp
    add.cpp  # Підключаємо реалізацію функцій до тестів
)
target_link_libraries(unit_tests
    PRIVATE
    MyLibrary
    gtest_main
)

add_test(NAME unit_tests COMMAND unit_tests)
