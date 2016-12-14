#version 330 core

in vec3 vPosition_vs; 
in vec3 vNormal_vs; 
in vec3 vFragColor; 

out vec3 fFragColor;

void main() {
    fFragColor = vec3(.3,.5,.8);
}
