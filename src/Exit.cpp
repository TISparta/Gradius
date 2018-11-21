#include "Exit.hpp"
#include "util.hpp"

Exit::Exit (sf::Font* font, sf::Texture* textureSpaceship) {
  id = 0;
  spaceship.setRadius(ExitConf::RADIUS);
  spaceship.setPosition(ExitConf::SPACESHIP_POS[id]);
  spaceship.setTexture(textureSpaceship);
  sf::Text text;
  setText(text, ExitConf::OPTION1, ExitConf::TEXT_SIZE, font, ExitConf::POS1);
  options.push_back(text);
  setText(text, ExitConf::OPTION2, ExitConf::TEXT_SIZE, font, ExitConf::POS2);
  options.push_back(text);
}

void Exit::move (int var) {
  int sz = options.size();
  id = (id + var + sz) % sz;
  spaceship.setPosition(ExitConf::SPACESHIP_POS[id]);
}

void Exit::render (sf::RenderWindow& window) {
  window.draw(spaceship);
  for_each(all(options), [&window] (auto option_i) {
    window.draw(option_i);    
  });
}

