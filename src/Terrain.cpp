#include "Terrain.hpp"

Terrain::Terrain ():
  rng(std::chrono::steady_clock::now().time_since_epoch().count()) {
  for (int i = 0; i < Start::N_STARTS; i++) {
    int x = rng() % WIDTH;
    int y = rng() % HEIGHT;
    float dr = -Start::var + fmod(rng(), 2 * Start::var);
    sf::CircleShape start;
    start.setRadius(Start::radius + dr);
    start.setPosition(x, y);
    start.setFillColor(Start::color); 
    starts.push_back(start);
  } 
}

Terrain::~Terrain () {
}

void Terrain::update () {
  for_each(all(starts), [&] (sf::CircleShape& start) {
    sf::Vector2f pos = start.getPosition();
    pos.x = fmod(pos.x - Start::xVel + WIDTH, WIDTH);
    int dy = -1 + (rng() % 3);
    pos.y = fmod(pos.y + dy * Start::yVel + HEIGHT, HEIGHT);
    start.setPosition(pos);
  });
}

void Terrain::render (sf::RenderWindow& window) {
  for (auto start: starts) window.draw(start);
}
