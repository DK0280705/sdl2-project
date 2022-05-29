#pragma once

class Texture
{
    struct SDL_Texture* _p_tex;
public:
    Texture();
    ~Texture();

    // High precision coordinate
    float x;
    float y;
    struct SDL_Rect rect;

    SDL_Texture* get();
    void set_pos(int x, int y);
    void set_size(int w, int h);
    void load_image(const char* path);
};