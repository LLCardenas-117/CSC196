#include "Audio/AudioSystem.h"
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
#include "Engine.h"

#include "Game/Player.h"
#include "Game/SpaceGame.h"

#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char* argv[]) {

    // Initialize Engine Systems
    errera::GetEngine().Initialize();

    // Initialize Game
    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
    game->Initialize();

    // FONT CREATION
    errera::Font* font = new errera::Font();
    font->Load("ArcadeClassic.ttf", 20);

    // TEXT CREATION
    errera::Text* text = new errera::Text(font);
    text->Create(errera::GetEngine().GetRenderer(), "Hello World", errera::vec3{ 1, 1, 1 });

    SDL_Event e;
    bool quit = false;

    // MAIN LOOP
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        // Update Engine Systems
        errera::GetEngine().Update();
        game->Update();
        
        if (errera::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        // Draw
        errera::vec3 color{ 0, 0, 0 };

        errera::GetEngine().GetRenderer().SetColor(color.r, color.g, color.b);
        errera::GetEngine().GetRenderer().Clear(); // Clear the screen with black

        // DRAW TEXT
        text->Draw(errera::GetEngine().GetRenderer(), 40.0f, 40.0f);

        game->Draw();

        errera::GetEngine().GetRenderer().Present();
    }

    errera::GetEngine().Shutdown();
    game->Shutdown();

    return 0;
}