#include "Player.hpp"

Player::Player () {
  player.setRadius(40.f);
  player.setPosition(PLAYER::position);
  player.setFillColor(sf::Color::Red);
  dirY = DIR::NOMOVE;
  dirX = DIR::RIGHT;
}

Player::~Player () {
  for (auto bullet_i: bullet) delete bullet_i;
}

void Player::setDirection (int _dirX, int _dirY) {
  if (_dirX != DIR::UNCHANGED) dirX = _dirX;
  if (_dirY != DIR::UNCHANGED) dirY = _dirY;
}

void Player::render (sf::RenderWindow& window) {
  for_each(all(bullet), [&window] (auto bullet_i) {
    bullet_i -> render(window);
  });
  window.draw(player);
}

void Player::update () {
  if (dirY != DIR::NOMOVE) {
    sf::Vector2f pos = player.getPosition();
    if (dirY == DIR::UP) pos.y -= PLAYER::movementSpeedY;
    if (dirY == DIR::DOWN) pos.y += PLAYER::movementSpeedY;
    player.setPosition(pos);
  }
  if (dirX != DIR::NOMOVE) {
    sf::Vector2f pos = player.getPosition();
    if (dirX == DIR::LEFT) pos.x -= PLAYER::movementSpeedX;
    if (dirX == DIR::RIGHT) pos.x += PLAYER::movementSpeedX;
    player.setPosition(pos);   
  }
  for_each(all(bullet), [&] (auto bullet_i) {
    bullet_i -> update(); 
  }); 
}

void Player::shoot () {
  bullet.emplace_back(new Bullet(player.getPosition(), DIR::RIGHT));
  toDelete.push_back(false);
}

void Player::setToDeleteBullet (int id) {
  toDelete[id] = true;
}

