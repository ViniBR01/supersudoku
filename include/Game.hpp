#pragma once

#include <array>

#define SIZE 9

class Game
{
public:
  Game();
  void fill_board();
  void clear_board();
  void print_board();
  bool solve_backtracking();
  bool is_entry_valid(int row, int col);
  void generate_new_game();
  int get_entry(int index);
  int remove_entry(int index);
  bool has_unique_solution();
  void insert_entry(int entry, int index);
  int count_solutions();
  bool fully_filled();
  bool correctly_solved();
private:
  std::array<std::array<int, SIZE>, SIZE> board;
  bool recursive_count(int &total_solutions);
};
