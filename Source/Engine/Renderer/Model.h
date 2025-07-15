#pragma once

#include "../Math/Vector2.h"
#include "../Math/Vector3.h"

#include <vector>

namespace errera {
	class Model {
	public:
		Model() = default;
		Model(const std::vector<vec2> points, const vec3& color) :
			_points{ points },
			_color{ color }
		{}

		void Draw(class Renderer& renderer, const vec2& position,float rotation, float scale);

	private:
		std::vector<vec2> _points;
		vec3 _color{ 1, 1, 1 };
	};
}