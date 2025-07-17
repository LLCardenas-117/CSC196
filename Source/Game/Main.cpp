#include "Core/Random.h"
#include "Core/Time.h"
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Input/InputSystem.h"
#include "Math/Transform.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"

#include "Game/Player.h"

#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char* argv[]) {

    // Initialize Engine Systems
    std::unique_ptr<errera::Renderer> renderer = std::make_unique<errera::Renderer>();
    errera::Time time;
    //std::unique_ptr<errera::AudioSystem> audio = std::make_unique<errera::AudioSystem>();
    std::unique_ptr<errera::InputSystem> input = std::make_unique<errera::InputSystem>();
    errera::Scene scene;

    renderer->Initialize();
	renderer->CreateWindow("ERRERA Engine", 1280, 1024);

    input->Initialize();

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

    std::shared_ptr<errera::Model> model = std::make_shared<errera::Model>(shipPoints, errera::vec3{ 0, 1, 0 });

    for (int i = 0; i < 10; i++) {
        errera::Transform transform{ errera::vec2{errera::random::getRandomFloat() * 1280, errera::random::getRandomFloat() * 1024}, 0, 2 };
        std::unique_ptr<Player> player = std::make_unique<Player>( transform, model);
        scene.AddActor(std::move(player));
    }

    SDL_Event e;
    bool quit = false;

    // MAIN LOOP
    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        if (input->GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        // Update Engine Systems
        input->Update();

        // Get Input

        //if (input.GetKeyDown(SDL_SCANCODE_A)) transform.rotation -= errera::math::degToRad(90 * time.GetDeltaTime());
        //if (input.GetKeyDown(SDL_SCANCODE_D)) transform.rotation += errera::math::degToRad(90 * time.GetDeltaTime());

        float speed = 200;
        errera::vec2 direction{ 0,0 };

        if (input->GetKeyDown(SDL_SCANCODE_W)) direction.y = -1; //100 * time.GetDeltaTime();
        if (input->GetKeyDown(SDL_SCANCODE_S)) direction.y = 1; //100 * time.GetDeltaTime();
        if (input->GetKeyDown(SDL_SCANCODE_A)) direction.x = -1; //100 * time.GetDeltaTime();
        if (input->GetKeyDown(SDL_SCANCODE_D)) direction.x = 1; //100 * time.GetDeltaTime();

        if (direction.LengthSquare() > 0) {
            direction = direction.Normalized();
            /*for (auto& player : actors) {
                player->GetTransform().position += (direction * speed) * time.GetDeltaTime();
            }*/
        }

        // Draw
        errera::vec3 color{ 0, 0, 0 };

        renderer->SetColor(color.r, color.g, color.b);
		renderer->Clear(); // Clear the screen with black

        scene.Draw(*renderer);

        renderer->Present();
    }

	renderer->Shutdown();
    input->Shutdown();

    return 0;
}