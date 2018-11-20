#include "Game.hpp"
#include <iostream>
#include <exception>

int main () {
  try {
    Game *game = new Game();
    game -> run();
    delete game;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}

