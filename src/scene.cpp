#include "pch.h"

#include "game.h"
#include "scene.h"

Scene::Scene(Game* game, int x, int y, int w, int h)
    : game_(game)
{
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

Scene::~Scene()
{
}