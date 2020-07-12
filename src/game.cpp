#include "game.h"
#include <iostream>
#include <algorithm>
#include "SDL.h"

Game::Game(std::size_t screen_width, std::size_t screen_height)
    : engine(dev()),
      screenX(screen_width), screenY(screen_height),
      random_x(0, static_cast<int>(screen_height)),
      random_y(0, static_cast<int>(screen_width)),
      random_asteriods(0, 3)
{ 
  _mm = new MotionModel(screen_width, screen_height);

  // Instatiate Falcon
  _falcon = new MFalcon(static_cast<int>(screen_width - (screen_width / 10)),
            static_cast<int>(screen_height / 2));
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, *_falcon);
    Update();
    renderer.Render(*_falcon, _asteroids);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update() {
  if (!_falcon->IsAlive()) return;

  // Update bullet positions
  _falcon->UpdateBullets();

  // Update asteroid positions
  for (auto& a : _asteroids)
  {
    Position pos = a.GetPosition();
    int speed = a.GetSpeed();
    _mm->MoveDown(&pos, speed);
    // Update position
    a.SetPosition(pos);
  }

  // Get all asteroids out of arena
  auto end = std::remove_if(_asteroids.begin(), _asteroids.end(),
              [this](Asteroid& a)                        
  { return !_mm->IsItemOnScreen(a.GetPosition(), a.GetSize()); });  
  _asteroids.erase(end, _asteroids.end());

  // Add new asteroids
  if (_asteroids.size() < 5)
  {
    for (int iter = 0; iter <= random_asteriods(engine); ++iter)
    {
      // Instantiate an asteroid in space
      Asteroid asteroid(random_y(engine), random_x(engine));

      // Add to list
      _asteroids.emplace_back(asteroid);
    }
  }
  
  // Check if asteroid collides with ship
  // !!!GAME OVER!!!

}

int Game::GetScore() const { return score; }