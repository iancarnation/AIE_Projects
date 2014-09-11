#version 120
// very simple vertex shader that just transforms an object-space
// position into clip space and passes along a texture coordinate

attribute vec4 Position;
attribute vec4 Color;
attribute vec2 UV;

varying vec2 vUV;
varying vec4 vColor;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;
uniform vec4 tintColor;
uniform vec2 uvScale;
uniform vec2 uvOffset;

void main()
{
	vUV = UV * uvScale + uvOffset;
	vColor = Color * tintColor;
	gl_Position = Projection * View * Model * Position;
}

