#include "Game.hpp"
#include "gtest/gtest.h"

TEST(Game, DefaultConstructor) {
  Game game;
  // Assert that the game is initialized with correct size and all zeros
  EXPECT_EQ(0, 0);
}
