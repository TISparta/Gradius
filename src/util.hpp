#ifndef CONFIG_CPP
#define CONFIG_CPP

#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

template <class T>
void load (T*& target, std::string path) {
  target = new T();
  if (not target -> loadFromFile(path)) {
    throw std::runtime_error("Could not load " + path + "\n");
  }
}

void setText (sf::Text& text, std::string msg, int size, const sf::Font* font) {
  text.setFont(*font);
  text.setString(msg);
  text.setCharacterSize(size);
  text.setStyle(sf::Text::Bold);
//  text.setFillColor(sf::Color::Blue);
}

#endif
