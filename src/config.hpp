#ifndef HARD_VALUES
#define HARD_VALUES

#include <SFML/Graphics.hpp>
#include <vector>

#define all(X) begin(X), end(X)

// TITLES
static std::string GAME_NAME = "Gradius - NES";

// Window size
static int WIDTH = 1200;
static int HEIGHT = 600;

// Resources paths
static std::string FONT_PATH = "./fonts/arial.ttf";
static std::string SPACESHIP_PATH = "./images/spaceship1.png";
static std::string ENEMY01_PATH = "./images/enemy01.png";
static std::string LOGO_PATH = "./images/logo.png";
static std::string BULLET1_PATH = "./images/bullet1.png";
static std::string BULLET2_PATH = "./images/bullet2.png";
static std::string BACKGROUND_MUSIC_PATH = "./sound/background-music.wav";

// Intro
namespace IntroConf {
  static int PLAY = 0;
  static int EXIT = 1;
  static int TEXT_SIZE = 80;
  static int PADDING = 10;
  static std::string OPTION1 = "PLAY";
  static sf::Vector2f POS1(WIDTH / 2.f, HEIGHT / 2.f);
  static std::string OPTION2 = "EXIT";
  static sf::Vector2f POS2(WIDTH / 2.f, HEIGHT / 2.f + TEXT_SIZE + PADDING);
  static float RADIUS = TEXT_SIZE / 2.f;
  static std::vector <sf::Vector2f> SPACESHIP_POS = {
    {WIDTH / 2.f - 3 * RADIUS, HEIGHT / 2.f},
    {WIDTH / 2.f - 3 * RADIUS, HEIGHT / 2.f + TEXT_SIZE + PADDING}};
  static sf::Vector2f LOGO_SIZE(600.f, 130.f);
  static sf::Vector2f LOGO_POS(2 * WIDTH / 7.f, 100.f);
}

// Exit
namespace ExitConf {
  static int AGAIN = 0;
  static int EXIT = 1;
  static int TEXT_SIZE = 80;
  static int PADDING = 10;
  static std::string OPTION1 = "AGAIN";
  static sf::Vector2f POS1(WIDTH / 2.f, HEIGHT / 2.f);
  static std::string OPTION2 = "EXIT";
  static sf::Vector2f POS2(WIDTH / 2.f, HEIGHT / 2.f + TEXT_SIZE + PADDING);
  static float RADIUS = TEXT_SIZE / 2.f;
  static std::vector <sf::Vector2f> SPACESHIP_POS = {
    {WIDTH / 2.f - 3 * RADIUS, HEIGHT / 2.f},
    {WIDTH / 2.f - 3 * RADIUS, HEIGHT / 2.f + TEXT_SIZE + PADDING}};
}


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

// Score
namespace SCORE {
  static int TEXT_SIZE = 40;
  static sf::Vector2f POS(0, HEIGHT - TEXT_SIZE);
}

// KEYS
namespace KEY {
  static std::vector <int> UP = {sf::Keyboard::Up, sf::Keyboard::W};
  static std::vector <int> DOWN = {sf::Keyboard::Down, sf::Keyboard::S};
  static std::vector <int> LEFT = {sf::Keyboard::Left, sf::Keyboard::D};
  static std::vector <int> RIGHT = {sf::Keyboard::Right, sf::Keyboard::A};
  static std::vector <int> ATTACK = {sf::Keyboard::Space};
  static int SPACE = sf::Keyboard::Space;
  static int EXIT = sf::Keyboard::Escape;
  static int PAUSE = sf::Keyboard::P;
  static int ENTER = sf::Keyboard::Return;
}

// States
enum class State {
  LOSE,
  PLAYING,
  INTRO,
  EXIT
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

// Frames per second
static int FRAMES = 60;

// up, left, down, right vector directions
static std::vector <int> dx = {0, -1, 0, 1};
static std::vector <int> dy = {-1, 0, 1, 0};

// Player
namespace PLAYER {
  static float RADIUS = 40.f;
  static sf::Vector2f position = {100.f, 100.f};
  static float movementSpeedX = WIDTH * 0.015F / FRAMES;
  static float movementSpeedY = WIDTH * 0.015F / FRAMES;
}

// Enemy 01
namespace E01 {
  static int score = 50;
  static float movementSpeed = WIDTH * 0.015f / FRAMES;
  static float radius = 30.f;
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
  static sf::Vector2f dimensions(35.f, 15.f);
  static sf::Color color = sf::Color::Yellow;
  static float dx = 0.3f;
}

#endif

