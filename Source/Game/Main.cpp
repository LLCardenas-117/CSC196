#include "Core/Random.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include "Input/InputSystem.h"

#include <SDL3/SDL.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    // Initialize Engine Systems
    errera::Renderer renderer;
    errera::Time time;
    errera::InputSystem input;

    renderer.Initialize();
	renderer.CreateWindow("ERRERA Engine", 1280, 1024);

    input.Initialize();

    // Audio Systems

    SDL_Event e;
    bool quit = false;

	std::vector<errera::vec2> stars;

    // Create Sarst
    for (int i = 0; i < 100; i++) {
        stars.push_back(errera::vec2{ errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024 });
    }

    std::vector<errera::vec2> points;

    // MAIN LOOP
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        // Update Engine Systems
        input.Update();

        // Get Input
        /*if (input.GetKeyPressed(SDL_SCANCODE_A)) {
            std::cout << "Pressed\n";
        }*/

        if (input.GetMouseButtonPressed(errera::InputSystem::MouseButton::LEFT)) {
            points.push_back(input.GetMousePosition());
        }
        
        if (input.GetMouseButtonDown(errera::InputSystem::MouseButton::LEFT)) {
            errera::vec2 position = input.GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }

        /*errera::vec2 mouse = input.GetMousePosition();
        std::cout << mouse.x << ", " << mouse.y << std::endl;*/

        // Draw
        renderer.SetColor(0, 0, 0, 0);
		renderer.Clear(); // Clear the screen with black
        
        for (int i = 0; i < (int)points.size() - 1; i++) {
            renderer.SetColor(errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256));
            renderer.SetColor(errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256));
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        renderer.Present();
    }

	renderer.Shutdown();

    return 0;
}