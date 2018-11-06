#ifndef HARD_VALUES
#define HARD_VALUES

#include <SFML/Graphics.hpp>
#include <vector>

#define all(X) begin(X), end(X)

// Directions
static int UNCHANGED = -2;
static int NOMOVE = -1;
static int UP = 0;
static int LEFT = 1;
static int DOWN = 2;
static int RIGHT = 3;

// Window size
static int WIDTH = 1200;
static int HEIGHT = 600;

// Frames per second
static int FRAMES = 60;

// up, left, down, right vector directions
static std::vector <int> dx = {0, -1, 0, 1};
static std::vector <int> dy = {-1, 0, 1, 0};

// Player
namespace PLAYER {
  static float movementSpeedX = WIDTH * 0.015F / FRAMES;
  static float movementSpeedY = WIDTH * 0.015F / FRAMES;
}

// Enemy 01
namespace E01 {
  static float movementSpeed = WIDTH * 0.015f / FRAMES;
  static int directionX = LEFT;
  static int attackSpeed = 1;
  static int lives = 1;
  static int score = 10;
  static float radius = 15.f;
  static sf::Color color = sf::Color::Green;
  static double d = E01::radius * 2.5f;
  static double x = WIDTH;
  static double y = HEIGHT / 2.f;
  static std::vector <std::pair <float, float>> positions = {
    {0, 0},
    {d, -d}, {d, d},
    {2 * d, -2 * d}, {2 * d, 2 * d}
  };
  static int cnt = FRAMES * 50; // Cada 5 segundos
}

// Terrain
namespace Start {
  static int N_STARTS = WIDTH * HEIGHT / 5000;
  static float radius = 0.7f;
  static float var = 0.3f;
  static sf::Color color = sf::Color::White;
  static float xVel = WIDTH * 0.012f / FRAMES;
  static float yVel = HEIGHT * 0.0001f / FRAMES;
}

// Bullet
namespace BulletConf {
  static sf::Vector2f dimensions(30.f, 10.f);
  static sf::Color color = sf::Color::Yellow;
  static float dx = 0.2f;
}

#endif

