#pragma once

#include <set>

template <typename elementType, size_t puzzleCardinality>
class Cell
{
public:
  bool isClue();
  bool setElement(elementType element);
  elementType getElement();
  bool isPencilCandidate(elementType element);
  bool addPencilCandidate(elementType element);
  bool removePencilCandidate(elementType element);
private:
  elementType element_;
  bool isClue_{};
  std::set<elementType> pencilCandidates_;
};
