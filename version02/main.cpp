#include <iostream>

#include "cell.hpp"

int main() {
  std::cout << "Hello, world." << std::endl;

  Cell<int, 9> cell;
  std::cout << cell.isClue() << std::endl;
  
  return 0;
}
