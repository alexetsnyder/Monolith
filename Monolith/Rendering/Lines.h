#pragma once

#include "Shader.h"

#include <glad/glad.h>

namespace Mono
{
	class Lines
	{
		public:
			Lines();
			~Lines();

			void draw(const Shader& shader) const;

		private:
			GLuint vao_;
			GLuint vbo_;
			int lineCount_;
	};
}
