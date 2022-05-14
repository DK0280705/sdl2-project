#include "pch.h"

#include "game.h"
#include <chrono>
#include <iostream>

constexpr int SCREEN_WIDTH  = 1280;
constexpr int SCREEN_HEIGHT = 720;
constexpr int MAX_FPS       = 60;

static bool terminating = false;

static double time_f()
{
    using namespace std::chrono;
    auto tp = system_clock::now() + 0ns;
    return tp.time_since_epoch().count() / 1000000.0;
}

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

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    if (SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED,
                                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                              SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)) {
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

        // Initialize game class
        Game& game = Game::init(window, renderer);
        game.setup_opengl(SCREEN_WIDTH, SCREEN_HEIGHT);

        // Handle FPS
        // For example 1000 / 60 will give you 16.666 milliseconds per frame
        constexpr double ticks_delay = 1000 / MAX_FPS;
        double start_ticks;
        double ticks_length;
        
        while (!terminating) {
            start_ticks = time_f();
            event_handler();
            game.update();
            ticks_length = time_f() - start_ticks;
            if (ticks_delay > ticks_length)
                SDL_Delay(std::floor(static_cast<Uint32>(ticks_delay - ticks_length)));
        }
    } else std::cerr << "Can't create window: " << SDL_GetError() << "\n";

    return 0;
}
