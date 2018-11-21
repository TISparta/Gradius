#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.hpp"

class Player {
public:
  Player () {};
  Player (sf::Texture* textureSpaceship, sf::Texture* _textureBullet);
  ~Player ();
  void render (sf::RenderWindow& window);
  void update ();
  void setDirection (int _dirX, int _dirY);
  void setToDeleteBullet (int id);
  void shoot ();
  inline const sf::Vector2f& getPosition () const { return player.getPosition(); }
  inline const sf::CircleShape getPlayer () const { return player; };
  inline std::vector <Bullet*> getBullets () { return bullet; }
private:
  void updatePlayer ();
  void updateBullets ();
  sf::CircleShape player;
  std::vector <Bullet*> bullet;
  std::vector <bool> toDelete;
  int dirX, dirY;
  sf::Texture* textureBullet;
};

#endif
