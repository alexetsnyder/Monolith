#pragma once

#include "Rendering/Shader.h"
#include "Rendering/Shapes/Quad.h"
#include "Rendering/Sprites/SpriteLoader.h"
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
			glm::mat4 projection_;
			Shader shader_;
			SpriteLoader spriteLoader_;
			Quad quad_;
	};
}
