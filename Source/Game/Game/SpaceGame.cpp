#include "SpaceGame.h"

#include "Core/Random.h"
#include "Framework/Scene.h"
#include "Math/Vector2.h"
#include "Player.h"
#include "Renderer/Font.h"
#include "Renderer/Model.h"
#include "Renderer/Text.h"
#include "Engine.h"

#include <vector>

bool SpaceGame::Initialize() {
    _scene = std::make_unique<errera::Scene>();

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
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        _scene->AddActor(std::move(player));
    }

    // FONT CREATION
    /*std::unique_ptr<errera::Font> font = std::make_unique<errera::Font>();
    font->Load("ArcadeClassic.ttf", 20);*/

    // TEXT CREATION
    //_text = std::make_unique<errera::Text>(font);
    //_text->Create(errera::GetEngine().GetRenderer(), "Hello World", errera::vec3{ 1, 1, 1 });

    return true;
}

void SpaceGame::Update() {
    _scene->Update(errera::GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Draw() {
    _scene->Draw(errera::GetEngine().GetRenderer());

    //// DRAW TEXT
    //_text->Draw(errera::GetEngine().GetRenderer(), 40.0f, 40.0f);
}

void SpaceGame::Shutdown() {
}
