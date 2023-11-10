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

TEST(CellTest, ElementManipulation) {
  int clueValue = 3;
  sudoku::Cell<int,9> clueCell(clueValue);
  sudoku::Cell<int,9> openCell;
  int testValue = 5;
  
  EXPECT_FALSE(clueCell.setElement(0));
  EXPECT_FALSE(clueCell.setElement(testValue));
  EXPECT_EQ(clueCell.getElement(), clueValue);
  
  EXPECT_TRUE(openCell.setElement(testValue));
  EXPECT_EQ(openCell.getElement(), testValue);
  EXPECT_TRUE(openCell.setElement(0));
  EXPECT_EQ(openCell.getElement(), 0);
}

TEST(CellTest, PencilCandidates) {
  int clueValue = 3;
  sudoku::Cell<int,9> clueCell(clueValue);
  sudoku::Cell<int,9> openCell;
  int testValue = 5;

  EXPECT_FALSE(clueCell.isPencilCandidate(testValue));
  EXPECT_FALSE(clueCell.addPencilCandidate(testValue));
  EXPECT_FALSE(clueCell.removePencilCandidate(testValue));

  EXPECT_FALSE(openCell.isPencilCandidate(testValue));
  EXPECT_FALSE(openCell.removePencilCandidate(testValue));
  EXPECT_TRUE(openCell.addPencilCandidate(testValue));
  EXPECT_TRUE(openCell.isPencilCandidate(testValue));
  EXPECT_TRUE(openCell.removePencilCandidate(testValue));
  EXPECT_FALSE(openCell.isPencilCandidate(testValue));
}
