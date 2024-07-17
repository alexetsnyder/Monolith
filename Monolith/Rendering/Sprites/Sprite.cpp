#include "Sprite.h"

#include <glm/gtc/matrix_transform.hpp>

#include <vector>

namespace Mono
{
	float quadVertices[12]
	{
		 0.5f,  0.5f, 0.0f,  //top right
		-0.5f,  0.5f, 0.0f,  //top left
		 0.5f, -0.5f, 0.0f,  //bottom right
		-0.5f, -0.5f, 0.0f,  //bottom left
	};

	int quadIndices[6]
	{
		0, 1, 2,
		2, 1, 3,
	};

	std::vector<float> textureCoordinates
	{
		1.0f, 0.0f,
		0.0f, 0.0f,	
		1.0f, 1.0f,	
		0.0f, 1.0f,
	};

	Sprite::Sprite(const SpriteSheet* spriteSheet, const glm::vec3 position, const glm::vec2 size)
		: position_{ position }, size_{ size }, meshRenderer_{},
		  spriteSheet_{ spriteSheet }
	{
		Mesh mesh{};
		fillMesh(mesh);
		meshRenderer_.sendData(mesh);
	}

	void Sprite::draw(const Shader& shader) const
	{
		glm::mat4 model{ 1.0f };
		model = glm::translate(model, position_);
		model = glm::scale(model, glm::vec3(size_.x, size_.y, 0.0f));
		shader.setUniform("model", model);

		spriteSheet_->bind();
		meshRenderer_.draw(shader);
	}

	void Sprite::fillMesh(Mesh& mesh)
	{
		std::vector<float> coordinates{ spriteSheet_->textureCoordinates(15, 1) };

		for (int v = 0; v < 12; v += 3)
		{
			int coordIndex = 2 * (v / 3);
			Vertex vertex{
				{ quadVertices[v], quadVertices[v + 1], quadVertices[v + 2]},
				{ coordinates[coordIndex], coordinates[coordIndex + 1] }
			};

			mesh.addVertex(vertex);
		}

		for (int i = 0; i < 6; i++)
		{
			mesh.addIndex(quadIndices[i]);
		}
	}
}