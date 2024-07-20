#include "SDLInit.h"

#include "Exceptions/InitException.h"
#include "Logging/ErrorLog.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

namespace Mono::Sys
{
	SDLInit::SDLInit()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			ErrorLog::log("SDL_Init(SDL_INIT_EVERYTHIG)", SDL_GetError());
			throw InitException("SDL_Init failed.");
		}

		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		{
			ErrorLog::log("IMG_Init(IMG_INIT_PNG)", SDL_GetError());
			SDL_Quit();
			throw InitException("IMG_Init failed.");
		}

		if (TTF_Init() < 0)
		{
			ErrorLog::log("TTF_Init()", SDL_GetError());
			IMG_Quit();
			SDL_Quit();
			throw InitException("TTF_Init failed.");
		}
	}

	SDLInit::~SDLInit()
	{
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
	}
}