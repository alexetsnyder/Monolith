#pragma once

#include "IRenderer.h"

namespace Mono
{
	class MeshRenderer : public IRenderer
	{
		public:
			MeshRenderer();
			~MeshRenderer();

			//From IRenderer
			void sendData(const Mesh& mesh) override;
			void draw(const Shader& shader) const override;

		private:
			GLuint vao_;
			GLuint ebo_;
			GLuint vbo_;
			GLsizei indicesCount_;
	};
}
