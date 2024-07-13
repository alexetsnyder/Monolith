#pragma once

#include "Mesh.h"
#include "Shader.h"

namespace Mono
{
	class IRenderer
	{
		public:
			virtual ~IRenderer() {};
			virtual void sendData(const Mesh& mesh) = 0;
			virtual void draw(const Shader& shader) const = 0;
	};
}