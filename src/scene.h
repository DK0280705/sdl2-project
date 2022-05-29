#pragma once

class Scene
{
    struct SDL_Rect rect;
public:
    Scene(int x, int y, int h, int w);
    virtual ~Scene();
    virtual void update(float delta) = 0;
};