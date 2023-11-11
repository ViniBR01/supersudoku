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
  private:
    static constexpr size_t puzzleSize_ = puzzleCardinality * puzzleCardinality;
    std::array<Cell<elementType, puzzleCardinality>, puzzleSize_> cells_;
  };

  template <typename elementType, size_t puzzleCardinality>
  Grid<elementType, puzzleCardinality>::Grid()
  {}

  template <typename elementType, size_t puzzleCardinality>
  size_t Grid<elementType, puzzleCardinality>::getSize()
  {
    return puzzleSize_;
  }
}
