#include "Actor.h"
#include "../Game.h"
#include "ActorComponent.h"
#include <algorithm>

Actor::Actor(Game* theGame)
	:position({0, 0})
	,game(theGame)
{
	game->AddActor(this);
}

Actor::~Actor()
{
	game->RemoveActor(this);
	while (!components.empty())
	{
		delete components.back();
	}
}

void Actor::Update(float deltaTime)
{
  UpdateComponents(deltaTime);
  UpdateActor(deltaTime);
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto comp : components)
	{
		comp->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{
}

void Actor::AddComponent(ActorComponent* component)
{
	components.push_back(component);
}

void Actor::RemoveComponent(ActorComponent* component)
{
	auto iter = std::find(components.begin(), components.end(), component);
	if (iter != components.end())
	{
		components.erase(iter);
	}
}
