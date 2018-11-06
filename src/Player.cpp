#include "Player.hpp"

Player::Player () {
  player.setRadius(40.f);
  player.setPosition(100.f, 100.f);
  player.setFillColor(sf::Color::Red);
  dirY = NOMOVE;
  dirX = RIGHT;
}

Player::~Player () {

}

void Player::setDirection (int _dirX, int _dirY) {
  if (_dirX != UNCHANGED) dirX = _dirX;
  if (_dirY != UNCHANGED) dirY = _dirY;
}

void Player::render (sf::RenderWindow& window) {
  window.draw(player);
}

void Player::update () {
  if (dirY != NOMOVE) {
    sf::Vector2f pos = player.getPosition();
    if (dirY == UP) pos.y -= PLAYER::movementSpeedY;
    if (dirY == DOWN) pos.y += PLAYER::movementSpeedY;
    player.setPosition(pos);
  }
  if (dirX != NOMOVE) {
    sf::Vector2f pos = player.getPosition();
    if (dirX == LEFT) pos.x -= PLAYER::movementSpeedX;
    if (dirX == RIGHT) pos.x += PLAYER::movementSpeedX;
    player.setPosition(pos);   
  }
}
