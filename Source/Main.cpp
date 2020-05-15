#include "Game.h"
#include <iostream>

//bool LoadResources();
//SDL_Texture* LoadTextureFromImageFile(std::string imageFilePath);

//bool LoadResources()
//{
//  hello = LoadTextureFromImageFile("hello.bmp");
//  return hello != nullptr;
//}

//SDL_Texture* LoadTextureFromImageFile(std::string imageFilePath)
//{
//  SDL_Surface* bmp = SDL_LoadBMP(imageFilePath.c_str());
//  if ( bmp == nullptr )
//  {
//    std:: cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
//    return nullptr;
//  }
//  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, bmp);
//  if ( texture == nullptr )
//  {
//    std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
//    return 0;
//  }
//  SDL_FreeSurface(bmp);
//
//  return texture;
//}

int main(int argc, char* argv[])
{
  Game* game = new Game();
  if (!game->Initialize())
  {
    std::cout << "Error with initialization." << std::endl;
    return 1;
  }

  while ( game->IsRunning() )
  {
    game->Loop();
  }

  game->CleanUp();

  return 0;
}
