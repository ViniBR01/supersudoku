#include <gtest/gtest.h>

#include "cell.hpp"

TEST(CellTest, DefaultConstructor) {
  sudoku::Cell<int,9> cell;
  EXPECT_EQ(cell.isClue(), false);
  EXPECT_EQ(cell.getElement(), 0);
}

TEST(CellTest, ClueConstructor) {
  int clueValue = 3;
  sudoku::Cell<int,9> cell(clueValue);
  EXPECT_EQ(cell.isClue(), true);
  EXPECT_EQ(cell.getElement(), 3);
}
