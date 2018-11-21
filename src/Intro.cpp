#include "Intro.hpp"
#include "util.hpp"

Intro::Intro (sf::Font* font, sf::Texture* textureSpaceship, sf::Texture* textureLogo) {
  id = 0;
  spaceship.setRadius(IntroConf::RADIUS);
  spaceship.setPosition(IntroConf::SPACESHIP_POS[id]);
  spaceship.setTexture(textureSpaceship);
  sf::Text text;
  setText(text, IntroConf::OPTION1, IntroConf::TEXT_SIZE, font, IntroConf::POS1);
  options.push_back(text);
  setText(text, IntroConf::OPTION2, IntroConf::TEXT_SIZE, font, IntroConf::POS2);
  options.push_back(text);
  logo.setSize(IntroConf::LOGO_SIZE);
  logo.setPosition(IntroConf::LOGO_POS);
  logo.setTexture(textureLogo);
}

void Intro::move (int var) {
  int sz = options.size();
  id = (id + var + sz) % sz;
  spaceship.setPosition(IntroConf::SPACESHIP_POS[id]);
}

void Intro::render (sf::RenderWindow& window) {
  window.draw(logo);
  window.draw(spaceship);
  for_each(all(options), [&window] (auto option_i) {
    window.draw(option_i);    
  });
}

