#pragma once

#include "Rendering/IRenderer.h"
#include "Rendering/MeshRenderer.h"

namespace Mono
{
	class Quad
	{
		public:
			Quad();
			~Quad() {};

			const IRenderer* renderer() const { return &meshRenderer_; };

		private:
			MeshRenderer meshRenderer_;
	};
}
