#pragma once
#include "ActorComponent.h"

class SpriteComponent : public ActorComponent
{
public:
    SpriteComponent(class Actor* theOwner, std::string theTextureId, std::string filePath);
    ~SpriteComponent();

    void Draw();
    void Update(float deltaMs);
protected:
    int texWidth;
    int texHeight;
    std::string textureId;
};
