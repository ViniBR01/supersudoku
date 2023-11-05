#pragma once

template <typename elementType>
class Cell
{
public:
  bool isClue();
  bool setElement(elementType element);
  elementType getElement(elementType element);
private:
  elementType element_;
  bool isClue_{};
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
  
