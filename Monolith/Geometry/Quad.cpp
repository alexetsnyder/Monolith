#include "Quad.h"

namespace Mono
{
	const float quadVertices[12]
	{
		 0.5f,  0.5f, 0.0f,  //top right
		-0.5f,  0.5f, 0.0f,  //top left
		 0.5f, -0.5f, 0.0f,  //bottom right
		-0.5f, -0.5f, 0.0f,  //bottom left
	};

	const int quadIndices[6]
	{
		0, 1, 2,
		2, 1, 3,
	};
}