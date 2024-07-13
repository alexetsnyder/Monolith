#pragma once

#include "GlyphAtlas.h"
#include "Rendering/Shader.h"
#include "Rendering/Shapes/Quad.h"
#include "Rendering/Texture.h"

#include <string>

namespace Mono
{
	class Font
	{
		public:
			Font(const std::string name, const std::string& filePath, int fontSize);
			~Font() {};
			Font(const Font&) = delete;

			void draw(const Shader& shader) const;

		private:
			std::string name_;
			GlyphAtlas atlas_;
	};
}
