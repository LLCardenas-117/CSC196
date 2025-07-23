#include "Actor.h"
#include "../Renderer/Model.h"

namespace errera {
	void Actor::Update(float dt) {
		transform.position += velocity * dt;
		velocity *= (1.0f / (1.0f + damping * dt));
	}

	void Actor::Draw(Renderer& renderer) {
		_model->Draw(renderer, transform);
	}

}

