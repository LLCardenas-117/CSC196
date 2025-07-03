#include <SDL3/SDL.h>
#include <Core/Random.h>
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    //SDL_FRect greenSquare{ 270, 190, 200, 200 };

    // Assignment: Draw lines and points
    for (int i = 0; i < 10; i++) {
        float x1 = errera::random::getRandomInt(1280);
        float y1 = errera::random::getRandomInt(1024);
        float x2 = errera::random::getRandomInt(1280);
        float y2 = errera::random::getRandomInt(1024);
        SDL_SetRenderDrawColor(renderer, errera::random::getRandomInt(255), errera::random::getRandomInt(255), errera::random::getRandomInt(255), errera::random::getRandomInt(255));
        SDL_RenderLine(renderer, x1, y1, x2, y2);

        for (int j = 0; j < 2; j++) {
            SDL_SetRenderDrawColor(renderer, errera::random::getRandomInt(255), errera::random::getRandomInt(255), errera::random::getRandomInt(255), errera::random::getRandomInt(255));
            float x = errera::random::getRandomInt(1280);
            float y = errera::random::getRandomInt(1024);
            SDL_RenderPoint(renderer, x, y);
        }
    }

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }        

        SDL_RenderPresent(renderer); // Render the screen
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}