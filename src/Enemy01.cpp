#include "Enemy01.hpp"

Enemy01::Enemy01(): Enemy() {
  x = E01::x;
  y = E01::y;
  movementSpeed = E01::movementSpeed;
  directionX = E01::directionX;
  attackSpeed = E01::attackSpeed;
  lives = E01::lives;
  score = E01::score;
  for_each(all(E01::positions), [&] (const std::pair <float, float>& pp) {
    sf::CircleShape enemy_i;
    enemy_i.setRadius(E01::radius);
    enemy_i.setPosition(x + pp.first, y + pp.second);
    enemy_i.setFillColor(E01::color);
    enemy.push_back(enemy_i);
  });
}

void Enemy01::render (sf::RenderWindow& window) {
  for (auto enemy_i: enemy) window.draw(enemy_i); 
}

void Enemy01::update (const sf::Vector2f player_pos) {
  int directionY = (y < player_pos.y) ? DOWN : UP;
  for_each(all(enemy), [&] (sf::CircleShape& enemy_i) {
    auto pos = enemy_i.getPosition();
    enemy_i.setPosition(pos.x + dx[LEFT] * E01::movementSpeed,
                        pos.y + dy[directionY] * E01::movementSpeed);
  });
  x += dx[LEFT] * E01::movementSpeed;
  y += dy[directionY] * E01::movementSpeed;
}
