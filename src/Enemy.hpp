#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Terrain.hpp"

class Enemy {
public:
  Enemy () {};
  virtual ~Enemy () {};
  virtual void render (sf::RenderWindow& window) = 0;
<<<<<<< HEAD:src/Enemy.hpp
  virtual void update (const sf::Vector2f player_pos) = 0;
  void hundleCollision (); // Aun no estoy seguro de los parametros
  float movementSpeed;
  int directionX;
  int directionY;
  int attackSpeed;
=======
  void setMovementSpeed (int _speed) { movementSpeed = _speed; }
  void setDirection (int dir) { direction = dir; }
  void setAttackSpeed (int _attackSpeed) { attackSpeed = _attackSpeed; }
  void setKindOfBuller (int _kindOfBuller) { kindOfBullet = _kindOfBuller; }
  void setLives (int _lives) { lives = _lives; }
  void setScore (int _score) { score = _score; }
private:
  void hundleCollision (); // Aun no estoy seguro de los parametros
  void update ();
  int movementSpeed;
  int direction;
  int attackSpeed;
  int kindOfBullet;
>>>>>>> a642b9f79f32ea1149058817801737e5882d446f:Enemy.hpp
  int lives;
  int score;
};

#endif
