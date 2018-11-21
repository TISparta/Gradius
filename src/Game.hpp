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
  void showCounter ();
  void processPlayingEvents ();
  void processWindowEvents ();
  void showPausedMessage ();
  void update ();
  void hundleCollisions ();
  void hundleCollisionWithEnemy ();
  void hundleCollisionWithBullets ();
  void render (bool pause = false);

  State state = State::PLAYING; 
  bool pause = false;
  bool gotEvents = false;
  int cntEnemy01 = 0;
  sf::RenderWindow window;
  Player player;
  Terrain terrain;
  std::vector <Enemy*> enemy;
  sf::Event event;
  sf::Font font;
  sf::Texture spaceship;
};

#endif
