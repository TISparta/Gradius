#include "Player.hpp"

Player::Player (sf::Texture* texture) {
  player.setRadius(PLAYER::RADIUS);
  player.setPosition(PLAYER::position);
  player.setTexture(texture);
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
  updatePlayer();
  updateBullets();
}

void Player::updatePlayer () {
  if (dirY != DIR::NOMOVE) {
    sf::Vector2f pos = player.getPosition();
    if (dirY == DIR::UP) pos.y -= PLAYER::movementSpeedY;
    if (dirY == DIR::DOWN) pos.y += PLAYER::movementSpeedY;
    if (0 < pos.y and pos.y + 2 * PLAYER::RADIUS < HEIGHT) player.setPosition(pos);
  }
  if (dirX != DIR::NOMOVE) {
    sf::Vector2f pos = player.getPosition();
    if (dirX == DIR::LEFT) pos.x -= PLAYER::movementSpeedX;
    if (dirX == DIR::RIGHT) pos.x += PLAYER::movementSpeedX;
    if (0 < pos.x and pos.x + 2 * PLAYER::RADIUS < WIDTH) player.setPosition(pos);
  }
}

void Player::updateBullets () {
  int id = 0;
  for_each(all(bullet), [&] (auto bullet_i) {
    if (bullet_i -> getPosition().x > WIDTH) toDelete[id] = true;
    id++;
  });
  id = 0;
  auto toDelete1 = remove_if(all(bullet), [&] (auto bullet_i) {
    return toDelete[id++];
  });
  bullet.erase(toDelete1, end(bullet));
  auto toDelete2 = remove_if(all(toDelete), [&] (bool elem) {
    return elem;
  });
  toDelete.erase(toDelete2, end(toDelete));
  for_each(all(bullet), [&] (auto bullet_i) {
    bullet_i -> update(); 
  });
}

void Player::shoot () {
  sf::Vector2f pos = player.getPosition();
  pos.x += 2 * PLAYER::RADIUS;
  pos.y += PLAYER::RADIUS;
  bullet.emplace_back(new Bullet(pos, DIR::RIGHT));
  toDelete.push_back(false);
}

void Player::setToDeleteBullet (int id) {
  toDelete[id] = true;
}

