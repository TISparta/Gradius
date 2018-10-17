#ifndef ENEMY01_HPP
#define ENEMY01_HPP

#include "Enemy.hpp"

class Enemy01: public Enemy {
public:
  Enemy01 ();
  virtual ~Enemy01 () {};
  virtual void render (sf::RenderWindow& window) override;
private:
  sf::CircleShape enemy;
};

#endif
