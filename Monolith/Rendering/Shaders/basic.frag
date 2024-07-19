#version 460 core
out vec4 FragmentColor;

in vec2 TextureCoordinates;

uniform sampler2D glyphAtlas;
uniform vec3 color;

void main()
{
	FragmentColor = vec4(color, 1.0f) * texture(glyphAtlas, TextureCoordinates);
}
