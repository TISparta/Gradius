#include "Player.hpp"

Player::Player () {
  player.setRadius(40.f);
  player.setPosition(100.f, 100.f);
  player.setFillColor(sf::Color::Red);
}

Player::~Player () {

}

void Player::render (sf::RenderWindow& window) {
  window.draw(player);
}
