#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Terrain {
public:
  Terrain ();
  ~Terrain ();
  void render (sf::RenderWindow& window);
private:
  void generateNewStar();
  void update ();
  std::vector <std::pair <float, float>> starts;
  // Por ahora mejor no nos preocupemos en dibujar la tierra, asteroides, etc
};

#endif
