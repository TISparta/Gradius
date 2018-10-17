#include "Game.hpp"
#include <iostream>

Game::Game ():
  window(sf::VideoMode(WIDTH, HEIGHT), "Gradius - NES"),
  player1(),
  terrain() {
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
  /*const sf::Time TimePerFrame = sf::seconds(1.f/60.f);
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Time elapsedTime;

  
  elapsedTime = clock.restart();
  timeSinceLastUpdate += elapsedTime;*/
  bool play = true;
  if (play){
    player1.setDirection(dx[RIGHT],dy[RIGHT]);

    if(sf::Event::KeyPressed){
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        player1.setDirection(dx[UP],dy[UP]);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        player1.setDirection(dx[LEFT],dy[LEFT]);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        player1.setDirection(dx[DOWN],dy[DOWN]);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        player1.setDirection(dx[RIGHT],dy[RIGHT]);
      }

    }


  }

}

bool ok = true;

void Game::update () {
  if (ok) {
    bullet.emplace_back(new Bullet(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f), RIGHT));
    ok = false;
  }
  if (cntEnemy01 <= 0) {
    enemy.emplace_back(new Enemy01());
    cntEnemy01 = E01::cnt;
  }
  terrain.update();
  for (auto enemy_i: enemy) enemy_i -> update(player1.getPosition());
  for (auto bullet_i: bullet) bullet_i -> update();
  cntEnemy01 -= 1;
}

void Game::render () {
  window.clear();
  terrain.render(window);
  player1.render(window);
  for (auto enemy_i: enemy) enemy_i -> render(window);
  for (auto bullet_i: bullet) bullet_i -> render(window);
  window.display();
}
