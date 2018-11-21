#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#define MAX_NUMBER_ITEMS 3

class Menu{
public:
  Menu(float width, float height);
  ~Menu();
  void draw (sf::RenderWindow &window);
  void moveUp();
  void moveDown();
private:
  int selectedItemIndex;
  sf::Font font;
  sf::Text menu[MAX_NUMBER_ITEMS];
};


#endif