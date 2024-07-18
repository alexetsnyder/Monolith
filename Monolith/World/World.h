#pragma once

#include "Geometry/Mesh.h"
#include "Rendering/MeshRenderer.h"
#include "Rendering/Shader.h"
#include "Rendering/Sprites/SpriteSheet.h"

#include <glm/glm.hpp>

namespace Mono
{
	class World
	{
		public:
			World(const SpriteSheet* spriteSheet, const glm::vec2& size);
			~World() {};
			World(const World&) = delete;

			void draw(const Shader& shader) const;

		private:
			void createWorld();
			void createTile(const glm::vec3& position, Mesh& mesh, int& vertexCount);

			const SpriteSheet* spriteSheet_;
			MeshRenderer meshRenderer_;
			glm::vec2 size_;
	};
}
