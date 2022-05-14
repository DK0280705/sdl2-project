#pragma once

class Game
{
    Game(SDL_Window* w, SDL_Renderer* r) noexcept;
    static Game* _p_instance;
public:
    static Game& init(SDL_Window* w, SDL_Renderer* r);
    ~Game();

    struct SDL_Window* window;
    struct SDL_Renderer* renderer;
    
    typedef void* SDL_GLContext;
    SDL_GLContext context;

    void setup_opengl(int width, int height);
    void update();
};