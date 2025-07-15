#include "Model.h"
#include "Renderer.h"

namespace errera {
	/// <summary>
	/// 
	/// </summary>
	/// <param name="renderer"></param>
	void Model::Draw(Renderer& renderer, const vec2& position, float rotation, float scale){
		// Checks if points are empty, if so then return
		if (_points.empty()) return;

		renderer.SetColor(_color.r, _color.g, _color.b);

		// Iterate through all points, draw line
		for (int i = 0; i < (_points.size() - 1); i++) {
			vec2 p1 = (_points[i].Rotate(rotation) * scale) + position;
			vec2 p2 = (_points[i + 1].Rotate(rotation) * scale) + position;

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
		}
	}
}

