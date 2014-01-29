#version 330

in vec4 position;
in vec2 texcoord;


out vec2 vTexcoord;
out vec4 vColor;


void main() {
	vTexcoord = texcoord ;
	gl_Position = position;
}