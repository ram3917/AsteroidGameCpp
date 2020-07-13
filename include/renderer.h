/*
    Renders the game

    Part of code are taken from https://github.com/udacity/CppND-Capstone-Snake-Game
*/

#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "mfalcon.h"
#include "asteroid.h"

class Renderer {
  public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void Render(MFalcon& falcon, std::vector<std::shared_ptr<Asteroid>>& asteroids);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif