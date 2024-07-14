#include "World.h"

namespace Mono
{
	World::World(int width, int height)
		: tileFont_{ FontName::Px437_IBM_VGA_8x14, "Assets/Fonts/Px437_IBM_VGA_8x14.ttf", 24},
		  mapTexture_{ width, height, TextureSettings{ GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR } },
		  mapQuad_{}, width_{width}, height_{height}
	{
		
	}

	void World::draw(const Shader& shader) const
	{
		mapTexture_.bind();
		mapQuad_.renderer()->draw(shader);
	}
}