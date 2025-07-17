#pragma once

#include "Framework/Actor.h"

class Enemy : public errera::Actor {
public:
	Enemy() = default;
	Enemy(const errera::Transform& transform, std::shared_ptr<errera::Model> model) :
		Actor{ transform, model }
	{
	}

	void Update(float dt) override;

private:

};