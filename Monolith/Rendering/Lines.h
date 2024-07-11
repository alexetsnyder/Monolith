#pragma once

#include "Shader.h"

#include <glad/glad.h>

#include <vector>

namespace Mono
{
	class Lines
	{
		public:
			Lines();
			~Lines();

			void createGrid(const std::vector<float>& gridData);
			void sendGridData(const std::vector<float>& gridData);

			void draw(const Shader& shader) const;

		private:
			GLuint vao_;
			GLuint vbo_;
			int lineCount_;
	};
}
