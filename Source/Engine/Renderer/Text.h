#pragma once
#include "Renderer.h"
#include "Font.h"
#include "../Math/Vector3.h"

struct SDL_Texture;

namespace errera {
	class Text {
	public:
		Text() = default;
		Text(Font* font) : _font{ font } {}
		~Text();

		bool Create(Renderer& renderer, const std::string& text, const vec3& color);
		void Draw(Renderer& renderer, float x, float y);

	private:
		Font* _font{ nullptr };
		SDL_Texture* _texture{ nullptr };
	};
}