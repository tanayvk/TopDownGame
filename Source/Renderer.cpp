#include "Renderer.h"
#include <SDL2/SDL_image.h>

bool Renderer::Initialize(SDL_Window* window)
{
    SDLRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if ( SDLRenderer == nullptr )
    {
        return 0;
    }
    return 1;
}    

void Renderer::CleanUp()
{
    if ( SDLRenderer != nullptr )
        SDL_DestroyRenderer(SDLRenderer);
}

SDL_Texture* Renderer::LoadTextureFromImageFile(std::string imageFilePath)
{
    SDL_Surface* bmp = IMG_Load(imageFilePath.c_str());
    if ( bmp == nullptr )
    {
        SDL_Log("SDL_LoadBMP Error: %s", SDL_GetError());
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(SDLRenderer, bmp);
    if ( texture == nullptr )
    {
        SDL_Log("SDL_CreateTextureFromSurface Error: %s", SDL_GetError());
        return 0;
    }
    SDL_FreeSurface(bmp);

    return texture;
}

void Renderer::AddTexture(std::string textureId, std::string imageFilePath)
{
    SDL_Texture* tex = LoadTextureFromImageFile(imageFilePath);
    if ( tex != nullptr )
        textures[textureId] = tex;
}

void Renderer::DrawTexture(std::string textureId, int x, int y, int w, int h)
{
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;

    SDL_RenderCopy(SDLRenderer, textures[textureId], NULL, &r);
}

void Renderer::QueryTexture(std::string textureId, int* texWidth, int* texHeight)
{
    SDL_Texture* tex = textures[textureId];
    SDL_QueryTexture(tex, nullptr, nullptr, texWidth, texHeight);
}
