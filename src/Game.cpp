#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

#include "Game.hpp"
#include "ScopedTimer.hpp"
#include "utils.hpp"

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
  ScopedTimer timer{__func__};
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
  // ScopedTimer timer{__func__};
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

void Game::clear_board()
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

void Game::generate_new_game()
{
  //TODO: Start with empty board, fill with 1 solution
  this->clear_board();
  this->solve_backtracking();

  // iteratively remove 1 random entry and check if still has unique solution
  // stop when all entries were tested removed or we hit some threshold for remaining etnries
  std::array<int, SIZE*SIZE> all_fields;
  std::iota(all_fields.begin(), all_fields.end(), 0);
  std::random_shuffle(all_fields.begin(), all_fields.end());

  for (auto index : all_fields)
    {
      // std::cout << index << "\n";
      auto temp_entry = this->remove_entry(index);
      // this->print_board();
      // std::cout << this->has_unique_solution() << std::endl;
      if (this->has_unique_solution())
	{
	  continue;
	}
      else
	{
	  this->insert_entry(temp_entry, index);
	}
    }
}

int Game::remove_entry(int index)
{
  auto row = convert_index_to_row(index);
  auto col = convert_index_to_col(index);
  auto entry = board[row][col];
  board[row][col] = 0;
  
  return entry;
}

bool Game::has_unique_solution()
{
  //make a copy of the game and check unique solution there
  auto game_copy = *this;
  int solution_counter = game_copy.count_solutions();
  if (solution_counter == 1) {
    return true;
  }
  return false;
}

int Game::count_solutions()
{
  //Recursive function to solve sudoku
  //
  //Useful methods:
  //this->fully_filled()
  //this->correctly_solved()
  //this->is_entry_valid()
  //
  int total_solutions = 0;
  
  Game temp_game = *this;
  temp_game.recursive_count(total_solutions);

  return total_solutions;
}

bool Game::recursive_count(int &total_solutions) {
  total_solutions = 5;
  return true;
}

bool Game::fully_filled()
{
  for (int row = 0; row < SIZE; ++row) {
    for (int col = 0; col < SIZE; ++col) {
      if (board[row][col] == 0) {
	return false;
      }
    }
  }
  return true;
}

bool Game::correctly_solved()
{
  for (int row = 0; row < SIZE; ++row) {
    for (int col = 0; col < SIZE; ++col) {
      if (not this->is_entry_valid(row, col)) {
	return false;
      }
    }
  }
  return true;
}

void Game::insert_entry(int entry, int index)
{
  auto row = convert_index_to_row(index);
  auto col = convert_index_to_col(index);
  board[row][col] = entry;
}
