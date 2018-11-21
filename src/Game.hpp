#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "config.hpp"
#include "Player.hpp"
#include "Terrain.hpp"
#include "Enemy.hpp"
#include "Enemy01.hpp"
#include "Bullet.hpp"
#include "Intro.hpp"
#include "Exit.hpp"

class Game {
public:
  Game ();
  ~Game ();
  void run ();
private:
  void reset ();
  void showCounter ();
  void processPlayingEvents ();
  void processWindowEvents ();
  void processIntroEvents ();
  void processExitEvents ();
  void showPausedMessage ();
  void update ();
  void hundleCollisions ();
  void hundleCollisionWithEnemies ();
  void hundleCollisionWithPlayerBullets ();
  void hundleCollisionWithEnemyBullets ();
  void render (bool display = true);
  Intro intro;
  Exit exit;
  State state = State::PLAYING; 
  bool pause;
  bool gotEvents;
  int cntEnemy01;
  int score;
  sf::RenderWindow window;
  Player player;
  Terrain terrain;
  std::vector <Enemy*> enemy;
  sf::Event event;
  sf::Font* font;
  sf::Texture* textureSpaceship;
  sf::Texture* textureEnemy01;
  sf::Texture* textureLogo;
  sf::Texture* textureBullet1;
  sf::Texture* textureBullet2;
  sf::Music backgroundMusic;
};

#endif
