#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Menu {
public:
  Menu () {}
  Menu (sf::Font* font, sf::Texture* textureSpaceship, sf::Texture* textureLogo);
  ~Menu ();
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
