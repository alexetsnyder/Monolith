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
		normalizedXTileSize_ = tileSize_.x / size_.x;
		normalizedYTileSize_ = tileSize_.y / size_.y;
	}

	std::vector<float> SpriteSheet::textureCoordinates(int i, int j) const
	{
		std::vector<float> coordinates{};

		float x = j * normalizedXTileSize_;
		float y = i * normalizedYTileSize_;

		coordinates.push_back(x + normalizedXTileSize_);
		coordinates.push_back(y + normalizedYTileSize_);

		coordinates.push_back(x);
		coordinates.push_back(y + normalizedYTileSize_);

		coordinates.push_back(x + normalizedXTileSize_);
		coordinates.push_back(y);

		coordinates.push_back(x);
		coordinates.push_back(y);

		return coordinates;
	}

	void SpriteSheet::bind() const
	{
		texture_.bind();
	}
}