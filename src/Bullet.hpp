#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Bullet {
public:
  Bullet(sf::Vector2f pos, int dir, sf::Texture* texture);
  ~Bullet() {};
  void render (sf::RenderWindow& windowi);
  void update ();
  inline sf::RectangleShape getBullet () { return bullet; }
  inline sf::Vector2f getPosition () const { return bullet.getPosition(); }
private:
  int dir;
  sf::RectangleShape bullet;
};

#endif
