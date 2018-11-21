#include "Menu.hpp"
#include "util.hpp"

Menu::Menu (sf::Font* font, sf::Texture* textureSpaceship, sf::Texture* textureLogo) {
  id = 0;
  spaceship.setRadius(MenuConf::RADIUS);
  spaceship.setPosition(MenuConf::SPACESHIP_POS[id]);
  spaceship.setTexture(textureSpaceship);
  sf::Text text;
  setText(text, MenuConf::OPTION1, MenuConf::TEXT_SIZE, font, MenuConf::POS1);
  options.push_back(text);
  setText(text, MenuConf::OPTION2, MenuConf::TEXT_SIZE, font, MenuConf::POS2);
  options.push_back(text);
  logo.setSize(MenuConf::LOGO_SIZE);
  logo.setPosition(MenuConf::LOGO_POS);
  logo.setTexture(textureLogo);
}

Menu::~Menu () {

}

void Menu::move (int var) {
  int sz = options.size();
  id = (id + var + sz) % sz;
  spaceship.setPosition(MenuConf::SPACESHIP_POS[id]);
}

void Menu::render (sf::RenderWindow& window) {
  window.draw(logo);
  window.draw(spaceship);
  for_each(all(options), [&window] (auto option_i) {
    window.draw(option_i);    
  });
}

