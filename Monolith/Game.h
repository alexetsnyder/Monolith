#pragma once

#include "Rendering/Shader.h"
#include "System/Windows/Window.h"

#include <string>

namespace Mono
{
	enum class GameState
	{
		RUNNING,
		EXIT,
	};

	class Game
	{
		public:
			Game(const std::string& title, int windowWidth, int windowHeight);
			~Game();

			void run();

		private:
			void createShader();
			void pollEvents();
			void loop();
			void update();
			void render();

			GameState gameState_;
			Sys::Window window_;
			Shader shader_;
	};
}
