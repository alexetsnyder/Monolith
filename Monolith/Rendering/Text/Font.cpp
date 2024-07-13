#include "Font.h"

namespace Mono
{
	Font::Font(const std::string name, const std::string& filePath, int fontSize)
		: name_{ name }, atlas_{ filePath.c_str(), fontSize }
	{

	}

	void Font::draw(const Shader& shader) const
	{

	}
}