#pragma once
#include "Framework/Game.h"
#include "Renderer/Text.h"

class SpaceGame : public errera::Game {
public:
	enum class GameState {
		Initialize,
		Title,
		StartGame,
		StartLevel,
		Game,
		PlayerDead,
		GameOver
	};

public:
	SpaceGame() = default;

	bool Initialize() override;

	void Update(float dt) override;

	void Draw() override;

	void Shutdown() override;
	

private:
	GameState _gameState = GameState::Initialize;
	float _enemySpawnTimer{ 0 };
};