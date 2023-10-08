#include "Game.hpp"
#include "gtest/gtest.h"

TEST(Game, DefaultConstructor) {
  Game game;
  // Assert that the game is initialized with correct size and all zeros
  EXPECT_EQ(game.remove_entry(0), 0);
  EXPECT_FALSE(game.fully_filled());
  EXPECT_FALSE(game.correctly_solved());
}

TEST(Game, fill_board) {
  Game game;
  game.fill_board();
  EXPECT_FALSE(game.fully_filled());
  EXPECT_EQ(game.remove_entry(1), 2);
  //EXPECT_TRUE(game.has_unique_solution());
}

TEST(Game, solve_backtracking) {
  Game game;
  game.fill_board();
  game.solve_backtracking();
  EXPECT_TRUE(game.fully_filled());
  EXPECT_TRUE(game.correctly_solved());
}

TEST(Game, has_unique_solution) {
  Game game;
  EXPECT_FALSE(game.has_unique_solution());
  game.fill_board();
  EXPECT_TRUE(game.has_unique_solution());
  game.clear_board();
  game.generate_new_game();
  EXPECT_TRUE(game.has_unique_solution());
}

TEST(Game, count_solutions) {
  Game game;
  game.fill_board();
  int num_solutions = 0;
  game.count_solutions(num_solutions);
  EXPECT_EQ(num_solutions, 1);
  game.clear_board();
  game.generate_new_game();
  num_solutions = 0;
  game.count_solutions(num_solutions);
  EXPECT_EQ(num_solutions, 1);
}

TEST(Game, correctly_solved) {
  Game game;
  game.fill_board();
  game.solve_backtracking();
  EXPECT_TRUE(game.correctly_solved());
}
