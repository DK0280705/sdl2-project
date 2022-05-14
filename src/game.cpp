#include "pch.h"

#include "game.h"

Game* Game::_p_instance = 0;

constexpr Game::Game(SDL_Window* w, SDL_Renderer* r) noexcept
    : window(w), renderer(r)
{
}

Game& Game::init(SDL_Window* w, SDL_Renderer* r)
{
    static Game game(w, r);
    _p_instance = &game;
    return game;
}

void Game::update()
{
    SDL_RenderClear(renderer);
    // What to render
    SDL_RenderPresent(renderer);
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}