#include "pch.h"

#include "game.h"
#include "scenes/scene_main.h"
#include <iostream>

constexpr int MAX_FPS = 60;

bool terminating = false;

static void event_handler(SDL_Event& event)
{
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        terminating = true;
        break;
    default:
        break;
    }
}

int main(int argc, const char** argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { 
        std::cerr << "Can't init video: " << SDL_GetError() << "\n";
        return 1;
    }

    int img_flags = IMG_INIT_PNG;
    if (!(IMG_Init(img_flags) & img_flags)) {
        std::cerr << "Can't init image: " << IMG_GetError() << "\n";
        return 1;
    }

    try {
        if (SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED,
                                                  SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                                  SCREEN_HEIGHT,
                                                  SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)) {
            SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            // Initialize game class
            Game& game = Game::init(window, renderer);

            Scene_main* main_s = new Scene_main(&game, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            game.scenes.push_back(main_s);

            // Handle FPS
            // For example 1000 / 60 will give you 16.666 milliseconds per frame
            constexpr float mspf = 1000.0f / MAX_FPS;
            Uint64 frame_count_start;
            float delta_ms = 0;
            float delta_s  = 0;

            Uint32 last_tick = SDL_GetTicks();
            Uint32 curr_tick = 0;

            SDL_Event event;
            while (!terminating) {
                frame_count_start = SDL_GetPerformanceCounter();

                curr_tick = SDL_GetTicks();
                delta_s   = (curr_tick - last_tick) / 1000.0f;
                event_handler(event);
                game.update(delta_s);
                last_tick = curr_tick;

                delta_ms = (SDL_GetPerformanceCounter() - frame_count_start) /
                           (float)SDL_GetPerformanceFrequency() * 1000.0f;
                if (mspf > delta_ms) SDL_Delay(std::floor(mspf - delta_ms));
            }
        } else std::cerr << "Can't create window: " << SDL_GetError() << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    
    IMG_Quit();
    SDL_Quit();

    return 0;
}
