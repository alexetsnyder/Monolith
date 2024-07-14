#pragma once

#include "GlyphAtlas.h"
#include "Rendering/Shader.h"
#include "Rendering/Shapes/Quad.h"
#include "Rendering/Texture.h"

#include <string>

namespace Mono
{
	class FontName
	{
		public:
			static const std::string Px437_IBM_VGA_8x14;
	};

	class Font
	{
		public:
			Font(const std::string name, const std::string& filePath, int fontSize);
			~Font() {};
			Font(const Font&) = delete;

			void blitSurface(char c, int x, int y, SDL_Surface* dstSurface);

		private:
			std::string name_;
			int fontSize_;
			GlyphAtlas atlas_;
	};
}
