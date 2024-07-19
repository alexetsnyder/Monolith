#include "World.h"

#include "Geometry/Quad.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Mono
{
	World::World(const SpriteSheet* spriteSheet, const glm::vec2& size, const glm::vec2& tileSize)
		: spriteSheet_{ spriteSheet }, meshRenderer_{}, size_{ size }, tileSize_{ tileSize }
	{
		createWorld();
	}

	void World::draw(const Shader& shader) const
	{
		glm::mat4 model{ 1.0f };
		model = glm::translate(model, glm::vec3(6.0f, 6.0f, 0.0f));
		model = glm::scale(model, glm::vec3(tileSize_.x, tileSize_.y, 0.0f));
		shader.setUniform("model", model);

		shader.setUniform("color", glm::vec3(0.0f, 0.0f, 1.0f));

		spriteSheet_->bind();
		meshRenderer_.draw(shader);
	}

	void World::createWorld()
	{
		Mesh mesh{};
		int vertexCount{ 0 };
		for (int i = 0; i < size_.y; i++)
		{
			for (int j = 0; j < size_.x; j++)
			{
				glm::vec3 position{ static_cast<float>(j), static_cast<float>(i), 0.0f };
				createTile(position, mesh, vertexCount);
			}
		}

		meshRenderer_.sendData(mesh);
	}

	void World::createTile(const glm::vec3& position, Mesh& mesh, int& vertexCount)
	{
		std::vector<float> coordinates{ spriteSheet_->textureCoordinates(8, 14) };

		for (int v = 0; v < 12; v += 3)
		{
			int coordIndex = 2 * (v / 3);
			Vertex vertex{
				{ position.x + quadVertices[v], position.y + quadVertices[v + 1], position.z + quadVertices[v + 2]},
				{ coordinates[coordIndex], coordinates[coordIndex + 1] }
			};

			mesh.addVertex(vertex);
		}

		for (int i = 0; i < 6; i++)
		{
			mesh.addIndex(vertexCount + quadIndices[i]);
		}

		vertexCount += 4;
	}
}