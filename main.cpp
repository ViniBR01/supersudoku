#include <iostream>
#include <array>
#include <iterator>
#include <chrono>

#define SIZE 9

class ScopedTimer
{
public:
  using ClockType = std::chrono::steady_clock;

  ScopedTimer(const char* func) : function_name_{func}, start_{ClockType::now()} {}

  ScopedTimer(const ScopedTimer&) = delete;
  ScopedTimer(ScopedTimer&&) = delete;
  auto operator=(const ScopedTimer&) -> ScopedTimer& = delete;
  auto operator=(ScopedTimer&&) -> ScopedTimer& = delete;

  ~ScopedTimer() {
    using namespace std::chrono;
    auto stop = ClockType::now();
    auto duration = (stop - start_);
    auto ms = duration_cast<milliseconds>(duration).count();
    std::cout << ms << " ms " << function_name_ << '\n';
  }

private:
  const char* function_name_{};
  const ClockType::time_point start_{};
};

class Game
{
  std::array<std::array<int, SIZE>, SIZE> board;
public:
  Game();
  void fill_board();
  void print_board();
  bool solve_backtracking();
  bool is_entry_valid(int row, int col);
};

// Use constructor to start an empty board
Game::Game()
{
  board[0] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  board[1] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  board[2] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  board[3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  board[4] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  board[5] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  board[6] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  board[7] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  board[8] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
}

void Game::fill_board()
{
  board[0] = {0, 2, 0, 1, 6, 5, 9, 0, 0};
  board[1] = {4, 0, 0, 0, 0, 0, 6, 0, 0};
  board[2] = {6, 0, 1, 0, 0, 2, 0, 3, 0};
  board[3] = {0, 0, 6, 5, 0, 0, 2, 0, 4};
  board[4] = {2, 0, 0, 0, 0, 0, 0, 0, 0};
  board[5] = {0, 8, 0, 2, 9, 0, 0, 0, 3};
  board[6] = {0, 0, 2, 4, 0, 0, 0, 0, 0};
  board[7] = {8, 0, 0, 9, 0, 0, 0, 7, 0};
  board[8] = {0, 1, 0, 0, 3, 0, 0, 0, 9};
}

void Game::print_board()
{
  std::cout << "Printing game board" << std::endl;
  for (int row = 0; row < SIZE; ++row)
    {
      if (row % 3 == 0)
	std::cout << " _______ _______ _______" << std::endl << std::endl;

      for (auto col = 0; col < SIZE; ++col)
	{
	  if (col % 3 == 0)
	    std::cout << "| ";
	  std::cout << board[row][col] << " ";
	}
      std::cout << "|" << std::endl;
    }
  std::cout << " _______ _______ _______" << std::endl << std::endl;
}

bool Game::solve_backtracking()
{
  //  std::cout << "Solving puzzle..." << std::endl;
  int row, col;
  bool puzzle_done = true;
  for (row = 0; row < SIZE; ++row)
    {
      for (col=0; col < SIZE; ++col)
	{
	  if (board[row][col] == 0)
	    {
	      puzzle_done = false;
	      break;
	    }
	}
      if (not puzzle_done)
	break;
    }
  
  if (puzzle_done)
    {
      return true;
    }

  int guess;
  for (guess = 1; guess <= SIZE; ++guess)
    {
      //      std::cout << "guessing " << row << " " << col << " " << guess << std::endl;
      board[row][col] = guess;
      if (this->is_entry_valid(row, col))
	{
	  bool is_solved = this->solve_backtracking();
	  //	  std::cout << "is_solved=" << is_solved << std::endl;
	  if (is_solved)
	    {
	      return true;
	    }
	}
      board[row][col] = 0;
    }

  return false;
}

bool Game::is_entry_valid(int row, int col)
{
  //Based on row and col, check validity of puzzle:
  //Test all other entries in row:
  for (int test_col = 0; test_col < SIZE; ++test_col)
    {
      if (test_col != col and board[row][test_col] == board[row][col])
	return false;
    }

  //Test all other entries in column:
  for (int test_row = 0; test_row < SIZE; ++test_row)
    {
      if (test_row != row and board[test_row][col] == board[row][col])
	return false;
    }
  
  //Localize block:
  int block_row = row - (row % 3);
  int block_col = col - (col % 3);

  //  std::cout << "entry: " << row << " " << col << std::endl;
  //  std::cout << "block: " << block_row << " " << block_col << std::endl;

  //Test all other entries in block:
  for (int test_row = block_row; test_row < block_row + 3; ++test_row)
    {
      for (int test_col = block_col; test_col < block_col + 3; ++ test_col)
	{
	  if ((test_row != row or test_col != col) and board[test_row][test_col] == board[row][col])
	    return false;
	}
    }
  
  return true;
}
  
int main()
{
  Game game;
  game.print_board();
  game.fill_board();
  game.print_board();
  game.solve_backtracking();
  game.print_board();
  
  return 0;
}
