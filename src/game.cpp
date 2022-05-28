#include "pch.h"

#include "game.h"

Game* Game::_p_instance = 0;

Game::Game(SDL_Window* w) noexcept : window(w)
{
   context = SDL_GL_CreateContext(window);  
}

Game& Game::init(SDL_Window* w)
{
    static Game game(w);
    _p_instance = &game;
    return game;
}

void Game::setup_opengl(int width, int height)
{
    glViewport(0, 0, width, height);
}

void Game::update(float delta)
{
    static bool reverse = false;
    static float r = 0.0f;
    glClearColor(r, 0.3f, -r, 0.0f);
    r += (reverse ? -0.1f : 0.1f) * delta;
    if (r >= 1.0f) reverse = true;
    else if (r <= 0.0f) reverse = false;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //SDL_RenderClear(renderer);
    //SDL_RenderPresent(renderer);
    SDL_GL_SwapWindow(window);
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    if (renderer) SDL_DestroyRenderer(renderer);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
