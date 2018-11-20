#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include "config.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <random>

class Terrain {
public:
  Terrain ();
  ~Terrain ();
  void render (sf::RenderWindow& window);
  void update ();
private:
  std::mt19937 rng; 
  std::vector <sf::CircleShape> starts;
};

#endif
