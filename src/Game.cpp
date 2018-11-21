#include "Game.hpp"
#include "util.hpp"
#include <iostream>
#include <chrono>
#include <thread>

Game::Game ():
  window(sf::VideoMode(WIDTH, HEIGHT), GAME_NAME),
  terrain() {
  pause = false;
  gotEvents = false;
  cntEnemy01 = 0;
  load(font, FONT_PATH); 
  load(textureSpaceship, SPACESHIP_PATH);
  load(textureEnemy01, ENEMY01_PATH);
  load(textureLogo, LOGO_PATH);
  load(textureBullet1, BULLET1_PATH);
  load(textureBullet2, BULLET2_PATH);
  player = Player(textureSpaceship, textureBullet2);
}

Game::~Game () {
  for (auto enemy_i: enemy) delete enemy_i;
}

void Game::run () {
  while (window.isOpen()) {
    menu = Menu(font, textureSpaceship, textureLogo);
    state = State::MENU;
    // Menu
    while (window.isOpen() and state == State::MENU) {
      gotEvents = window.pollEvent(event);
      processWindowEvents();
      processMenuEvents();
      terrain.update();
      window.clear();
      terrain.render(window);
      menu.render(window);
      window.display();
    }
    showCounter();
    pause = false;
    // Game
    while (window.isOpen()) {
      gotEvents = window.pollEvent(event);
      processPlayingEvents();
      processWindowEvents();
      bool gotPaused = pause;
      while (window.isOpen() and pause) {
        if (gotPaused) showPausedMessage();
        gotEvents = window.pollEvent(event);
        processWindowEvents();
      }
      if (gotPaused) showCounter();
      update();
      render();
      if (state != State::PLAYING) break;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(COUNTER::LAPSE));
    reset();
  }
}

void Game::reset () {
  player = Player(textureSpaceship, textureBullet2);
  enemy.clear();
  state = State::PLAYING;
  pause = false;
  gotEvents = false;
  cntEnemy01 = 0;
}

void Game::showCounter () {
  for (std::string msg: COUNTER::MSG) {
    render();
    sf::Text text;
    setText(text, msg, COUNTER::TEXT_SIZE, font);
    window.draw(text);
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(COUNTER::LAPSE));
  }
}

void Game::processPlayingEvents () {
  if (not gotEvents) return;
  if (event.type == sf::Event::KeyPressed) {
    int key = event.key.code;
    if (find(all(KEY::UP), key) != end(KEY::UP)) {
      player.setDirection(DIR::UNCHANGED, DIR::UP);
    }
    if (find(all(KEY::DOWN), key) != end(KEY::DOWN)) {
      player.setDirection(DIR::UNCHANGED, DIR::DOWN);
    }
    if (find(all(KEY::LEFT), key) != end(KEY::LEFT)) {
      player.setDirection(DIR::LEFT, DIR::NOMOVE);
    }
    if (find(all(KEY::RIGHT), key) != end(KEY::RIGHT)) {
      player.setDirection(DIR::RIGHT, DIR::NOMOVE);
    }
    if (find(all(KEY::ATTACK), key) != end(KEY::ATTACK)) {
      player.shoot();
    }
  }
}

void Game::processWindowEvents () {
  if (not gotEvents) return;
  if (event.type == sf::Event::Closed) {
    window.close();
  }
  if (event.type == sf::Event::KeyPressed) {
    int key = event.key.code;
    if (key == KEY::EXIT) window.close();
    if (key == KEY::PAUSE) pause = 1 - pause;
  }
}

void Game::processMenuEvents () {
  if (not gotEvents) return;
  if (event.type == sf::Event::KeyPressed) {
    int key = event.key.code;
    if (find(all(KEY::UP), key) != end(KEY::UP)) menu.move(-1);
    if (find(all(KEY::DOWN), key) != end(KEY::DOWN)) menu.move(1);
    if (key == KEY::ENTER or key == KEY::SPACE) {
      int id = menu.getId();
      if (id == MenuConf::EXIT) window.close();
      if (id == MenuConf::PLAY) state = State::PLAYING;
    }
  }
}

void Game::showPausedMessage () {
  sf::Text text;
  setText(text, PAUSE::MSG, PAUSE::TEXT_SIZE, font);
  terrain.update();
  render(false);
  window.draw(text);
  window.display();
}

void Game::update () {
  if (cntEnemy01 <= 0) {
    enemy.emplace_back(new Enemy01(textureEnemy01, textureBullet1));
    cntEnemy01 = E01::cnt;
  }
  terrain.update();
  for (auto enemy_i: enemy) enemy_i -> update(player.getPosition());
  player.update();
  cntEnemy01 -= 1;
  hundleCollisions();
}

void Game::hundleCollisions () {
  hundleCollisionWithEnemies();
  hundleCollisionWithPlayerBullets();
  hundleCollisionWithEnemyBullets();
}

void Game::hundleCollisionWithEnemies () {
  auto p = player.getPlayer();
  bool collision = false;
  for_each(all(enemy), [&] (auto enemy_i) {
    auto _enemy = enemy_i -> getEnemies();
    for_each(all(_enemy), [&] (auto e) {
      collision |= p.getGlobalBounds().intersects(e.getGlobalBounds());
    });
  });
  if (collision) state = State::LOSE;
}

void Game::hundleCollisionWithPlayerBullets () {
  auto bullets = player.getBullets(); 
  for_each(all(enemy), [&] (auto enemy_i) {
    auto _enemy = enemy_i -> getEnemies();
    for (int i = 0; i < int(_enemy.size()); i++) {
      for (int j = 0; j < int(bullets.size()); j++) {
        auto s1 = _enemy[i].getGlobalBounds();
        auto s2 = bullets[j] -> getBullet().getGlobalBounds();
        if (s1.intersects(s2)) {
          enemy_i -> setToDelete(i);
          player.setToDeleteBullet(j);
        }
      }
    } 
  });
}

void Game::hundleCollisionWithEnemyBullets () {
  auto p = player.getPlayer();
  for_each(all(enemy), [&] (auto enemy_i) {
    auto b = enemy_i -> getBullets();
    for (int i = 0; i < int(b.size()); i++) {
      auto s1 = p.getGlobalBounds();
      auto s2 = b[i] -> getBullet().getGlobalBounds();
      if (s1.intersects(s2)) {
        state = State::LOSE;
      }
    }
  });
}

void Game::render (bool display) {
  window.clear();
  terrain.render(window);
  for (auto enemy_i: enemy) enemy_i -> render(window);
  player.render(window);
  if (display) window.display();
}
