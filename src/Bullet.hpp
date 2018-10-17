#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Bullet {
public:
  Bullet(sf::Vector2f pos, int dir);
  ~Bullet() {};
  void render (sf::RenderWindow& window);
  void update ();
private:
  int dir;
  sf::RectangleShape bullet;
};

#endif
