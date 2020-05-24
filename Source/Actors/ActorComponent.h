#pragma once
#include <memory>

class ActorComponent {
  
public:
  ActorComponent(class Actor* ownerActor);
  virtual ~ActorComponent();
  virtual void Update(float deltaMs);

protected:
  class Actor* owner;

};
