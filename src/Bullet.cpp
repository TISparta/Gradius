#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet (sf::Vector2f pos, int dir):
  dir(dir),
  bullet(BulletConf::dimensions) {
  bullet.setPosition(pos);
  bullet.setFillColor(BulletConf::color);
}

void Bullet::render (sf::RenderWindow& window) {
  window.draw(bullet); 
}

void Bullet::update () { 
  auto pos = bullet.getPosition();
  pos.x = pos.x + dx[dir] * BulletConf::dx; 
  bullet.setPosition(pos);
}
