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
  virtual void setToDelete (int id) = 0;
  virtual std::vector <sf::CircleShape>& getEnemies () = 0;
  int directionX, directionY;
  std::vector <bool> toDelete;
};

#endif
