#include "Audio/AudioSystem.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    // Initialize Engine Systems
    errera::Renderer renderer;
    errera::Time time;
    errera::InputSystem input;
    errera::AudioSystem audio;


    renderer.Initialize();
	renderer.CreateWindow("ERRERA Engine", 1280, 1024);

    input.Initialize();

    audio.Init();

    // Audio Systems

    //Creates audio in the code and adds it to a vector
    audio.AddSound("bass.wav", "bass");
    audio.AddSound("snare.wav", "snare");
    audio.AddSound("open-hat.wav", "open-hat");
    audio.AddSound("close-hat.wav", "close-hat");
    audio.AddSound("clap.wav", "clap");
    audio.AddSound("cowbell.wav", "cowbell");

    SDL_Event e;
    bool quit = false;

	std::vector<errera::vec2> stars;

    // Create Stars
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
        audio.Update();

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

        if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q)) { audio.PlaySound("bass"); }
        if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W)) { audio.PlaySound("snare"); }
        if (input.GetKeyDown(SDL_SCANCODE_A) && !input.GetPrevKeyDown(SDL_SCANCODE_A)) { audio.PlaySound("open-hat"); }
        if (input.GetKeyDown(SDL_SCANCODE_S) && !input.GetPrevKeyDown(SDL_SCANCODE_S)) { audio.PlaySound("close-hat"); }
        if (input.GetKeyDown(SDL_SCANCODE_D) && !input.GetPrevKeyDown(SDL_SCANCODE_D)) { audio.PlaySound("clap"); }
        if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E)) { audio.PlaySound("cowbell"); }

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
    audio.Shutdown();

    return 0;
}