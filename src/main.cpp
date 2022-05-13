#include "pch.h"

#include <iostream>
#include <csignal>

constexpr int SCREEN_WIDTH  = 1280;
constexpr int SCREEN_HEIGHT = 720;

static bool terminating = false;

int main()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cerr << "Can't init video: " << SDL_GetError() << "\n";
    
    if (SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) {
        SDL_Surface* screen_surface = SDL_GetWindowSurface(window);

        std::signal(SIGINT, [](int) {terminating = true;});
        SDL_FillRect( screen_surface, NULL, SDL_MapRGB( screen_surface->format, 0xFF, 0xFF, 0xFF ) );

        while(!terminating) {
            SDL_UpdateWindowSurface(window);
        }
        SDL_DestroyWindow(window);
        SDL_Quit();
    } else std::cerr << "Can't create window: " << SDL_GetError() << "\n";
}
