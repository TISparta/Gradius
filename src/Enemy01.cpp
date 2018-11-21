#include "Enemy01.hpp"

Enemy01::Enemy01(sf::Texture* texture): Enemy() {
  toDeleteEnemy.resize(E01::nEnemies, false);
  directionX = DIR::LEFT;
  directionY = prevDirectionY = DIR::UP;
  x = E01::x;
  y = E01::y;
  for_each(all(E01::positions), [&] (const std::pair <float, float>& pp) {
    sf::CircleShape enemy_i;
    enemy_i.setRadius(E01::radius);
    enemy_i.setPosition(x + pp.first, y + pp.second);
    enemy_i.setTexture(texture);
    enemy.push_back(enemy_i);
  });
  start1 = start2 = clock();
}

void Enemy01::render (sf::RenderWindow& window) {
  for_each(all(enemy), [&window] (auto enemy_i) {
    window.draw(enemy_i);
  });
  for_each(all(bullet), [&window] (auto bullet_i) {
    bullet_i -> render(window);
  });
}

void Enemy01::update (const sf::Vector2f playerPos) {
  updateEnemies(playerPos);
  updateBullets();
}

void Enemy01::updateEnemies (const sf::Vector2f playerPos) {
  if (enemy.empty()) return;
  directionY = prevDirectionY;
  if (1.0 * (clock() - start1) / CLOCKS_PER_SEC > E01::frec) {
    directionY = (y < playerPos.y) ? DIR::DOWN : DIR::UP;
    start1 = clock();
  }
  for_each(all(enemy), [&] (sf::CircleShape& enemy_i) {
    auto pos = enemy_i.getPosition();
    enemy_i.setPosition(pos.x + dx[directionX] * E01::movementSpeed,
                        pos.y + dy[directionY] * E01::movementSpeed);
  });
  x += dx[DIR::LEFT] * E01::movementSpeed;
  y += dy[directionY] * E01::movementSpeed;
  prevDirectionY = directionY;
}

void Enemy01::updateBullets () {
  int id = 0;
  for_each(all(bullet), [&] (auto bullet_i) {
    if (bullet_i -> getPosition().x + BulletConf::dimensions.x < 0) {
      toDeleteBullet[id] = true;
    }
    id++;
  });
  id = 0;
  auto toDelete1 = remove_if(all(enemy), [&] (auto enemy_i) {
    return toDeleteEnemy[id++];
  });
  enemy.erase(toDelete1, end(enemy));
  auto toDelete2 = remove_if(all(toDeleteEnemy), [&] (bool elem) {
    return elem;
  });
  toDeleteEnemy.erase(toDelete2, end(toDeleteEnemy));
  id = 0;
  auto toDelete3 = remove_if(all(bullet), [&] (auto enemy_i) {
    return toDeleteBullet[id++];
  });
  bullet.erase(toDelete3, end(bullet));
  auto toDelete4 = remove_if(all(toDeleteBullet), [&] (bool elem) {
    return elem;
  });
  toDeleteBullet.erase(toDelete4, end(toDeleteBullet));
  for_each(all(bullet), [&] (auto bullet_i) {
    bullet_i -> update();
  });
  if (not enemy.empty() and 1.0 * (clock() - start2) / CLOCKS_PER_SEC > E01::frec) {
    int id = rand() % enemy.size();
    bullet.emplace_back(new Bullet(enemy[id].getPosition(), DIR::LEFT));
    toDeleteBullet.push_back(false);
    start2 = clock();
  }
}

void Enemy01::setToDelete (int id) {
  toDeleteEnemy[id] = true;
}

