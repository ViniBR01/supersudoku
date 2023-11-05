#pragma once

template <typename elementType, size_t puzzleCardinality>
class Cell
{
public:
  bool isClue();
  bool setElement(elementType element);
  elementType getElement(elementType element);
  bool isPencilCandidate(elementType element);
  bool addPencilCandidate(elementType element);
  bool removePencilCandidate(elementType element);
private:
  elementType element_;
  bool isClue_{};
  std::set<elementType> pencilCandidates_;
};

bool Cell::isClue()
{
  return isClue_;
}

bool Cell::setElement(elementType element)
{
  if (isClue_)
    {
      return false;
    }
  element_ = element;
  return true;
}

elementType Cell::getElement()
{
  return element_;
}
  
bool isPencilCandidate(elementType element)
{
  return pencilCandidates_.contains(element);
}

bool addPencilCandidate(elementType element)
{
  if (pencilCandidates_.contains(element))
    {
      return false;
    }
  pencilCandidates_.insert(element);
  return true;
}

bool removePencilCandidate(elementType element)
{
  if (not pencilCandidates_.contains(element))
    {
      return false;
    }
  pencilCandidates_.erase(element);
  return true;
}
