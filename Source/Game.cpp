#include "Game.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <algorithm>
#include "Utilities/Math.h"
#include "Actors/Actor.h"
#include "Actors/SpriteComponent.h"
#include "Renderer.h"

Game::Game()
{
    SDLIsInitialized = false;
    window = nullptr;
    ticksCount = 0;
}

bool Game::Initialize()
{
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        return 0;
    }

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        return 0;
    }
    
    window = SDL_CreateWindow("Top Down Game",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            800,
                            800,
                            SDL_WINDOW_SHOWN);

    if ( window == nullptr )
    {
        return 0;
    }
    
    renderer = new Renderer();
    if (!renderer->Initialize(window))
        return 0;

    AmIRunning = true;

    Actor* addActor = new Actor(this);
    addActor->SetPosition({100, 400});
    AddActor(addActor);

    new SpriteComponent(addActor, "player", "Assets/PNG/Survivor 1/survivor1_gun.png");

    return 1;
}

void Game::CleanUp()
{
    while (!actors.empty())
    {
        delete actors.back();
    }

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
    // fps cap
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + 16))
        ;

    // clamp delta time to avoid exceptionally big values
    float deltaTime = (SDL_GetTicks() - ticksCount) / 1000.0f;
    if (deltaTime > 0.05f)
    {
        deltaTime = 0.05f;
    }
    ticksCount = SDL_GetTicks();

    for (auto actor : actors)
    {
        actor->Update(deltaTime);
        // temp
        Vector2 pos = actor->GetPosition();
        actor->SetPosition({pos.x + 1, pos.y});
    }
}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer->SDLRenderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer->SDLRenderer);
    
    for (auto sprite : sprites)
    {
        sprite->Draw();
    }

    SDL_RenderPresent(renderer->SDLRenderer);
}

void Game::AddActor(Actor* actor)
{
    actors.emplace_back(actor);
}

void Game::RemoveActor(Actor* actor)
{
    auto iter = std::find(actors.begin(), actors.end(), actor);
    if (iter != actors.end())
    {
        std::iter_swap(iter, actors.end() - 1);
        actors.pop_back();
    }
}

void Game::AddSprite(SpriteComponent* sprite)
{
    sprites.push_back(sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
    auto iter = std::find(sprites.begin(), sprites.end(), sprite);
    sprites.erase(iter);
}
