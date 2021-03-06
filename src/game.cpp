#include "game.h"
#include <iostream>
#include <algorithm>
#include "SDL.h"

Game::Game(std::size_t screen_width, std::size_t screen_height)
    : engine(dev()),
      screenX(screen_width), screenY(screen_height),
      random_x(0, static_cast<int>(screen_height)),
      random_y(0, static_cast<int>(screen_width/2)),
      random_asteriods(0, 3)
{ 
  _mm = std::make_unique<MotionModel>(std::move(MotionModel(screen_width, screen_height)));

  // Instatiate Falcon
  _falcon = std::make_shared<MFalcon>(std::move(MFalcon(static_cast<int>(screen_width - (screen_width / 10)),
            static_cast<int>(screen_height / 2))));
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
    controller.HandleInput(running, _falcon);

    // Stop if quit in controller
    if (!running)
      break;

    running = Update();
    renderer.Render(_falcon, _asteroids);

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

bool Game::Update() {

  // Update bullet positions
  _falcon->UpdateBullets(_asteroids);

  // get size before killing asteroids
  int sizeBefore = _asteroids.size();

  // Delete all destroyed asteroids
  _asteroids.erase(std::remove_if(_asteroids.begin(), _asteroids.end(),
              [](std::shared_ptr<Asteroid> a)                        
  { return !a->IsAlive(); }), _asteroids.end() );  

  // Update Score
  // Change in size is the number of asteroids killed.
  score += (sizeBefore - _asteroids.size());

  // Update asteroid positions
  bool isHit = true;
  for (auto& a : _asteroids)
  {
    Position pos = a->GetPosition();
    int speed = a->GetSpeed();
    _mm->MoveDown(&pos, speed);
    // Update position
    a->SetPosition(pos);

    // Check if falcon is not hit
    if (_mm->CheckCollision(pos, a->GetSize(),
     _falcon->GetPosition(), _falcon->GetSize()))
     {
        // GAME OVER
        return false;
     }
  }

  // Get all asteroids out of arena
  _asteroids.erase(std::remove_if(_asteroids.begin(), _asteroids.end(),
              [this](std::shared_ptr<Asteroid> a)                        
  { return !_mm->IsItemOnScreen(a->GetPosition(), a->GetSize()); }),
  _asteroids.end() );

  // Add new asteroids
  if (_asteroids.size() < 5)
  {
    for (int iter = 0; iter <= random_asteriods(engine); ++iter)
    {
      // Instantiate an asteroid in space
      Asteroid asteroid(random_y(engine), random_x(engine));

      // Add to list
      _asteroids.emplace_back(std::make_shared<Asteroid>(asteroid));
    }
  }

  // Keep running
  return true;
}

int Game::GetScore() const { return score; }