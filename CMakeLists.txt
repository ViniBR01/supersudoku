cmake_minimum_required(VERSION 3.10)
project(SuperSudoku) # Stored as PROJECT_NAME

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(supersudoku main.cpp)

add_subdirectory(${SuperSudoku_SOURCE_DIR}/src)
target_include_directories(supersudoku PUBLIC ${SuperSudoku_SOURCE_DIR}/include PUBLIC ${SuperSudoku_SOURCE_DIR}/src)
target_link_libraries(supersudoku Game ScopedTimer)
