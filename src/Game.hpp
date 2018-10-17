#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "Player.hpp"
#include "Terrain.hpp"
#include "Enemy.hpp"
#include "Enemy01.hpp"
#include "Bullet.hpp"
#include <vector>

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
  bool playing = true;
  bool pause = false;
  int cntEnemy01 = 0;
  sf::RenderWindow window;
  Player player1;
  Terrain terrain;
  std::vector <Enemy*> enemy;
  std::vector <Bullet*> bullet;
};

#endif
