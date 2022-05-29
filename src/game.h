#pragma once
#include <vector>

class Scene;

class Game
{
    Game(SDL_Window* w, SDL_Renderer* r) noexcept;
    static Game* _p_instance;
public:
    static Game& init(SDL_Window* w, SDL_Renderer* r);

    Game(const Game&) = delete;
    Game operator=(const Game&) = delete;

    ~Game();

    struct SDL_Window* window;
    struct SDL_Renderer* renderer;

    std::vector<Scene*> scenes;

    void update(float delta);
};