#pragma once
#include "ActorComponent.h"
#include <SDL.h>

class SpriteComponent : public ActorComponent
{
public:
    SpriteComponent(class Actor* theOwner, std::string theTextureId, std::string filePath);
    ~SpriteComponent();

    virtual void Draw();
protected:
    int texWidth;
    int texHeight;
    std::string textureId;
};
