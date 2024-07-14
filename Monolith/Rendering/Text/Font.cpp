#include "Font.h"

namespace Mono
{
	const std::string FontName::Px437_IBM_VGA_8x14{ "Px437_IBM_VGA_8x14" };

	Font::Font(const std::string name, const std::string& filePath, int fontSize)
		: name_{ name }, fontSize_{ fontSize }, atlas_{ filePath.c_str(), fontSize }
	{

	}

	void Font::blitSurface(char c, int x, int y, SDL_Surface* dstSurface)
	{
		SDL_Rect srcRect{ atlas_.getGlyph(static_cast<int>(c)) };

		SDL_Rect dstRect
		{
			x,
			y,
			srcRect.w,
			srcRect.h,
		};

		SDL_BlitSurface(atlas_.surface(), &srcRect, dstSurface, &dstRect);
	}
}