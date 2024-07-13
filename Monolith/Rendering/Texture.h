#pragma once

#include <glad/glad.h>
#include <SDL/SDL.h>

namespace Mono
{
	struct TextureSettings
	{
		GLenum sWrap;
		GLenum tWrap;
		GLenum minFilter;
		GLenum magFilter;
	};

	class Texture
	{
		public:
			Texture(SDL_Surface* surface, TextureSettings settings);
			Texture(int width, int height, TextureSettings settings);
			~Texture();
			Texture(const Texture&) = delete;

			void updateTexture(SDL_Surface* newSurface);

			void bind() const;

		private:
			void setTextureSettings(TextureSettings settings);
			SDL_Surface* convertSurfaceForOpenGL(SDL_Surface* srcSurface);

			GLuint id_;
	};
}
