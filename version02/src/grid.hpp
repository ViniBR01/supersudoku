#pragma once

#include <array>

#include "cell.hpp"

namespace sudoku {
  template <typename elementType, size_t puzzleCardinality>
  class Grid
  {
  public:
    Grid<elementType, puzzleCardinality>();
    size_t getSize();
    Cell<elementType, puzzleCardinality>& getCell(size_t index);
    Cell<elementType, puzzleCardinality>& getCell(size_t row, size_t column);
  private:
    static constexpr size_t puzzleSize_ = puzzleCardinality * puzzleCardinality;
    std::array<Cell<elementType, puzzleCardinality>, puzzleSize_> cells_;

    size_t getIndex_(size_t row, size_t column);
  };

  template <typename elementType, size_t puzzleCardinality>
  Grid<elementType, puzzleCardinality>::Grid()
  {}

  template <typename elementType, size_t puzzleCardinality>
  size_t
  Grid<elementType, puzzleCardinality>::getSize()
  {
    return puzzleSize_;
  }

  template <typename elementType, size_t puzzleCardinality>
  Cell<elementType, puzzleCardinality>&
  Grid<elementType, puzzleCardinality>::getCell(size_t index)
  {
    return cells_[index];
  }
  
  template <typename elementType, size_t puzzleCardinality>
  Cell<elementType, puzzleCardinality>&
  Grid<elementType, puzzleCardinality>::getCell(size_t row, size_t column)
  {
    return cells_[getIndex_(row, column)];
  }

  template <typename elementType, size_t puzzleCardinality>
  size_t
  Grid<elementType, puzzleCardinality>::getIndex_(size_t row, size_t column)
  {
    return row+column*puzzleCardinality;
  }
}
