#include "Game.hpp"
#include <iostream>
#include <chrono>
#include <thread>

Game::Game ():
  window(sf::VideoMode(WIDTH, HEIGHT), "Gradius - NES"),
  player1(),
  terrain() {
  if (not font.loadFromFile("./fonts/arial.ttf")) {
    std::cerr << "Could not load arial.ttf" << std::endl;
  }
}

Game::~Game () {
  for (auto enemy_i: enemy) delete enemy_i;
  for (auto bullet_i: bullet) delete bullet_i;
}

void Game::run () {
  while (window.isOpen()) {
    /* Preguntar las opciones con las que quiere jugar
    while (window.isOpen() and not playing) {
      showSetup();
      processSetupEvents();
    }
    */
    showCounter();
    while (window.isOpen()) {
      gotEvents = window.pollEvent(event);
      processPlayingEvents();
      processEvents();
      update();
      render();
      bool gotPaused = false;
      while (window.isOpen() and pause) {
        if (not gotPaused) showPausedMessage();
        gotEvents = window.pollEvent(event);
        processEvents();
        gotPaused = true;
      }
      if (gotPaused) showCounter();
    }
    /* Mostrar su score y preguntar si quiere jugar d nuev
    while (window.isOpen()) {
      showResult();
      processResultEvents();
    }
    */
  }
}

void Game::showCounter () {
  for (std::string msg: {"1", "2", "3", "GO"}) {
    render();
    sf::Text text;
    text.setFont(font);
    text.setString(msg);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Blue);
    text.setStyle(sf::Text::Bold);
    window.draw(text);
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

void Game::showPausedMessage () {
  sf::Text text;
  text.setFont(font);
  text.setString("Pausa");
  text.setCharacterSize(50);
  text.setFillColor(sf::Color::Blue);
  text.setStyle(sf::Text::Bold);
  window.draw(text);
  window.display();
}

void Game::showSetup () {
}

void Game::showResult () {

}

void Game::processEvents () {
  if (gotEvents) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
    if (event.type == sf::Event::KeyPressed and
        event.key.code == sf::Keyboard::Escape) {
      window.close();
    }
    if (event.type == sf::Event::KeyPressed and
        event.key.code == sf::Keyboard::P) {
      pause = 1 - pause;
    }
  }
}

void Game::processSetupEvents () {
}

void Game::processPlayingEvents () {
  if (gotEvents) {
    if (event.type == sf::Event::KeyPressed and
        (event.key.code == sf::Keyboard::Up or
         event.key.code == sf::Keyboard::W)) {
      player1.setDirection(UNCHANGED, UP);
    }
    if (event.type == sf::Event::KeyPressed and
        (event.key.code == sf::Keyboard::Down or
         event.key.code == sf::Keyboard::S)) {
      player1.setDirection(UNCHANGED, DOWN);
    }
    if (event.type == sf::Event::KeyPressed and
        (event.key.code == sf::Keyboard::Left or
         event.key.code == sf::Keyboard::A)) {
      player1.setDirection(LEFT, NOMOVE);
    }
    if (event.type == sf::Event::KeyPressed and
        (event.key.code == sf::Keyboard::Right or
         event.key.code == sf::Keyboard::D)) {
      player1.setDirection(RIGHT, NOMOVE);
    }
    if (event.type == sf::Event::KeyPressed and
        event.key.code == sf::Keyboard::Space) {
      bullet.emplace_back(new Bullet(player1.getPosition(), RIGHT));
    }
  }
}

void Game::hundleCollisionBulletEnemy () {
  for (Bullet* b: bullet) {
    for (Enemy* e: enemy) {
      // Aqui hacer los chequeos
    }
  }
}

void Game::hundleCollisions () {
  hundleCollisionBulletEnemy();
}

void Game::update () {
  if (cntEnemy01 <= 0) {
    enemy.emplace_back(new Enemy01());
    cntEnemy01 = E01::cnt;
  }
  player1.update();
  terrain.update();
  for (auto enemy_i: enemy) enemy_i -> update(player1.getPosition());
  for (auto bullet_i: bullet) bullet_i -> update();
  cntEnemy01 -= 1;
  hundleCollisions();
}

void Game::render () {
  window.clear();
  terrain.render(window);
  player1.render(window);
  for (auto enemy_i: enemy) enemy_i -> render(window);
  for (auto bullet_i: bullet) bullet_i -> render(window);
  window.display();
}
