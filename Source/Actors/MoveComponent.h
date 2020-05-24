#pragma once
#include "../Utilities/Math.h"
#include "ActorComponent.h"

class MoveComponent : public ActorComponent
{
public:
    MoveComponent(class Actor* theOwner, float velocity);
    ~MoveComponent();
  
    void Move(Vector2 direction);

    void Update(float deltaMs);

    float GetVelocity() { return velocity; }
    void SetVelocity(float vel) { velocity = vel; }
private:
    float velocity;
    Vector2* direction;
};
