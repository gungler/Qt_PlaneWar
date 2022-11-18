#version 450 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D tex;
uniform vec3 inColor;

void main()
{
    color =  vec4(inColor, 1.0) * texture(tex, TexCoords);
}
