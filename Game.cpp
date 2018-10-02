#include "Game.hpp"

Game::Game ():
  window(sf::VideoMode(600, 600), "Gradius - NES"),
  player1() {

}

Game::~Game () {

}

void Game::run () {
  while (window.isOpen()) {
    /* Preguntar las opciones con las que quiere jugar
    while (window.isOpen() and not playing) {
      showSetup();
      processSetupEvents();
    }
    */
    while (window.isOpen()) {
      while (window.isOpen() and pause) processEvents();
      processPlayingEvents();
      update();
      render();
    }
    /* Mostrar su score y preguntar si quiere jugar d nuev
    while (window.isOpen()) {
      showResult();
      processResultEvents();
    }
    */
  }
}

void Game::showSetup () {

}

void Game::showResult () {

}

void Game::processEvents () {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void Game::processSetupEvents () {
  processEvents();
}

void Game::processPlayingEvents () {
  processEvents();
}

void Game::update () {

}

void Game::render () {
  window.clear();
  player1.render(window);
  window.display();
}
