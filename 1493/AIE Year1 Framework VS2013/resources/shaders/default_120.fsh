#version 120
// very simple pixel shader that just samples a texture

varying vec2 vUV;
varying vec4 vColor;

uniform sampler2D diffuseTexture;

void main()
{
    gl_FragColor = texture2D(diffuseTexture, vUV) * vColor;
}
