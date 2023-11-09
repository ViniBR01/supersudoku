cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Supersudoku VERSION 2.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Declare dependency on GTest using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)

add_executable(Main main.cpp)

target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/src")

# Build the test code
enable_testing()

add_executable(cell_test cell_test.cpp)
target_link_libraries(cell_test GTest::gtest_main)
target_include_directories(cell_test PUBLIC "${PROJECT_SOURCE_DIR}/src")

include(GoogleTest)
gtest_discover_tests(cell_test)
