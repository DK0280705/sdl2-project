#pragma once

class Game
{
    Game(SDL_Window* w) noexcept;
    static Game* _p_instance;
public:
    static Game& init(SDL_Window* w);

    Game(const Game&) = delete;
    Game operator=(const Game&) = delete;

    ~Game();

    struct SDL_Window* window;
    struct SDL_Renderer* renderer;
    
    typedef void* SDL_GLContext;
    SDL_GLContext context;

    void setup_opengl(int width, int height);
    void update(float delta);
};