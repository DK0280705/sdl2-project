#include "pch.h"

#include "scene.h"

Scene::Scene(int x, int y, int h, int w)
{
    rect.x = x;
    rect.y = y;
    rect.h = h;
    rect.w = w;
}

Scene::~Scene()
{
}