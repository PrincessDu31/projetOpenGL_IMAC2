#version 330 core

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;
layout(location = 2) in vec3 aVertexNormal; // Normale du sommet



// Matrices de transformations reçues en uniform
uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

// Sorties du shader
out vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
out vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
out vec3 vFragColor; // Coordonnées de texture du sommet



void main() {
 
  // gl_Position = vec4(aVertexPosition, 1);
  // vPosition_vs = aVertexPosition;
//  vFragColor = aVertexColor;



	//Conversion coord homogènes
	vec4 vertexPosition = vec4(aVertexPosition, 1);
	vec4 vertexNormal = vec4(aVertexNormal, 0);

	vPosition_vs = vec3 (uMVPMatrix * vertexPosition);
	vNormal_vs =  vec3 (uNormalMatrix*vertexNormal);
	vFragColor = aVertexColor;

	gl_Position = uMVPMatrix * vertexPosition;

}