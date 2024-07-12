#include "Lines.h"

#include <vector>

namespace Mono
{
	Lines::Lines()
		: vao_{}, vbo_{}, lineCount_{}
	{
		std::vector<float> gridData{};
		createGrid(gridData);
		sendGridData(gridData);
	}

	Lines::~Lines()
	{
		glDeleteVertexArrays(1, &vao_);
		glDeleteBuffers(1, &vbo_);
	}

	void Lines::createGrid(std::vector<float>& gridData)
	{
		for (int i = 0; i <= 150; i+=2)
		{
			gridData.push_back(0.0f);
			gridData.push_back(static_cast<float>(i));
			gridData.push_back(0.0f);

			gridData.push_back(200.0f);
			gridData.push_back(static_cast<float>(i));
			gridData.push_back(0.0f);
		}

		for (int j = 0; j <= 200; j+=2)
		{
			gridData.push_back(static_cast<float>(j));
			gridData.push_back(0.0f);
			gridData.push_back(0.0f);

			gridData.push_back(static_cast<float>(j));
			gridData.push_back(150.0f);
			gridData.push_back(0.0f);
		}
	}

	void Lines::sendGridData(const std::vector<float>& gridData)
	{
		if (!gridData.empty())
		{
			glGenVertexArrays(1, &vao_);
			glGenBuffers(1, &vbo_);

			glBindVertexArray(vao_);
			glBindBuffer(GL_ARRAY_BUFFER, vbo_);

			glBufferData(GL_ARRAY_BUFFER, gridData.size() * sizeof(float), gridData.data(), GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

			lineCount_ = gridData.size();
		}	
	}

	void Lines::draw(const Shader& shader) const
	{
		glBindVertexArray(vao_);
		glDrawArrays(GL_LINES, 0, lineCount_);
		glBindVertexArray(0);
	}
}
