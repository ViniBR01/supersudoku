#include <gtest/gtest.h>

#include "grid.hpp"

TEST(GridTest, DefaultConstructor) {
  sudoku::Grid<int, 9> grid;
  EXPECT_EQ(grid.getSize(), 81);
}
