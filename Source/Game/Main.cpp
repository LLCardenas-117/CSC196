#include <SDL3/SDL.h>
#include <Core/Random.h>
#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include <iostream>

int main(int argc, char* argv[]) {
    errera::Renderer renderer;

    renderer.Initialize();
	renderer.CreateWindow("ERRERA Engine", 1280, 1024);

    SDL_Event e;
    bool quit = false;

    errera::vec2 v(30, 40);

    // Define a rectangle
    //SDL_FRect greenSquare{ 270, 190, 200, 200 };

    // Assignment: Draw lines and points
    //for (int i = 0; i < 10; i++) {
    //    float x1 = errera::random::getRandomInt(1280);
    //    float y1 = errera::random::getRandomInt(1024);
    //    float x2 = errera::random::getRandomInt(1280);
    //    float y2 = errera::random::getRandomInt(1024);
    //    SDL_SetRenderDrawColor(renderer, errera::random::getRandomInt(255), errera::random::getRandomInt(255), errera::random::getRandomInt(255), errera::random::getRandomInt(255));
    //    SDL_RenderLine(renderer, x1, y1, x2, y2);

    //    for (int j = 0; j < 2; j++) {
    //        SDL_SetRenderDrawColor(renderer, errera::random::getRandomInt(255), errera::random::getRandomInt(255), errera::random::getRandomInt(255), errera::random::getRandomInt(255));
    //        float x = errera::random::getRandomInt(1280);
    //        float y = errera::random::getRandomInt(1024);
    //        SDL_RenderPoint(renderer, x, y);
    //    }
    //}

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }  

        renderer.SetColor(errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256), 0);
		renderer.Clear(); // Clear the screen with black

		for (int i = 0; i < 100; i++) {
            renderer.SetColor(errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256));
			
            renderer.DrawPoint(errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024);

            renderer.SetColor(errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256));

			renderer.DrawPoint(v.x, v.y);
            
            renderer.DrawLine(errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024, errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024);
		}
		//renderer.DrawLine(errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024, errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024);

        renderer.Present();
    }

	renderer.Shutdown();

    return 0;
}