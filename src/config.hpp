#ifndef HARD_VALUES
#define HARD_VALUES

#include <SFML/Graphics.hpp>
#include <vector>

#define all(X) begin(X), end(X)

// TITLES
static std::string GAME_NAME = "Gradius - NES";

// Font
static std::string FONT = "arial.ttf";

// Counter
namespace COUNTER {
  static std::vector <std::string> MSG = {"1", "2", "3", "GO"};
  static int TEXT_SIZE = 50;
  static int LAPSE = 1000;
}

// Pause
namespace PAUSE {
  static std::string MSG = "PAUSA";
  static int TEXT_SIZE = 50;
}

// KEYS
namespace KEY {
  static std::vector <int> UP = {sf::Keyboard::Up, sf::Keyboard::W};
  static std::vector <int> DOWN = {sf::Keyboard::Down, sf::Keyboard::S};
  static std::vector <int> LEFT = {sf::Keyboard::Left, sf::Keyboard::D};
  static std::vector <int> RIGHT = {sf::Keyboard::Right, sf::Keyboard::A};
  static std::vector <int> ATTACK = {sf::Keyboard::Space};
  static int EXIT = sf::Keyboard::Escape;
  static int PAUSE = sf::Keyboard::P;
}

// States
enum class State {
  WIN,
  LOSE,
  PLAYING
};

// Directions
namespace DIR {
  static int UNCHANGED = -2;
  static int NOMOVE = -1;
  static int UP = 0;
  static int LEFT = 1;
  static int DOWN = 2;
  static int RIGHT = 3;
}

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
  static sf::Vector2f position = {100.f, 100.f};
  static float movementSpeedX = WIDTH * 0.015F / FRAMES;
  static float movementSpeedY = WIDTH * 0.015F / FRAMES;
}

// Enemy 01
namespace E01 {
  static float movementSpeed = WIDTH * 0.015f / FRAMES;
  static float radius = 15.f;
  static sf::Color color = sf::Color::Green;
  static double d = E01::radius * 2.5f;
  static double x = WIDTH;
  static double y = HEIGHT / 2.f;
  static int nEnemies = 5;
  static std::vector <std::pair <float, float>> positions = {
    {0, 0},
    {d, -d}, {d, d},
    {2 * d, -2 * d}, {2 * d, 2 * d}
  };
  static float frec = 0.5;
  static int cnt = FRAMES * 50;
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

