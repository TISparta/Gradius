#ifndef ENEMY01_HPP
#define ENEMY01_HPP

#include "Enemy.hpp"
#include "config.hpp"

class Enemy01: public Enemy {
public:
  Enemy01 ();
  virtual ~Enemy01 () {};
  virtual void render (sf::RenderWindow& window) override;
  virtual void update (const sf::Vector2f player_pos) override;
private:
  float x, y;
  std::vector <sf::CircleShape> enemy;
};

#endif
