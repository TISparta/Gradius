#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Terrain.hpp"

class Enemy {
public:
  Enemy ();
  virtual ~Enemy ();
  virtual void render (sf::RenderWindow& window) = 0;
private:
  float vel;
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
