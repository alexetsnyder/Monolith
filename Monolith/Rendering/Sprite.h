#pragma once

#include "Shapes/Quad.h"
#include "Texture.h"

#include <glm/glm.hpp>

namespace Mono
{
	class Sprite
	{
		public:
			Sprite(const glm::vec3 position, const glm::vec2 size, char c);
			~Sprite() {};
			Sprite(const Sprite&) = delete;

		private:
			glm::vec3 position_;
			glm::vec2 size_;
			Quad quad_;
			Texture texture_;
	};
}
