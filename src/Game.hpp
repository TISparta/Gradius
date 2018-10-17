#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"
#include "Player.hpp"
#include "Terrain.hpp"
#include "Enemy.hpp"
#include "Enemy01.hpp"
<<<<<<< HEAD:src/Game.hpp
#include "Bullet.hpp"
#include <vector>
=======
>>>>>>> a642b9f79f32ea1149058817801737e5882d446f:Game.hpp

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
