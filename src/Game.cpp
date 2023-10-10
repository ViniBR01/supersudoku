#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <numeric>
#include <stack>
#include <vector>

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

int Game::get_entry(int index)
{
  auto row = convert_index_to_row(index);
  auto col = convert_index_to_col(index);
  auto entry = board[row][col];
  
  return entry;
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

class Node {
public:
  ~Node();
  bool set_level(int new_level);
  int get_level();
  bool set_entry(int new_level);
  int get_entry();
  bool set_child(std::shared_ptr<Node> child);
  std::shared_ptr<Node> get_child(int value);
  int get_num_children();
  bool is_first_visit();
  void mark_as_visited();
  bool is_fixed();
  void mark_as_fixed();
private:
  std::vector<std::shared_ptr<Node>> children;
  int level{0};
  int entry{0};
  bool visited{0};
  bool fixed{0};
};
Node::~Node() {}

bool Node::set_level(int new_level) {
  level = new_level;
  return true;
}
int Node::get_level() {
  return level;
}
bool Node::set_entry(int new_entry) {
  entry = new_entry;
  return true;
}
int Node::get_entry() {
  return entry;
}bool Node::set_child(std::shared_ptr<Node> child) {
  children.push_back(child);
  return true;
}
std::shared_ptr<Node> Node::get_child(int value) {
  return children[value-1];
}
int Node::get_num_children() {
  return children.size();
}
bool Node::is_first_visit() {
  return visited==false;
}
void Node::mark_as_visited() {
  visited = true;
}
bool Node::is_fixed() {
  return fixed;
}
void Node::mark_as_fixed() {
  fixed = true;
}

// Question: can I count all solutions with a single instance of the game class?
int Game::count_solutions() {
  int total_solutions = 0;
  std::shared_ptr<Node> root = std::make_shared<Node>(); //Represents unexistent node
  root->set_level(-1);
  root->set_entry(-1);
  //std::cout << root->get_level() << ": " << root->get_entry() << std::endl;

  std::stack<std::shared_ptr<Node>> node_stack; //top() push() pop()
  node_stack.push(root);

  while(not node_stack.empty()) {
    auto node = node_stack.top();
    // std::cout << node->get_level() << ": " << node->get_entry() << std::endl;
    // std::cout << node->get_level() << std::endl;
    // this->print_board();
    //If not the root, fill that entry
    if (node->get_level() != -1) {
      this->insert_entry(node->get_entry(), node->get_level());
    }

    //Check if level is SIZE*SIZE -1: if yes, increment total_solutions
    //pop node and continue
    if (node->get_level() == SIZE*SIZE - 1) {
      ++total_solutions;
      node_stack.pop();
      if (not node->is_fixed()) {
	this->insert_entry(0, node->get_level());
      }
      continue;
    }

    //Check if each of children is viable and create node if yes
    //Add newly created nodes to the stack
    if (node->is_first_visit()) {
      //1st case: the next level is already filled:
      if (this->get_entry(node->get_level() + 1) != 0) {
	auto new_node = std::make_shared<Node>();
	new_node->set_level(node->get_level() + 1);
	new_node->set_entry(this->get_entry(node->get_level() + 1));
	new_node->mark_as_fixed();
	//node->set_child(new_node);
	node_stack.push(new_node);
	node->mark_as_visited();
	continue;
      }

      //2nd case: the next level is empty:
      else {
	//test all possible guesses from 1 to N and create nodes if viable
	for (int guess = 1; guess <= SIZE; ++guess) {
	  this->insert_entry(guess, node->get_level() + 1);
	  if (
	      this->is_entry_valid(
				   convert_index_to_row(node->get_level() + 1),
				   convert_index_to_col(node->get_level() + 1)
				   )
	      )
	    {
	      auto new_node = std::make_shared<Node>();
	      new_node->set_level(node->get_level() + 1);
	      new_node->set_entry(guess);
	      //node->set_child(new_node);
	      node_stack.push(new_node);
	    }
	  //cleanup next field before leaving
	  this->insert_entry(0, node->get_level() + 1);
	}
	//remember to mark_as_visited();
	node->mark_as_visited();
	continue;
      }
    }

    // If this is not the first visit to a node, it means it was already checked
    else {
      node_stack.pop();
      if (not node->is_fixed()) {
	// cleanup game field for current node - set it to 0
	this->insert_entry(0, node->get_level());
      }
      continue;
    }
  }
  
  return total_solutions;
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
