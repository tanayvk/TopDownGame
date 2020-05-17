#pragma once
#include <vector>
#include "../Utilities/Math.h"

class Actor
{
  friend class Game;
  friend class ActorComponent;
public:
  Actor(class Game* game);
  ~Actor();
  bool Initialize();
  void Update(float deltaMs);

  const Vector2& GetPosition() const { return position; }
	void SetPosition(const Vector2& pos) { position = pos; }

  class Game* GetGame() { return game; }
private:
  Vector2 position;
  std::vector<class ActorComponent*> components;

  void UpdateActor(float deltaMs);
  void UpdateComponents(float deltaMs);

  void Destroy();
  void AddComponent(class ActorComponent* theComponent);
  void RemoveComponent(class ActorComponent* theComponent);

  class Game* game;
};
