#version 330 core

in vec3 vFragColor;
in vec3 vPosition;

out vec3 fFragColor;

uniform vec2 uSizeMap;


vec3 attenuation(float a, float b, vec2 vCentre, vec2 vPosition, vec3 vFragColor){
	float alpha = a*exp(-b*distance(vPosition, vCentre)*distance(vPosition, vCentre));
	return vFragColor*alpha;
}

vec3 grid(float spaceX, float spaceY, vec2 vPosition, float sizeLine){
	float nbLine = uSizeMap.x/spaceX;
	int i = 0;
	for (i = 0; i < nbLine; i++){
		if (abs(vPosition.x) < i*spaceX + sizeLine*0.5){
			if (abs(vPosition.x) > i*spaceX - sizeLine*0.5) {
				return attenuation(0.3, 70, vec2(sign(vPosition.x)*i*spaceX, vPosition.y), vPosition, vec3(0.2, 0.2, 1));
				//return attenuation(0.3, 60, vec2(sign(vPosition.x)*i*spaceX, vPosition.y), vPosition, vec3(1, 0, 1));
			}
		}
	}
	nbLine = uSizeMap.y/spaceY;
	for (i = 0; i < nbLine; i++){
		if (abs(vPosition.y) < i*spaceY*1.3 + sizeLine*0.5){
			if (abs(vPosition.y) > i*spaceY*1.3 - sizeLine*0.5) {
				return attenuation(0.3, 70, vec2(vPosition.x, sign(vPosition.y)*i*spaceY*1.3), vPosition, vec3(0.2, 0.2, 1));
				//return attenuation(0.3, 60, vec2(sign(vPosition.x)*i*spaceY, vPosition.y), vPosition, vec3(1, 0, 1));
			}
		}
	}
	return vec3(0,0,0);
}


void main() {
	
	fFragColor = grid(0.01, 0.03, vPosition.xy, 0.00065);
};