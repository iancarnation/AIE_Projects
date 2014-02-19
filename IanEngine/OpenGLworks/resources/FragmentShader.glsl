#version 330
in vec4 vColor;
in vec2 UV;
out vec4 outColor;
uniform sampler2D diffuseTexture;
void main () {
	outColor = texture(diffuseTexture, UV).rgba;
}