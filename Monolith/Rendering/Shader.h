#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>

namespace Mono
{
	class Shader
	{
		public:
			Shader();
			~Shader();

			bool setVertexShader(const std::string& shaderPath);

			bool setFragmentShader(const std::string& shaderPath);

			bool compile();

			bool link();

			void use() const;

			void setUniform(const std::string& name, const glm::mat4& matrix) const;

		private:
			bool setShader(const std::string shaderPath, int glShader);
			std::string readFile(const std::string& filePath);
			bool compile(GLuint shader, std::vector<GLchar>& infoLog);

			GLuint programID_;
			GLuint vertexID_;
			GLuint fragmentID_;
	};
}
