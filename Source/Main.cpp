#include <iostream>
#include <SDL.h>

bool SDLIsInitialized = false;
SDL_Window* window;
SDL_Renderer* renderer;

bool Initialize()
{
  // Initialize SDL
  if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    return 0;
  }

  // Create Window
  window = SDL_CreateWindow("Platformer Shooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    800, 800, SDL_WINDOW_SHOWN);
  if ( window == nullptr )
  {
    return 1;
  }

  // Create Renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if ( renderer == nullptr )
  {
    return 1;
  }

  return 1;
}

void CleanUp()
{
  if ( renderer != nullptr )
    SDL_DestroyRenderer(renderer);
  if ( window != nullptr )
    SDL_DestroyWindow(window);
  if (SDLIsInitialized)
    SDL_Quit();
}

int main(int argc, char* argv[])
{
  if (!Initialize())
  {
    std::cout << "Error with initialization." << std::endl;
    return 1;
  }

  std::cout << "Successfully initialized SDL, created window and renderer." << std::endl;

  CleanUp();

  return 0;
}
