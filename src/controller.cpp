#include "controller.h"
#include <iostream>
#include "SDL.h"

Controller::Controller(int width, int height)
{
  _mm = new MotionModel(width, height);
}

void Controller::HandleInput(bool &running, MFalcon &falcon) const 
{
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      Position pos = falcon.GetPosition();
      // ship speed
      int speed = falcon.GetSpeed();
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          _mm->MoveUp(&pos, speed);
         break;
        case SDLK_DOWN:
          _mm->MoveDown(&pos, speed);
          break;
        case SDLK_LEFT:
          _mm->MoveLeft(&pos, speed);
          break;
        case SDLK_RIGHT:
          _mm->MoveRight(&pos, speed);
          break;
        case SDLK_SPACE:    
          falcon.Shoot();
        break;
      }

      // Check if new position is OK
      if (_mm->IsItemOnScreen(pos, falcon.GetSize()))
      {

        std::cout << pos.x << " " << pos.y << std::endl;
        // Update position
        falcon.SetPosition(pos);
      }
    }
  }
}