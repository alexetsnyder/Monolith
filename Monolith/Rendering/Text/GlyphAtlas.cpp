#include "GlyphAtlas.h"

#include <assert.h>

namespace Mono
{
	GlyphAtlas::GlyphAtlas(const std::string& name, const char* filePath, int fontSize)
	{
		addFont(name, filePath, fontSize);
	}

	GlyphAtlas::~GlyphAtlas()
	{
		TTF_CloseFont(font_);
		SDL_FreeSurface(surface_);
	}

	SDL_Rect GlyphAtlas::getGlyph(int fontType, int character) const
	{
		return glyphs_[character];
	}

	void GlyphAtlas::addFont(const std::string& name, const char* filePath, int fontSize)
	{
		name_ = name;

		font_ = TTF_OpenFont(filePath, fontSize);
		assert(font_ != nullptr);

		surface_ = SDL_CreateRGBSurface(0, FONT_SURFACE_SIZE, FONT_SURFACE_SIZE, 32, 0, 0, 0, 0xff);

		SDL_SetColorKey(surface_, SDL_TRUE, SDL_MapRGBA(surface_->format, 0, 0, 0, 0));

		SDL_Rect dest{};
		SDL_Color white{ getColor(0xff, 0xff, 0xff, 0xff) };
		for (int i = 1; i < MAX_GLYPHS; i++)
		{
			char c[2]
			{
				static_cast<char>(i),
				'\0',
			};

			SDL_Surface* srcSurface = TTF_RenderUTF8_Blended(font_, c, white);

			TTF_SizeText(font_, c, &dest.w, &dest.h);

			if (dest.x + dest.w >= FONT_SURFACE_SIZE)
			{
				dest.x = 0;
				dest.y += dest.h + 1;

				assert(dest.y + dest.h < FONT_SURFACE_SIZE);
			}

			SDL_BlitSurface(srcSurface, nullptr, surface_, &dest);

			glyphs_[i] = dest;

			SDL_FreeSurface(srcSurface);

			dest.x += dest.w;
		}
	}

	SDL_Color GlyphAtlas::getColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		SDL_Color color{};
		color.r = r;
		color.g = g;
		color.b = b;
		color.a = a;
		return color;
	}	
}