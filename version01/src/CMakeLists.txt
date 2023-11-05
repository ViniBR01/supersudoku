include_directories(${SuperSudoku_SOURCE_DIR}/include ${SuperSudoku_SOURCE_DIR}/src)

add_library(Game STATIC Game.cpp utils.cpp)
add_library(ScopedTimer STATIC ScopedTimer.cpp)
