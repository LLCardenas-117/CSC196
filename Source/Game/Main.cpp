#include "Audio/AudioSystem.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Input/InputSystem.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    union data_t {
        bool b;
        int i;
        double d;
    };

    data_t data;
    data.b = true;

    std::cout << data.b << std::endl;
    data.i = 400;
    std::cout << data.i << std::endl;
    std::cout << data.b << std::endl;

    // Initialize Engine Systems
    errera::Renderer renderer;
    errera::Time time;
    errera::InputSystem input;
    errera::AudioSystem audio;


    renderer.Initialize();
	renderer.CreateWindow("ERRERA Engine", 1280, 1024);

    input.Initialize();

    audio.Initialize();

    std::vector<errera::vec2> points {
        {-5, -5},
        { 5, -5},
        { 5, 5 },
        {-5, 5 },
        {-5, -5}
    };

    std::vector<errera::vec2> shipPoints{
        { 1, -18 },
        { 3, -14 },
        { 3, -13 },
        { 4, -13 },
        { 5, -11 },
        { 8, -11 },
        { 13, -9 },
        { 13, -7 },
        { 12, -6 },
        { 8, -5 },
        { 8, -4 },
        { 7, -0 },
        { 5, -0 },
        { 5, -7 },
        { 5, -6 },
        { 4, -3 },
        { 4, -1 },
        { 3, 2 },
        { 6, 9 },
        { 7, 10 },
        { 7, 20 },
        { 4, 20 },
        { 3, 19 },
        { 3, 11 },
        { 2, 14 },
        { 2, 16 },
        { 1, 18 },
        { -1, 18 },
        { -2, 16 },
        { -2, 14 },
        { -3, 11 },
        { -3, 19 },
        { -4, 20 },
        { -7, 20 },
        { -7, 10 },
        { -6, 9 },
        { -3, 2 },
        { -4, -1 },
        { -4, -3 },
        { -5, -6 },
        { -5, -7 },
        { -5, -0 },
        { -7, -0 },
        { -8, -5 },
        { -12, -6 },
        { -13, -7 },
        { -13, -9 },
        { -8, -11 },
        { -5, -11 },
        { -4, -13 },
        { -3, -13 },
        { -3, -14 },
        { -1, -18 },
        { 1, -18 }
    };

    //errera::Model model{ points, {0, 0, 1} };
    errera::Model model{ shipPoints, {0, 1, 0} };

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

    //std::vector<errera::vec2> points;

    // MAIN LOOP
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        if (input.GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

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
        errera::vec3 color{ 0, 0, 0 };

        renderer.SetColor(color.r, color.g, color.b);
		renderer.Clear(); // Clear the screen with black

        model.Draw(renderer, input.GetMousePosition(), 0.0f, 10.0f);
        
        for (int i = 0; i < (int)points.size() - 1; i++) {
            renderer.SetColor((uint8_t)errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256), errera::random::getRandomInt(256));
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        renderer.Present();
    }

	renderer.Shutdown();
    audio.Shutdown();

    return 0;
}