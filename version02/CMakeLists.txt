cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(Supersudoku VERSION 2.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(Main main.cpp)

target_link_libraries(Main PUBLIC Cell)

target_include_directories(Main PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_include_directories(Main PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
