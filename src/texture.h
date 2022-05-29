#pragma once

class Texture
{
    struct SDL_Texture* _p_tex;
    struct SDL_Surface* _p_surf;
public:
    Texture();
    ~Texture();

    void load_image(const char* path);
};