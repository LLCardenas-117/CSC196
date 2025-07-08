#include <SDL3/SDL.h>
#include <Core/Random.h>
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    errera::Renderer renderer;
    errera::Time time;

    renderer.Initialize();
	renderer.CreateWindow("ERRERA Engine", 1280, 1024);

    SDL_Event e;
    bool quit = false;

	std::vector<errera::vec2> stars;

    for (int i = 0; i < 100; i++) {
        stars.push_back(errera::vec2{ errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024 });
    }

    // MAIN LOOP
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }  

		renderer.Clear(); // Clear the screen with black

        errera::vec2 speed{ 40.0f, 0.0f };
		float length = speed.Length();

        for (auto& star : stars) {
            star -= speed * time.GetDeltaTime();
            if (star[0] > 1280) star[0] = 0;
			if (star[0] < 0) star[0] = 1280;
			if (star[1] > 1024) star[1] = 0;
			if (star[1] < 0) star[1] = 1024;
            renderer.SetColor(errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256));
            renderer.DrawPoint(star.x, star.y);
        }

		/*for (int i = 0; i < 100; i++) {
            renderer.SetColor(errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256));
			
            renderer.DrawPoint(errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024);

            renderer.SetColor(errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256));

			renderer.DrawPoint(v.x, v.y);
            
            renderer.DrawLine(errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024, errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024);
		}*/

        renderer.Present();
    }

	renderer.Shutdown();

    return 0;
}