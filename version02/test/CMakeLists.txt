enable_testing()

add_executable(cell_test cell_test.cpp)
target_link_libraries(cell_test GTest::gtest_main)
target_include_directories(cell_test PUBLIC "${PROJECT_SOURCE_DIR}/src")

include(GoogleTest)
gtest_discover_tests(cell_test)
