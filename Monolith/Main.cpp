#include <cstdlib>
#include <iostream>

#include "Game.h"
#include "System/Exceptions/InitException.h"
#include "System/Logging/ErrorLog.h"
#include "System/SDLInit.h"

constexpr int screenWidth{ 1024 };
constexpr int screenHeight{ 768 };

int main(int argc, char** argv)
{
	try
	{
		Mono::Sys::SDLInit sdlInit{};
		Mono::Game game{ "Monolith", screenWidth, screenHeight };
		game.run();
	}
	catch (const Mono::Sys::InitException& exception)
	{
		Mono::Sys::ErrorLog::log("main", exception.what());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}