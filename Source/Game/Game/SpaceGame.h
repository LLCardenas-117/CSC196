#pragma once
#include "Framework/Game.h"

class SpaceGame : public errera::Game {
public:
	SpaceGame() = default;

	bool Initialize() override;

	void Update() override;

	void Draw() override;

	void Shutdown() override;
	

private:
	//

};