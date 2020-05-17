#pragma once
#include "ActorComponent.h"
#include <SDL.h>

class SpriteComponent : public ActorComponent
{
public:
  SpriteComponent(class Actor* theOwner);
  ~SpriteComponent();

  virtual void Draw(SDL_Renderer* renderer);
};
