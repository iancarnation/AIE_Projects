#version 330
in vec3 position;
in vec4 color;
in vec2 texcoord;
out vec2 UV;
out vec4 vColor;
uniform mat4 matrix; // our matrix
void main() {
	UV = texcoord;
	gl_Position = matrix * vec4 (position, 1.0);
	vColor = color;
}