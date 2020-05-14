#include <iostream>
#include <SDL.h>
#include <string>

bool SDLIsInitialized = false;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* hello;

bool Initialize();
void CleanUp();
bool LoadResources();
SDL_Texture* LoadTextureFromImageFile(std::string imageFilePath);

bool Initialize()
{
  if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
  {
    return 0;
  }

  window = SDL_CreateWindow("Platformer Shooter",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            800,
                            800,
                            SDL_WINDOW_SHOWN);
  if ( window == nullptr )
  {
    return 1;
  }

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

bool LoadResources()
{
  hello = LoadTextureFromImageFile("hello.bmp");
  return hello != nullptr;
}

SDL_Texture* LoadTextureFromImageFile(std::string imageFilePath)
{
  SDL_Surface* bmp = SDL_LoadBMP(imageFilePath.c_str());
  if ( bmp == nullptr )
  {
    std:: cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
    return nullptr;
  }
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, bmp);
  if ( texture == nullptr )
  {
    std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    return 0;
  }
  SDL_FreeSurface(bmp);

  return texture;
}

int main(int argc, char* argv[])
{
  if (!Initialize())
  {
    std::cout << "Error with initialization." << std::endl;
    return 1;
  }
  
  LoadResources();

  int startTime = SDL_GetTicks();
  while ( SDL_GetTicks() - startTime < 5000 )
  {
    SDL_PumpEvents();
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, hello, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  CleanUp();

  return 0;
}
