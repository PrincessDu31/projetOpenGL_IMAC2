
#version 330 core

in vec2 vTexCoords;
out vec3 fFragColor;


uniform sampler2D uTextureOeil;

vec3 attenuation(float a, float b, vec2 vCentre, vec2 vPosition, vec3 vFragColor){
	float alpha = a*exp(-b*distance(vPosition, vCentre)*distance(vPosition, vCentre));
	return vFragColor*alpha;
}


void main() {
	//fFragColor = vec3(0.63, 0.63, 0.63);
	fFragColor = vec3(texture(uTextureOeil, vTexCoords));
		
	// fFragColor = attenuation(1, 10, vec2(0,0), vPosition_vs.xy, fFragColor);
	
};


