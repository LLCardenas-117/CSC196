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
#include "Input/InputSystem.h"
#include "GameData.h"

#include <vector>

bool SpaceGame::Initialize() {
    _scene = std::make_unique<errera::Scene>();

    return true;
}

void SpaceGame::Update(float dt) {
    switch (_gameState) {
    case SpaceGame::GameState::Initialize:
        _gameState = GameState::Title;
        break;

    case SpaceGame::GameState::Title:
        if (errera::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE)) {
            _gameState = GameState::StartGame;
        }
        break;

    case SpaceGame::GameState::StartGame:
        _score = 0;
        _lives = 3;
        _gameState = GameState::StartLevel;
        break;

    case SpaceGame::GameState::StartLevel:
    {
        std::shared_ptr<errera::Model> model = std::make_shared<errera::Model>(GameData::playerShipPoints, errera::vec3{ 0, 1, 0 });
        errera::Transform transform{ errera::vec2{ errera::GetEngine().GetRenderer().GetWidth() * 0.5f , errera::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 2 };
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        player->speed = 1000.0f;
        player->rotationRate = 280.0f;
        player->damping = 0.75f;
        player->name = "player";
        player->tag = "player";

        _scene->AddActor(std::move(player));
        _gameState = GameState::Game;
    }
        break;

    case SpaceGame::GameState::Game:
        _enemySpawnTimer -= dt;
        if (_enemySpawnTimer <= 0) {
            _enemySpawnTimer = 4;

            // SAVING CODE FOR ENEMY CODE
            std::shared_ptr<errera::Model> enemyModel = std::make_shared<errera::Model>(GameData::enemyShipPoints, errera::vec3{ 0.749f, 0.250f, 0.749f });
            errera::Transform transform{ errera::vec2{errera::random::getRandomFloat() * errera::GetEngine().GetRenderer().GetHeight(), errera::random::getRandomFloat() * errera::GetEngine().GetRenderer().GetWidth()}, 0, 5 };
            std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
            enemy->damping = 1.5f;
            enemy->speed = (errera::random::getRandomFloat() * 800) + 500.0f;
            enemy->tag = "enemy";
            _scene->AddActor(std::move(enemy));
        }

        

        break;

    case SpaceGame::GameState::PlayerDead:
        _lives--;
        if (_lives == 0) _gameState = GameState::GameOver;
        else { _gameState = GameState::StartLevel; }
        break;

    case SpaceGame::GameState::GameOver:
        break;
    }

    _scene->Update(errera::GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Draw() {
    _scene->Draw(errera::GetEngine().GetRenderer());
}

void SpaceGame::Shutdown() {
}
