#pragma once

#include "Rendering/Texture.h"

#include "glm/glm.hpp"

#include <string>
#include <vector>

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

			std::vector<float> textureCoordinates(int i, int j) const;

			void bind() const;

		private:
			Texture texture_;
			glm::vec2 size_;
			glm::vec2 tileSize_;
			float normalizedXTileSize_;
			float normalizedYTileSize_;
	};

}
