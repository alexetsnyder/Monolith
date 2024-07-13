#include "Texture.h"

namespace Mono
{
	Texture::Texture(SDL_Surface* surface, TextureSettings settings)
	{
		glGenTextures(1, &id_);
		bind();

		setTextureSettings(settings);

		SDL_Surface* convSurface = convertSurfaceForOpenGL(surface);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, convSurface->w, convSurface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, convSurface->pixels);
		glGenerateMipmap(GL_TEXTURE_2D);

		SDL_FreeSurface(convSurface);
	}

	Texture::Texture(int width, int height, TextureSettings settings)
	{
		glGenTextures(1, &id_);
		bind();

		setTextureSettings(settings);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &id_);
	}

	void Texture::updateTexture(SDL_Surface* newSurface)
	{
		glBindTexture(GL_TEXTURE_2D, id_);

		SDL_Surface* convSurface = convertSurfaceForOpenGL(newSurface);

		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, convSurface->w, convSurface->h, GL_RGBA, GL_UNSIGNED_BYTE, convSurface->pixels);
		glGenerateMipmap(GL_TEXTURE_2D);

		SDL_FreeSurface(convSurface);
	}

	void Texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, id_);
	}

	void Texture::setTextureSettings(TextureSettings settings)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, settings.sWrap);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, settings.tWrap);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, settings.minFilter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, settings.magFilter);
	}

	SDL_Surface* Texture::convertSurfaceForOpenGL(SDL_Surface* srcSurface)
	{
		SDL_Rect srcRect{ 0, 0, srcSurface->w, srcSurface->h };

		uint32_t redMask;
		uint32_t greenMask;
		uint32_t blueMask;
		uint32_t alphaMask;

#if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		redMask = 0xff000000;
		greenMask = 0x00ff0000;
		blueMask = 0x0000ff00;
		alphaMask = 0x000000ff;
#else
		redMask = 0x000000ff;
		greenMask = 0x0000ff00;
		blueMask = 0x00ff0000;
		alphaMask = 0xff000000;
#endif

		SDL_Surface* destSurface = SDL_CreateRGBSurface(0, srcRect.w, srcRect.h, 32, redMask, greenMask, blueMask, alphaMask);

		SDL_BlitSurface(srcSurface, &srcRect, destSurface, &srcRect);

		return destSurface;
	}
}