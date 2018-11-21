#ifndef INTRO_HPP
#define INTRO_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Intro {
public:
  Intro () {}
  Intro (sf::Font* font, sf::Texture* textureSpaceship, sf::Texture* textureLogo);
  ~Intro () {};
  void render (sf::RenderWindow& window);
  void move (int var);
  inline int getId () const { return id; }
private:
  int id;
  sf::CircleShape spaceship;
  sf::RectangleShape logo;
  std::vector <sf::Text> options;
};

#endif
