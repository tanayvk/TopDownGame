#include "Actor.h"
#include "../Game.h"
#include "SpriteComponent.h"
#include "../Renderer.h"

SpriteComponent::SpriteComponent(Actor* theOwner, std::string theTextureId, std::string filePath)
	:ActorComponent(theOwner)
	,textureId(theTextureId)
{
	owner->GetGame()->GetRenderer()->AddTexture(theTextureId, filePath);
	owner->GetGame()->GetRenderer()->QueryTexture(theTextureId, &texWidth, &texHeight);
	owner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	owner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw()
{
	owner->GetGame()->GetRenderer()->DrawTexture(textureId, owner->GetPosition().x,
														owner->GetPosition().y,
														texWidth,
														texHeight);
}

void SpriteComponent::Update(float deltaTime)
{
}
