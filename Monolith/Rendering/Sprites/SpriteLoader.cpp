#include "SpriteLoader.h"

namespace Mono
{
	SpriteLoader::SpriteLoader(const std::string& spriteSheetFilePath, const glm::vec2& spriteSheetSize, const glm::vec2& tileSize)
		: spriteSheet_{ spriteSheetFilePath, TextureSettings{ GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR } },
		  size_{ spriteSheetSize }, tileSize_{ tileSize }
	{

	}

	void SpriteLoader::bindSpriteSheet()
	{
		spriteSheet_.bind();
	}
}