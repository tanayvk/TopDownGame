#include "Game.h"
#include <iostream>
#include <string>
#include <SDL.h>

Game::Game()
{
  SDLIsInitialized = false;
  window = nullptr;
}

bool Game::Initialize()
{
  if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
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
    return 0;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if ( renderer == nullptr )
  {
    return 0;
  }
  
  AmIRunning = true;
  return 1;
}

void Game::CleanUp()
{
  if ( renderer != nullptr )
    SDL_DestroyRenderer(renderer);
  if ( window != nullptr )
    SDL_DestroyWindow(window);
  if (SDLIsInitialized)
    SDL_Quit();
}

void Game::Loop()
{
  ProcessInput();
  Update();
  Render();
}

void Game::ProcessInput()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch(event.type)
    {
    case SDL_QUIT: 
      AmIRunning = false;
    }
  }
}

void Game::Update()
{

}

void Game::Render()
{

}

