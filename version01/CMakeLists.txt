cmake_minimum_required(VERSION 3.10)
project(SuperSudoku) # Stored as PROJECT_NAME

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(supersudoku main.cpp)

add_subdirectory(${SuperSudoku_SOURCE_DIR}/src)
target_include_directories(supersudoku PUBLIC ${SuperSudoku_SOURCE_DIR}/include PUBLIC ${SuperSudoku_SOURCE_DIR}/src)
target_link_libraries(supersudoku Game ScopedTimer)

enable_testing()

add_subdirectory(${SuperSudoku_SOURCE_DIR}/test)
