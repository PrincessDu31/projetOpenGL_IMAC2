#version 330 core

in vec2 vTexCoords;
out vec3 fFragColor;


uniform sampler2D uTextureMonster;

void main() {
	fFragColor = vec3(texture(uTextureMonster, vTexCoords));
}