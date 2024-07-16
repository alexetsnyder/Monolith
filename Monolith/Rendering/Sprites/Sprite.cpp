#include "Sprite.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Mono
{
	float quadVertices[20]
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

	Sprite::Sprite(const glm::vec3 position, const glm::vec2 size)
		: position_{ position }, size_{ size }, meshRenderer_{},
		  texture_{ static_cast<int>(size.x), static_cast<int>(size.y), TextureSettings{ GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR } }
	{

	}

	void Sprite::draw(const Shader& shader) const
	{
		glm::mat4 model{ 1.0f };
		model = glm::translate(model, position_);
		model = glm::scale(model, glm::vec3(size_.x, size_.y, 0.0f));
		shader.setUniform("model", model);

		texture_.bind();
		meshRenderer_.draw(shader);
	}

	void Sprite::fillMesh(Mesh& mesh)
	{
		for (int v = 0; v < 20; v += 5)
		{
			Vertex vertex{
				{ quadVertices[v], quadVertices[v + 1], quadVertices[v + 2]},
				{ 0.0f, 0.0f }
			};

			mesh.addVertex(vertex);
		}

		for (int i = 0; i < 6; i++)
		{
			mesh.addIndex(quadIndices[i]);
		}
	}
}