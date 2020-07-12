#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running, MFalcon &falcon) const 
{
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          falcon.MoveUp();
          break;

        case SDLK_DOWN:
          falcon.MoveDown();
          break;

        case SDLK_LEFT:
          falcon.MoveLeft();
          break;

        case SDLK_RIGHT:
          falcon.MoveRight();
          break;
        case SDLK_SPACE:
            std::cout << "shoot /n";
        break;
      }
    }
  }
}