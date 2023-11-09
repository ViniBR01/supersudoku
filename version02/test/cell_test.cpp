#include <gtest/gtest.h>

#include "cell.hpp"

sudoku::Cell<int,9> cell;

TEST(CellTest, BasicAssertions) {
  EXPECT_EQ(cell.isClue(), false);
}
