#pragma once

class Game
{
    constexpr Game(SDL_Window* w, SDL_Renderer* r) noexcept;
    static Game* _p_instance;
public:
    static Game& init(SDL_Window* w, SDL_Renderer* r);
    ~Game();

    struct SDL_Window* window;
    struct SDL_Renderer* renderer;

    void update();
};