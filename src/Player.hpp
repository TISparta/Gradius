#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.hpp"
#include "Terrain.hpp"

class Player {
public:
  Player ();
  ~Player ();
  void render (sf::RenderWindow& window);
  void update ();
  void setDirection (int _dirX, int _dirY);
  const sf::Vector2f& getPosition () { return player.getPosition(); }
private:
  sf::CircleShape player;
  void hundleCollision (); // Aun no estoy seguro de los parametros
  float movementSpeed;
  int dirX;
  int dirY;
  int attack;
  float attackSpeed;
  int kindOfBullet;
  int lives;
  int score;
};

#endif
