#pragma once

#include "Rendering/Shader.h"
#include "Rendering/Sprites/Sprite.h"
#include "Rendering/Sprites/SpriteSheet.h"
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
			SpriteSheet spriteSheet_;
			Sprite sprite_;
	};
}
