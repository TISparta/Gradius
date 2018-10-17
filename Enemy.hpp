#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Terrain.hpp"

class Enemy {
public:
  Enemy () {};
  virtual ~Enemy () {};
  virtual void render (sf::RenderWindow& window) = 0;
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
  int lives;
  int score;
};

#endif
