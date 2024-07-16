#include "SpriteSheet.h"

#include <glad/glad.h>

namespace Mono
{
	SpriteSheet::SpriteSheet(const std::string& filePath, 
		                     const glm::vec2& size, 
		                     const glm::vec2& tileSize)
		: texture_{ filePath, TextureSettings{ GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR } },
		  size_{ size }, tileSize_{ tileSize }
	{

	}

	void SpriteSheet::bind()
	{
		texture_.bind();
	}
}