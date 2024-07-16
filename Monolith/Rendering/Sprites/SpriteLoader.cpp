#include "SpriteLoader.h"

namespace Mono
{
	SpriteLoader::SpriteLoader(const std::string& spriteSheetFilePath, 
							   const glm::vec2& spriteSheetSize, 
							   const glm::vec2& spriteSheetTileSize)
		: spriteSheet_{ spriteSheetFilePath, spriteSheetSize, spriteSheetTileSize }
	{

	}

	void SpriteLoader::bindSpriteSheet()
	{
		spriteSheet_.bind();
	}
}