#include <iostream>

#include "cell.hpp"

int main() {
  std::cout << "Hello, world." << std::endl;

  {
    sudoku::Cell<int, 9> cell(3);
    std::cout << cell.isClue() << std::endl;
    std::cout << cell.getElement() << std::endl;
    cell.setElement(5);
    std::cout << cell.getElement() << std::endl;
  }

    {
    sudoku::Cell<int, 9> cell;
    std::cout << cell.isClue() << std::endl;
    std::cout << cell.getElement() << std::endl;
    cell.setElement(5);
    std::cout << cell.getElement() << std::endl;
  }
  
  return 0;
}
