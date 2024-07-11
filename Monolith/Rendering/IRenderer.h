#pragma once

#include "Shader.h"

namespace Mono
{
	class IRenderer
	{
		public:
			virtual ~IRenderer() {};
			virtual void sendData() = 0;
			virtual void draw(const Shader& shader) const = 0;
	};
}