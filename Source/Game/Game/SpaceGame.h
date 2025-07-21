#pragma once
#include "Framework/Game.h"
#include "Renderer/Text.h"

class SpaceGame : public errera::Game {
public:
	SpaceGame() = default;

	bool Initialize() override;

	void Update() override;

	void Draw() override;

	void Shutdown() override;
	

protected:
	//std::unique_ptr<errera::Text> _text;
};