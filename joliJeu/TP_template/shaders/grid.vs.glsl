#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;
out vec2 vPosition;

void main() {
 
  gl_Position = vec4(aVertexPosition, 0, 1);
  vPosition = aVertexPosition;
  vFragColor = aVertexColor;
};