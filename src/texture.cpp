#include "pch.h"

#include "game.h"
#include "texture.h"
#include <stdexcept>

Texture::Texture()
{
}

SDL_Texture* Texture::get()
{
    if (!_p_tex) throw std::runtime_error("Texture empty!");
    return _p_tex;
}

void Texture::set_pos(int x, int y)
{
    rect.x = x;
    rect.y = y;
}

void Texture::set_size(int w, int h)
{
    rect.w = w;
    rect.h = h;
}

void Texture::load_image(const char* path)
{
    SDL_Surface* surf = IMG_Load(path);
    if (!surf) throw std::runtime_error(IMG_GetError());
    Game& game = Game::get();
    _p_tex     = SDL_CreateTextureFromSurface(game.renderer, surf);
    SDL_FreeSurface(surf);
}

Texture::~Texture()
{
    if (_p_tex) SDL_DestroyTexture(_p_tex);
}