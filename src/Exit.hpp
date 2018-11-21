#ifndef EXIT_HPP
#define EXIT_HPP

#include <SFML/Graphics.hpp>
#include "config.hpp"

class Exit {
public:
  Exit () {}
  Exit (sf::Font* font, sf::Texture* textureSpaceship);
  ~Exit () {};
  void render (sf::RenderWindow& window);
  void move (int var);
  inline int getId () const { return id; }
private:
  int id;
  sf::CircleShape spaceship;
  std::vector <sf::Text> options;
};

#endif
