#include "Game.hpp"

int convert_index_to_row(int index)
{
  return index / SIZE;
}

int convert_index_to_col(int index)
{
  return index % SIZE;
}
