#pragma once

#include "Geometry/Mesh.h"
#include "Rendering/MeshRenderer.h"
#include "SpriteSheet.h"

#include <glm/glm.hpp>

namespace Mono
{
	class Sprite
	{
		public:
			Sprite(const SpriteSheet* spriteSheet, const glm::vec3 position, const glm::vec2 size);
			~Sprite() {};
			Sprite(const Sprite&) = delete;

			void draw(const Shader& shader) const;

		private:
			void fillMesh(Mesh& mesh);

			glm::vec3 position_;
			glm::vec2 size_;
			MeshRenderer meshRenderer_;
			const SpriteSheet* spriteSheet_;
	};
}
