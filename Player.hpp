#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.hpp"
#include "Terrain.hpp"

class Player {
public:
  Player ();
  ~Player ();
  void render (sf::RenderWindow& window);
  void setDirection (int dir);
private:
  sf::CircleShape player;
  void hundleCollision (); // Aun no estoy seguro de los parametros
  void update ();
  float movementSpeed;
  int direction;
  int attack;
  float attackSpeed;
  int kindOfBullet;
  int lives;
  int score;
};

#endif
