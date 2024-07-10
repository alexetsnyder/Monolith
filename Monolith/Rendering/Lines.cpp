#include "Lines.h"

namespace Mono
{
	float line[6]
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
	};

	Lines::Lines()
		: vao_{}, vbo_{}, lineCount_{}
	{
		glGenVertexArrays(1, &vao_);
		glGenBuffers(1, &vbo_);

		glBindVertexArray(vao_);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_);

		glBufferData(GL_ARRAY_BUFFER, sizeof(line), line, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		lineCount_ = 2;
	}

	Lines::~Lines()
	{
		glDeleteVertexArrays(1, &vao_);
		glDeleteBuffers(1, &vbo_);
	}

	void Lines::draw(const Shader& shader) const
	{
		glBindVertexArray(vao_);
		glDrawArrays(GL_LINES, 0, lineCount_);
		glBindVertexArray(0);
	}
}
