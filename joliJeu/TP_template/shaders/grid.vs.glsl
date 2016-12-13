#version 330 core

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;
layout(location = 2) in vec3 aVertexNormal; // Normale du sommet


// Matrices de transformations reçues en uniform
uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;


out vec3 vPosition; // Position du sommet transformé dans l'espace View
out vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
out vec3 vFragColor; // Coordonnées de texture du sommet
out vec2 vTexCoords;

void main() {
 
	vec4 vertexPosition = vec4(aVertexPosition, 1);
	vec4 vertexNormal = vec4(aVertexNormal, 0);

//	vPosition = vec3 (uMVPMatrix * vertexPosition);
	vPosition = aVertexPosition;

	vNormal_vs =  vec3 (uNormalMatrix*vertexNormal);
	vFragColor = aVertexColor;


	gl_Position = uMVPMatrix * vertexPosition;

};