#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet (sf::Vector2f pos, int dir, sf::Texture* texture):
  dir(dir),
  bullet(BulletConf::dimensions) {
  bullet.setPosition(pos);
  bullet.setTexture(texture);
}

void Bullet::render (sf::RenderWindow& window) {
  window.draw(bullet); 
}

void Bullet::update () { 
  auto pos = bullet.getPosition();
  pos.x = pos.x + dx[dir] * BulletConf::dx; 
  bullet.setPosition(pos);
}
