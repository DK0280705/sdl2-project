#pragma once

class Scene
{
public:
    Scene(class Game* game, int x, int y, int w, int h);
    virtual ~Scene();
    
    SDL_Rect rect;

    virtual void update(float delta) = 0;

protected:
    class Game* game_;
};