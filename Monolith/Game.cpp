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
		  projection_{ glm::ortho(0.0f, static_cast<float>(window_.width()), 0.0f, static_cast<float>(window_.height())) },
		  spriteSheet_{ "Assets/Textures/Haowan_Curses_1440x450.png", glm::vec2(288.0f, 288.0f), glm::vec2(18.0f, 18.0f) },
		  sprite_{ &spriteSheet_, glm::vec3(500.0f, 300.0f, 0.0f), glm::vec2(16.0f, 16.0f) },
		  world_{ &spriteSheet_, glm::vec2(64.0f, 64.0f), glm::vec2(16.0f, 16.0f) },
		  shader_{}
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
				case SDL_WINDOWEVENT:
					if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
					{
						projection_ = glm::ortho(0.0f, static_cast<float>(window_.width()), 0.0f, static_cast<float>(window_.height()));
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

		glm::mat4 view{ 1.0f };
		glm::mat4 model{ 1.0f };

		shader_.setUniform("projection", projection_);
		shader_.setUniform("view", view);
		shader_.setUniform("model", model);

		world_.draw(shader_);
		sprite_.draw(shader_);

		window_.SwapBuffer();
	}
}