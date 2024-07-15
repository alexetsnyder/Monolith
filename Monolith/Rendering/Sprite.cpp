#include "Sprite.h"

namespace Mono
{
	Sprite::Sprite(const glm::vec3 position, const glm::vec2 size, char c)
		: position_{ position }, size_{ size }, 
		  texture_{ static_cast<int>(size.x), static_cast<int>(size.y), TextureSettings{ GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR } },
		  quad_{}
	{

	}
}