#pragma once

#include "SpriteSheet.h"

#include <glm/glm.hpp>

#include <string>

namespace Mono
{
	class SpriteLoader
	{
		public:
			SpriteLoader(const std::string& spriteSheetFilePath, 
				         const glm::vec2& spriteSheetSize, 
				         const glm::vec2& spriteSheetTileSize);
			~SpriteLoader() {};
			SpriteLoader(const SpriteLoader&) = delete;

			void bindSpriteSheet();

		private:
			SpriteSheet spriteSheet_;
	};
}
