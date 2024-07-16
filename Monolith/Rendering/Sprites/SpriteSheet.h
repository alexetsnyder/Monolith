#pragma once

#include "Rendering/Texture.h"

#include "glm/glm.hpp"

#include <string>

namespace Mono
{
	class SpriteSheet
	{
		public:
			SpriteSheet(const std::string& filePath, 
				        const glm::vec2& size, 
				        const glm::vec2& tileSize);
			~SpriteSheet() {};
			SpriteSheet(const SpriteSheet&) = delete;

			void bind();

		private:
			Texture texture_;
			glm::vec2 size_;
			glm::vec2 tileSize_;
	};

}
