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

#include "Core/File.h"

int main(int argc, char* argv[]) {

    // Test getInt() variants
    std::cout << "Integer Functions:\n";
    std::cout << "getInt(): " << errera::random::getInt() << "\n";
    std::cout << "getInt(): " << errera::random::getInt() << "\n";
    std::cout << "getInt(10): " << errera::random::getInt(10) << "\n";
    std::cout << "getInt(10): " << errera::random::getInt(10) << "\n";
    std::cout << "getInt(5, 15): " << errera::random::getInt(5, 15) << "\n";
    std::cout << "getInt(5, 15): " << errera::random::getInt(5, 15) << "\n";
    std::cout << "getInt(-10, 10): " << errera::random::getInt(-10, 10) << "\n\n";

    // Test getReal() variants with float
    std::cout << "Float Functions:\n";
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "getReal<float>(): " << errera::random::getReal<float>() << "\n";
    std::cout << "getReal<float>(): " << errera::random::getReal<float>() << "\n";
    std::cout << "getReal<float>(5.0f): " << errera::random::getReal<float>(5.0f) << "\n";
    std::cout << "getReal<float>(2.5f, 7.5f): " << errera::random::getReal<float>(2.5f, 7.5f) << "\n";
    std::cout << "getReal<float>(-1.0f, 1.0f): " << errera::random::getReal<float>(-1.0f, 1.0f) << "\n\n";

    // Test getReal() variants with double
    std::cout << "Double Functions:\n";
    std::cout << std::setprecision(10);
    std::cout << "getReal<double>(): " << errera::random::getReal<double>() << "\n";
    std::cout << "getReal<double>(100.0): " << errera::random::getReal<double>(100.0) << "\n";
    std::cout << "getReal<double>(0.0, 2.0): " << errera::random::getReal<double>(0.0, 2.0) << "\n\n";

    // Test getBool()
    std::cout << "Boolean Functions:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << "getBool(): " << std::boolalpha << errera::random::getBool() << "\n";
    }
    std::cout << "\n";

    /*
    // Initialize Engine Systems
    errera::GetEngine().Initialize();

    // Initialize Game
    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
    game->Initialize();

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
        game->Update(errera::GetEngine().GetTime().GetDeltaTime());
        
        if (errera::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        // Draw
        errera::vec3 color{ 0, 0, 0 };

        errera::GetEngine().GetRenderer().SetColor(color.r, color.g, color.b);
        errera::GetEngine().GetRenderer().Clear(); // Clear the screen with black

        game->Draw();

        errera::GetEngine().GetRenderer().Present();
    }

    game->Shutdown();
    game.release();
    errera::GetEngine().Shutdown();

    return 0;
    */
}