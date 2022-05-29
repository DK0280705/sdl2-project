#include "pch.h"

#include "game.h"

Game* Game::_p_instance = 0;

Game::Game(SDL_Window* w, SDL_Renderer* r) noexcept : window(w), renderer(r)
{
}

Game& Game::init(SDL_Window* w, SDL_Renderer* r)
{
    static Game game(w, r);
    _p_instance = &game;
    return game;
}

void Game::update(float delta)
{
    static bool reverse = false;
    static float r = 0;
    r += (reverse ? -80.0f : 80.0f) * delta;
    if (r >= 255.0f) { 
        r = 255.0f;
        reverse = true;
    }
    else if (r <= 0.0f) {
        r = 0.0f;
        reverse = false;
    }
    SDL_SetRenderDrawColor(renderer, 76, (int)r, 0, 255);
    SDL_RenderClear(renderer); 
    SDL_RenderPresent(renderer);
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
