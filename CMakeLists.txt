cmake_minimum_required(VERSION 3.10)
project(SuperSudoku) # Stored as PROJECT_NAME

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
include_directories(include src)

add_executable(supersudoku main.cpp)
