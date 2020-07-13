#include "renderer.h"
#include <iostream>
#include <string>

/*
* Assets used in this game are taken from 
* https://opengameart.org/content/space-shooter-extension-250 
*/

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Asteroid Shooter", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(MFalcon& falcon,
     std::vector<std::shared_ptr<Asteroid>>& asteroids)
{
  SDL_Rect block;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render falcon ship 
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0xFF, 0x00, 0xFF);

  // X and Y transpose
  auto pos  = falcon.GetPosition();
  auto size = falcon.GetSize();

  // Set pos and size
  block.x = pos.y;
  block.y = pos.x;
  block.w = size.w;
  block.h = size.h;

  SDL_RenderFillRect(sdl_renderer, &block);

  // TODO : Update laser bullets
  
  // Render Asteroids  
  for (auto& a : asteroids)
  {
      // Render falcon ship 
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);

    // X and Y transpose
    auto pos  = a->GetPosition();
    auto size = a->GetSize();

    // Set pos and size
    block.x = pos.y;
    block.y = pos.x;
    block.w = size.w;
    block.h = size.h;

    SDL_RenderFillRect(sdl_renderer, &block);
  }

  auto bullets = falcon.GetBullets();
  for (auto b : bullets)
  {
      // Render falcon ship 
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0x00, 0xFF);

    // X and Y transpose    
    auto pos = b.GetPosition();
    auto size = b.GetSize();

    // Set pos and size
    block.x = pos.y;
    block.y = pos.x;
    block.w = size.w;
    block.h = size.h;

    SDL_RenderFillRect(sdl_renderer, &block);
  }
  
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
