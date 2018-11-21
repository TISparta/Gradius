#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class Enemy {
public:
  Enemy () {};
  virtual ~Enemy () {};
  virtual void render (sf::RenderWindow& window) = 0;
  virtual void update (const sf::Vector2f player_pos) = 0;
  virtual void setToDelete (int id) = 0;
  virtual int getScore () const = 0;
  virtual std::vector <sf::CircleShape>& getEnemies () = 0;
  inline std::vector <Bullet*> getBullets () { return bullet; }
  int directionX, directionY, score;
  float x, y;
  std::vector <Bullet*> bullet;
};

#endif
