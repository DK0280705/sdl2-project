#include "../pch.h"

#include "../game.h"
#include "scene_main.h"

Scene_main::Scene_main(Game* game, int x, int y, int w, int h)
    : Scene(game, x, y, w, h)
{
    ground.load_image("assets/ground.png");
    ground.set_size(SCREEN_WIDTH / 2, 120);
    ground.set_pos(0, SCREEN_HEIGHT - ground.rect.h);

    trees.load_image("assets/trees.png");
    trees.set_size(SCREEN_WIDTH, 720);
    trees.set_pos(0, 95);

    mountains.load_image("assets/mountains.png");
    mountains.set_size(SCREEN_WIDTH, 768);
    mountains.set_pos(0, 0);
    
    clouds.load_image("assets/clouds.png");
    clouds.set_size(SCREEN_WIDTH, 768);
    clouds.set_pos(0, -30);
    
    background.load_image("assets/background_main.png");
    background.set_size(SCREEN_WIDTH, 720);
    background.set_pos(0, -10);
}

static void _move_infinite(Game* game, Texture& tex, int repeat, float speed, float delta)
{
    tex.x = tex.x - (speed * delta);
    for (int i = 0; i < repeat; i++) {
        SDL_Rect rect = tex.rect;
        rect.x        = tex.x + (rect.w * i);
        SDL_RenderCopy(game->renderer, tex.get(), nullptr, &rect);
    }
    if (tex.x <= -1280) tex.x = 0;
}

void Scene_main::update(float delta)
{
    SDL_RenderCopy(game_->renderer, background.get(), nullptr, &background.rect);
    _move_infinite(game_, clouds, 2, 5.0f, delta);
    _move_infinite(game_, mountains, 2, 10.0f, delta);
    _move_infinite(game_, trees, 2, 20.0f, delta);
    _move_infinite(game_, ground, 4, 40.0f, delta);
}

void Scene_main::input(const SDL_Event& event)
{

}

Scene_main::~Scene_main()
{
}