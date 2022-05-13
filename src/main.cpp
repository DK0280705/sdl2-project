#include "pch.h"

#include <iostream>

constexpr int SCREEN_WIDTH  = 1280;
constexpr int SCREEN_HEIGHT = 720;
constexpr int MAX_FPS       = 60;

static bool terminating = false;

static void event_handler()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        terminating = true;
        break;
    default:
        break;
    }
}

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::cerr << "Can't init video: " << SDL_GetError() << "\n";

    if (SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED,
                                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                              SDL_WINDOW_SHOWN)) {
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
        // Base color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        // Handle FPS
        constexpr Uint32 ticks_delay = 1000 / MAX_FPS;
        Uint32 start_ticks;
        Uint32 ticks_length;

        while (!terminating)  {
            start_ticks = SDL_GetTicks();

            event_handler();
            SDL_RenderClear(renderer);
            // What to render
            SDL_RenderPresent(renderer);
            
            ticks_length = SDL_GetTicks() - start_ticks;
            if (ticks_delay > ticks_length) SDL_Delay(ticks_delay - ticks_length);
        }
        
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    } else std::cerr << "Can't create window: " << SDL_GetError() << "\n";

    return 0;
}
