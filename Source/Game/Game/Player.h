#pragma once
#include "Framework/Actor.h"

class Player : public errera::Actor {
public:
	float speed = 200;
	float rotationRate = 180;

public:
	Player() = default;
	Player(const errera::Transform& transform, std::shared_ptr<errera::Model> model) :
		Actor{ transform, model }
	{}

	void Update(float dt) override;

private:

};