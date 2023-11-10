#pragma once

#include <set>

namespace sudoku {
  template <typename elementType, size_t puzzleCardinality>
  class Cell
  {
  public:
    Cell() = default;
    Cell(elementType clue);
    bool isClue();
    bool setElement(elementType element);
    elementType getElement();
    bool isPencilCandidate(elementType element);
    bool addPencilCandidate(elementType element);
    bool removePencilCandidate(elementType element);
  private:
    elementType element_{};
    bool isClue_{};
    std::set<elementType> pencilCandidates_;
  };

  template <typename elementType, size_t puzzleCardinality>
  Cell<elementType, puzzleCardinality>::Cell(elementType clue) :
    element_(clue),
    isClue_(true)
  {}

  template <typename elementType, size_t puzzleCardinality>
  bool Cell<elementType, puzzleCardinality>::isClue()
  {
    return isClue_;
  }
  
  template <typename elementType, size_t puzzleCardinality>
  bool Cell<elementType, puzzleCardinality>::setElement(elementType element)
  {
    if (isClue_)
      {
	return false;
      }
    element_ = element;
    return true;
  }

  template <typename elementType, size_t puzzleCardinality>
  elementType Cell<elementType, puzzleCardinality>::getElement()
  {
    return element_;
  }

  template <typename elementType, size_t puzzleCardinality>
  bool Cell<elementType, puzzleCardinality>::isPencilCandidate(elementType element)
  {
    return pencilCandidates_.contains(element);
  }

  template <typename elementType, size_t puzzleCardinality>
  bool Cell<elementType, puzzleCardinality>::addPencilCandidate(elementType element)
  {
    if (isClue_ or pencilCandidates_.contains(element))
      {
	return false;
      }
    pencilCandidates_.insert(element);
    return true;
  }

  template <typename elementType, size_t puzzleCardinality>
  bool Cell<elementType, puzzleCardinality>::removePencilCandidate(elementType element)
  {
    if (isClue_ or not pencilCandidates_.contains(element))
      {
	return false;
      }
    pencilCandidates_.erase(element);
    return true;
  }
}
