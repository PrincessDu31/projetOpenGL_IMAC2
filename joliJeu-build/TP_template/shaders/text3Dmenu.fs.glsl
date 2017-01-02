#version 330 core

in vec2 vTexCoords;
out vec3 fFragColor;


uniform sampler2D uTextureMenu_1;

void main() {
	fFragColor = vec3(texture(uTextureMenu_1, vTexCoords));
	//fFragColor = vec3(1, 0, 0);
}