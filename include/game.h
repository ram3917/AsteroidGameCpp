#ifndef GAME_H_
#define GAME_H_

#include <random>
#include <vector>
#include "SDL.h"
#include "renderer.h"
#include "controller.h"
#include "mfalcon.h"
#include "asteroid.h"
#include "motion_model.h"

class Game
{
 public:
  Game(std::size_t screen_width, std::size_t screen_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

  bool IsItemOnScreen(const Position& pos, const Size& size) const;

 private:

  // Defines motion in space
  MotionModel* _mm;

  MFalcon* _falcon;
  // laser shot position (s)
  // Asteroids
  std::vector<Asteroid> _asteroids;
    
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_x;
  std::uniform_int_distribution<int> random_y;
  std::uniform_int_distribution<int> random_asteriods;
  
  int score{0};
  // Game area size
  int screenX { 0 };
  int screenY { 0 };

  void Update();
};

#endif