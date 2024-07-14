#pragma once

#include "Rendering/Shader.h"
#include "Rendering/Shapes/Quad.h"
#include "Rendering/Texture.h"
#include "Rendering/Text/Font.h"

namespace Mono
{
	class World
	{
		public:
			World(int width, int height);
			~World() {};
			World(const World&) = delete;

			void createWorld();

			void draw(const Shader& shader) const;

		private:
			Font tileFont_;
			Texture mapTexture_;
			Quad mapQuad_;
			int width_;
			int height_;
	};
}
