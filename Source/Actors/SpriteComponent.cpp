#include "SpriteComponent.h"
#include "Actor.h"
#include "../Game.h"

SpriteComponent::SpriteComponent(Actor* theOwner)
	:ActorComponent(theOwner)
{
  SDL_Log("reached here..");
	theOwner->GetGame()->AddSprite(this);
  SDL_Log("Adding guy to the game sprites...");
}

SpriteComponent::~SpriteComponent()
{
	//owner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
  SDL_Rect r;
  r.x = (owner->GetPosition()).x - 25;
  r.y = (owner->GetPosition()).y - 25;
  r.w = 50;
  r.h = 50;

  SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

  SDL_RenderFillRect( renderer, &r );
}
