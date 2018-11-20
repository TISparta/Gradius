#ifndef CONFIG_CPP
#define CONFIG_CPP

#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

void loadFont (sf::Font& font, std::string fontName) {
  if (not font.loadFromFile("./fonts/" + fontName)) {
    throw std::runtime_error("Could not load " + fontName + "\n");
  }
}

void setText (sf::Text& text, std::string msg, int size, const sf::Font& font) {
  text.setFont(font);
  text.setString(msg);
  text.setCharacterSize(size);
  text.setStyle(sf::Text::Bold);
//  text.setFillColor(sf::Color::Blue);
}

#endif
