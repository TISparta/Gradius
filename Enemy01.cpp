#include "Enemy01.hpp"

Enemy01::Enemy01 (): Enemy() {
  setMovementSpeed(10);
  setDirection(1);
  setAttackSpeed(10);
  setKindOfBuller(1);
  setLives(1);
  setScore(10);
  enemy.setRadius(20.f);
  enemy.setPosition(200.f, 100.f);
  enemy.setFillColor(sf::Color::Green);
}

void Enemy01::render (sf::RenderWindow& window) {
  window.draw(enemy); 
}
