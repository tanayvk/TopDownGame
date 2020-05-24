#include "Actor.h"
#include "../Game.h"
#include "MoveComponent.h"
#include "../Renderer.h"
#include "../Utilities/Math.h"

MoveComponent::MoveComponent(Actor* owner, float vel)
	:ActorComponent(owner)
	,velocity(vel)
{
  direction = new Vector2(0, 0);
}

MoveComponent::~MoveComponent()
{
}

void MoveComponent::Update(float deltaTime)
{
  Vector2 pos = owner->GetPosition();
  owner->SetPosition(Vector2(pos.x + velocity * direction->x * deltaTime,
                             pos.y + velocity * direction->y * deltaTime));
}

void MoveComponent::Move(Vector2 direction)
{
  this->direction->x = direction.x;
  this->direction->y = direction.y;
}
