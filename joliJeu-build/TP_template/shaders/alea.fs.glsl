#version 330 core

in vec3 vPosition_vs; 
in vec3 vNormal_vs; 
in vec3 vFragColor; 

out vec3 fFragColor;

vec3 attenuation(float a, float b, vec2 vCentre, vec2 vPosition, vec3 vFragColor){
	float alpha = a*exp(-b*distance(vPosition, vCentre)*distance(vPosition, vCentre));
	return vFragColor*alpha;
}


void main() {
    fFragColor = attenuation(0.6, 100, vPosition_vs.xy, vPosition_vs.xy, vec3(1, 0.2, 1));
    //fFragColor = vec3(0.2, 0.2, 1);
}
