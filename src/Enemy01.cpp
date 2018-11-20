#include "Enemy01.hpp"

Enemy01::Enemy01(): Enemy() {
  toDelete.resize(E01::nEnemies, false);
  directionX = DIR::LEFT;
  directionY = prevDirectionY = DIR::UP;
  x = E01::x;
  y = E01::y;
  for_each(all(E01::positions), [&] (const std::pair <float, float>& pp) {
    sf::CircleShape enemy_i;
    enemy_i.setRadius(E01::radius);
    enemy_i.setPosition(x + pp.first, y + pp.second);
    enemy_i.setFillColor(E01::color);
    enemy.push_back(enemy_i);
  });
  start = clock();
}

void Enemy01::render (sf::RenderWindow& window) {
  for_each(all(enemy), [&window] (auto enemy_i) {
      window.draw(enemy_i);
  });
}

void Enemy01::update (const sf::Vector2f player_pos) {
  directionY = prevDirectionY;
  if (1.0 * (clock() - start) / CLOCKS_PER_SEC > E01::frec) {
    directionY = (y < player_pos.y) ? DIR::DOWN : DIR::UP;
    start = clock();
  }
  for_each(all(enemy), [&] (sf::CircleShape& enemy_i) {
    auto pos = enemy_i.getPosition();
    enemy_i.setPosition(pos.x + dx[directionX] * E01::movementSpeed,
                        pos.y + dy[directionY] * E01::movementSpeed);
  });
  x += dx[DIR::LEFT] * E01::movementSpeed;
  y += dy[directionY] * E01::movementSpeed;
  prevDirectionY = directionY;
  int id = 0;
  auto toDelete1 = remove_if(all(enemy), [&] (auto enemy_i) {
    return toDelete[id++];
  });
  enemy.erase(toDelete1, end(enemy));
  auto toDelete2 = remove_if(all(toDelete), [&] (bool elem) {
    return elem;
  });
  toDelete.erase(toDelete2, end(toDelete));
}

void Enemy01::setToDelete (int id) {
  toDelete[id] = true;
}

