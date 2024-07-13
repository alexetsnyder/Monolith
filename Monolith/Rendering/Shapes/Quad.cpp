#include "Quad.h"

namespace Mono
{
	float quadVertexArray[20]
	{
		 0.5f,  0.5f, 0.0f,  1.0f, 0.0f,	//top right
		-0.5f,  0.5f, 0.0f,  0.0f, 0.0f,	//top left
		 0.5f, -0.5f, 0.0f,  1.0f, 1.0f,	//bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f,	//bottom left
	};

	int quadIndexArray[6]
	{
		0, 1, 2,
		2, 1, 3,
	};

	Quad::Quad()
		: meshRenderer_{}
	{
		Mesh mesh{};
		for (int v = 0; v < 20; v += 5)
		{
			Vertex vertex{
				{ quadVertexArray[v], quadVertexArray[v + 1], quadVertexArray[v + 2]},
				{ quadVertexArray[v + 3], quadVertexArray[v + 4] }
			};

			mesh.addVertex(vertex);
		}

		for (int i = 0; i < 6; i++)
		{
			mesh.addIndex(quadIndexArray[i]);
		}

		meshRenderer_.sendData(mesh);
	}
}