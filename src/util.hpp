#ifndef CONFIG_CPP
#define CONFIG_CPP

#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

template <class T>
static void load (T*& target, std::string path) {
  target = new T();
  if (not target -> loadFromFile(path)) {
    throw std::runtime_error("Could not load " + path + "\n");
  }
}

static void setText (sf::Text& text, std::string msg, int size, const sf::Font* font, sf::Vector2f pos = {0, 0}) {
  text.setFont(*font);
  text.setString(msg);
  text.setCharacterSize(size);
  text.setStyle(sf::Text::Bold);
  text.setPosition(pos);
//  text.setFillColor(sf::Color::Blue);
}

#endif
