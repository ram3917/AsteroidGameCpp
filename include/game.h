#ifndef GAME_H_
#define GAME_H_

#include <random>
#include "SDL.h"
#include "renderer.h"
#include "controller.h"
#include "mfalcon.h"

class Game
{
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

 private:
  MFalcon _falcon;
  // laser shot position (s)
  // Asteroid positions

  std::random_device dev;
  std::mt19937 engine;
  
  int score{0};

  void Update();
};

#endif