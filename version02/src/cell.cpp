#include "cell.hpp"

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
  if (pencilCandidates_.contains(element))
    {
      return false;
    }
  pencilCandidates_.insert(element);
  return true;
}

template <typename elementType, size_t puzzleCardinality>
bool Cell<elementType, puzzleCardinality>::removePencilCandidate(elementType element)
{
  if (not pencilCandidates_.contains(element))
    {
      return false;
    }
  pencilCandidates_.erase(element);
  return true;
}
