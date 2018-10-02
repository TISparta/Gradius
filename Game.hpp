#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.hpp"
#include "Terrain.hpp"
#include "Enemy.hpp"

class Game {
public:
  Game ();
  ~Game ();
  void run ();
private:
  void showSetup ();
  void showResult ();
  void processEvents ();
  void processSetupEvents ();
  void processResultEvents ();
  void processPlayingEvents ();
  void hundleCollisions ();
  void generateEnemy ();
  void update ();
  void render ();
  sf::RenderWindow window;
  bool playing;
  bool pause;
  Player player1;
  Terrain* terrain;
  std::vector <Enemy*> enemy;
};

#endif
