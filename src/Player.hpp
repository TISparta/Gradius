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
  void setDirection (int dirX,int dirY);
  const sf::Vector2f& getPosition () { return player.getPosition(); }
private:
  sf::CircleShape player;
  bool hundleCollision (); // Aun no estoy seguro de los parametros
  void update ();
  float movementSpeed;
  int dirX;
  int dirY; // no es dir ?
  int attack;
  float attackSpeed;
  int kindOfBullet;
  int lives;
  int score;
};

#endif
