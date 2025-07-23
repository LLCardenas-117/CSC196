#include "SpaceGame.h"

#include "Core/Random.h"
#include "Enemy.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Math/Vector2.h"
#include "Player.h"
#include "Renderer/Font.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"
#include "Renderer/Text.h"

#include <vector>

bool SpaceGame::Initialize() {
    _scene = std::make_unique<errera::Scene>();

    std::vector<errera::vec2> playerShipPoints{
        { 18, 1 },
        { 14, 3 },
        { 13, 3 },
        { 13, 4 },
        { 11, 5 },
        { 11, 8 },
        { 9, 13 },
        { 7, 13 },
        { 6, 12 },
        { 5, 8 },
        { 4, 8 },
        { 0, 7 },
        { 0, 5 },
        { 7, 5 },
        { 6, 5 },
        { 3, 4 },
        { 1, 4 },
        { -2, 3 },
        { -9, 6 },
        { -10, 7 },
        { -20, 7 },
        { -20, 4 },
        { -19, 3 },
        { -11, 3 },
        { -14, 2 },
        { -16, 2 },
        { -18, 1 },
        { -18, -1 },
        { -16, -2 },
        { -14, -2 },
        { -11, -3 },
        { -19, -3 },
        { -20, -4 },
        { -20, -7 },
        { -10, -7 },
        { -9, -6 },
        { -2, -3 },
        { 1, -4 },
        { 3, -4 },
        { 6, -5 },
        { 7, -5 },
        { 0, -5 },
        { 0, -7 },
        { 5, -8 },
        { 6, -12 },
        { 7, -13 },
        { 9, -13 },
        { 11, -8 },
        { 11, -5 },
        { 13, -4 },
        { 13, -3 },
        { 14, -3 },
        { 18, -1 },
        { 18, 1 }
    };

    std::vector<errera::vec2> enemyShipPoints{
        { 9, 0 },
        { 8, 3 },
        { 6, 5 },
        { 3, 6 },
        { -1, 6 },
        { -4, 5 },
        { -7, 4 },
        { -9, 3 },
        { -3, 3 },
        { -3, 1 },
        { -1, 1 },
        { -2, 0 },
        { -1, -1 },
        { -3, -1 },
        { -3, -3 },
        { -9, -3 },
        { -7, -4 },
        { -4, -5 },
        { -1, -6 },
        { 3, -6 },
        { 6, -5 },
        { 8, -3 },
        { 9, 0 }
    };

    std::shared_ptr<errera::Model> model = std::make_shared<errera::Model>(playerShipPoints, errera::vec3{ 0, 1, 0 });

    errera::Transform transform{ errera::vec2{ errera::GetEngine().GetRenderer().GetWidth() * 0.5f , errera::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 2};
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    player->speed = 1000.0f;
    player->rotationRate = 280.0f;
    player->damping = 0.75f;
    player->name = "player";

    _scene->AddActor(std::move(player));

    // SAVING CODE FOR ENEMY CODE
    std::shared_ptr<errera::Model> enemyModel = std::make_shared<errera::Model>(enemyShipPoints, errera::vec3{ 0.749f, 0.250f, 0.749f });
    for (int i = 0; i < 10; i++) {
        errera::Transform transform{ errera::vec2{errera::random::getRandomFloat() * errera::GetEngine().GetRenderer().GetHeight(), errera::random::getRandomFloat() * errera::GetEngine().GetRenderer().GetWidth()}, 0, 5 };
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
        enemy->damping = 1.5f;
        enemy->speed = (errera::random::getRandomFloat() * 800) + 500.0f;
        _scene->AddActor(std::move(enemy));
    }

    return true;
}

void SpaceGame::Update() {
    _scene->Update(errera::GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Draw() {
    _scene->Draw(errera::GetEngine().GetRenderer());
}

void SpaceGame::Shutdown() {
}
