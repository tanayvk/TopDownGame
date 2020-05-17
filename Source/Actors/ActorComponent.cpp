#include "ActorComponent.h"
#include "Actor.h"

ActorComponent::ActorComponent(Actor* theOwner)
	:owner(theOwner)
{
	owner->AddComponent(this);
}

ActorComponent::~ActorComponent()
{
	owner->RemoveComponent(this);
}

void ActorComponent::Update(float deltaTime)
{
}
