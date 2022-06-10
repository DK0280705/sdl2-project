#include "pch.h"

#include "game.h"
#include "scene.h"

Game* Game::_p_instance = 0;

Game::Game(SDL_Window* w, SDL_Renderer* r) noexcept : window(w), renderer(r)
{
}

Game& Game::get()
{
    return *_p_instance;
}

Game& Game::init(SDL_Window* w, SDL_Renderer* r)
{
    static Game game(w, r);
    _p_instance = &game;
    return game;
}

void Game::update(float delta)
{
    SDL_RenderClear(renderer); 
    for (auto& scene : scenes) {
        scene->input(event);
        scene->update(delta);
    }
    SDL_RenderPresent(renderer);
}

Game::~Game()
{
    for (auto& scene : scenes) delete scene;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
