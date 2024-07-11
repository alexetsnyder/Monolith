#include "Game.h"

#include "System/Exceptions/InitException.h"
#include "System/Logging/ErrorLog.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Mono
{
	Game::Game(const std::string& title, int windowWidth, int windowHeight)
		: gameState_{ GameState::RUNNING },
		  window_{ title.c_str(), windowWidth, windowHeight },
		  shader_{}, line_{}
	{
		createShader();
	}

	Game::~Game()
	{

	}

	void Game::run()
	{
		loop();
	}

	void Game::createShader()
	{
		if (!shader_.setVertexShader("Rendering/Shaders/basic.vert") ||
			!shader_.setFragmentShader("Rendering/Shaders/basic.frag") ||
			!shader_.compile() ||
			!shader_.link())
		{
			Sys::ErrorLog::log("Main::CreateShader", "Could not create Shaders");
			throw Sys::InitException("Failed to create shader.");
		}
	}

	void Game::pollEvents()
	{
		SDL_Event event;
		while (window_.pollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					gameState_ = GameState::EXIT;
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						gameState_ = GameState::EXIT;
					}
					else if (event.key.keysym.sym == SDLK_F1)
					{
						window_.toggleFullScreen();
					}
					break;
			}
		}
	}

	void Game::loop()
	{
		while (gameState_ != GameState::EXIT)
		{
			pollEvents();

			update();

			render();
		}
	}

	void Game::update()
	{

	}

	void Game::render()
	{
		window_.ClearBuffer();

		shader_.use();

		glm::mat4 projection{ 1.0f };// glm::ortho(0.0f, 100.0f, 0.0f, 100.0f, 0.1f, 100.0f) };
		glm::mat4 view{ 1.0f };
		glm::mat4 model{ 1.0f };

		shader_.setUniform("projection", projection);
		shader_.setUniform("view", view);
		shader_.setUniform("model", model);

		line_.draw(shader_);

		window_.SwapBuffer();
	}
}