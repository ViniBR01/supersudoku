#include "Game.hpp"
#include "ScopedTimer.hpp"

void test_game()
{
  Game game;
  game.fill_board();
  game.print_board();
  {
    //TODO: write proper benchmarking function to run solving K times and print stats (avg, min, max)
    ScopedTimer timer{"solve_backtracking"};
    game.solve_backtracking();
  }
  game.print_board();
}

int main()
{
  // test_game();

  Game game;
  game.print_board();
  {
        ScopedTimer timer{"generate_new_game"};
	game.generate_new_game();
  }
  game.print_board();

  {
    ScopedTimer time{"solve"};
    game.solve_backtracking();
  }
  game.print_board();
  
  return 0;
}
