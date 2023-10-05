add_executable(Game_test ../test/Game_test.cpp)
target_include_directories(Game_test PUBLIC ../include ../src)
target_link_libraries(Game_test gtest_main Game ScopedTimer)

include(GoogleTest)
gtest_discover_tests(Game_test)
