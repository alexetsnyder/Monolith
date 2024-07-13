#pragma once

#include <SDL/SDL_ttf.h>

#include <string>

namespace Mono
{
	class GlyphAtlas
	{
		public:
			static const int FONT_SURFACE_SIZE{ 512 };
			static const int MAX_GLYPHS{ 128 };

			GlyphAtlas(const std::string& name, const char* filePath, int fontSize);
			~GlyphAtlas();
			GlyphAtlas(const GlyphAtlas&) = delete;

			SDL_Rect getGlyph(int fontType, int character) const;

			const SDL_Surface* surface() const { return surface_; }

		private:
			void addFont(const std::string& name, const char* filePath, int fontSize);
			SDL_Color getColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

			std::string name_;
			TTF_Font* font_;
			SDL_Surface* surface_;
			SDL_Rect glyphs_[MAX_GLYPHS];
	};
}
