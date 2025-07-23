#pragma once
#include <memory>

namespace errera {
	class Game {
	public:
		Game() = default;

		virtual bool Initialize() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual void Shutdown() = 0;

	protected:
		int _score{ 0 };
		int _lives{ 0 };
		std::unique_ptr<class Scene> _scene;
	};
}