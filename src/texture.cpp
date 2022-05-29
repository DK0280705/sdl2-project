#include "pch.h"

#include "texture.h"
#include <stdexcept>

Texture::Texture()
{
}

void Texture::load_image(const char* path)
{
    _p_surf = IMG_Load(path);
    if (!_p_surf) throw std::runtime_error(IMG_GetError());
}

Texture::~Texture()
{
    if (_p_surf) SDL_FreeSurface(_p_surf);
}