#pragma once

#include "Rendering/Lines.h"
#include "Rendering/Shader.h"
#include "System/Windows/Window.h"

#include "Rendering/Shapes/Quad.h"
#include "Rendering/Text/GlyphAtlas.h"
#include "Rendering/Texture.h"

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
			GlyphAtlas atlas_;
			Texture texture_;
			Quad quad_;
			//Lines line_;
	};
}
