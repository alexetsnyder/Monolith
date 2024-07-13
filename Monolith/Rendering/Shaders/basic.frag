#version 460 core
out vec4 FragmentColor;

in vec2 TextureCoordinates;

uniform sampler2D glyphAtlas;

void main()
{
	FragmentColor = texture(glyphAtlas, TextureCoordinates);
}
