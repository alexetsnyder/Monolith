#pragma once

#include "Rendering/Texture.h"

#include <glm/glm.hpp>

#include <string>

namespace Mono
{
	class SpriteLoader
	{
		public:
			SpriteLoader(const std::string& spriteSheetFilePath, 
				         const glm::vec2& spriteSheetSize, 
				         const glm::vec2& tileSize);
			~SpriteLoader() {};
			SpriteLoader(const SpriteLoader&) = delete;

			void bindSpriteSheet();

		private:
			Texture spriteSheet_;
			glm::vec2 size_;
			glm::vec2 tileSize_;
	};
}
