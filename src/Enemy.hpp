#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Terrain.hpp"

class Enemy {
public:
  Enemy () {};
  virtual ~Enemy () {};
  virtual void render (sf::RenderWindow& window) = 0;
  virtual void update (const sf::Vector2f player_pos) = 0;
  void hundleCollision (); // Aun no estoy seguro de los parametros
  float movementSpeed;
  int directionX;
  int directionY;
  int attackSpeed;
  int lives;
  int score;
};

#endif
