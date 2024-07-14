#include "World.h"

namespace Mono
{
	World::World(int width, int height)
		: tileFont_{ FontName::Px437_IBM_VGA_8x14, "Assets/Fonts/Px437_IBM_VGA_8x14.ttf", 24},
		  mapTexture_{ width, height, TextureSettings{ GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR } },
		  mapQuad_{}, width_{width}, height_{height}
	{
		createWorld();
	}

	void World::createWorld()
	{
		SDL_Surface* mapSurface{ SDL_CreateRGBSurface(0, width_, height_, 32, 0, 0, 0, 0xff) };
		SDL_SetColorKey(mapSurface, SDL_TRUE, SDL_MapRGBA(mapSurface->format, 0, 0, 0, 0));

		for (int i = 0; i < height_; i+=12)
		{
			for (int j = 0; j < width_; j+=12)
			{
				tileFont_.blitSurface('~', j, i, mapSurface);
			}
		}

		mapTexture_.updateTexture(mapSurface);

		SDL_FreeSurface(mapSurface);
	}

	void World::draw(const Shader& shader) const
	{
		mapTexture_.bind();
		mapQuad_.renderer()->draw(shader);
	}
}