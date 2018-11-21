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
  inline sf::RectangleShape getBullet () { return bullet; }
  inline sf::Vector2f getPosition () const { return bullet.getPosition(); }
private:
  int dir;
  sf::RectangleShape bullet;
};

#endif
