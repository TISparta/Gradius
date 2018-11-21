#ifndef ENEMY01_HPP
#define ENEMY01_HPP

#include "Enemy.hpp"
#include "config.hpp"
#include <ctime>

class Enemy01: public Enemy {
public:
  Enemy01 ();
  virtual ~Enemy01 () {};
  virtual void render (sf::RenderWindow& window) override;
  virtual void update (const sf::Vector2f player_pos) override;
  virtual void setToDelete (int id) override;
  virtual std::vector <sf::CircleShape>& getEnemies () override { return enemy; }
private:
  void updateEnemies (const sf::Vector2f player_pos);
  void updateBullets ();
  int prevDirectionY;
  clock_t start1, start2;
  std::vector <bool> toDeleteEnemy, toDeleteBullet;
  std::vector <sf::CircleShape> enemy;
};

#endif
