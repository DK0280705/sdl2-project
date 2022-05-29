#pragma once
#include <vector>

extern bool terminating;

constexpr int SCREEN_WIDTH  = 1280;
constexpr int SCREEN_HEIGHT = 720;

class Scene;

class Game
{
    Game(SDL_Window* w, SDL_Renderer* r) noexcept;
    static Game* _p_instance;
public:
    static Game& init(SDL_Window* w, SDL_Renderer* r);
    static Game& get();

    Game(const Game&) = delete;
    Game operator=(const Game&) = delete;

    ~Game();

    struct SDL_Window* window;
    struct SDL_Renderer* renderer;

    std::vector<Scene*> scenes;

    void update(float delta);
};