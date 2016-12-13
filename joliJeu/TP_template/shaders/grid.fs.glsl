#version 330 core

in vec3 vFragColor;
in vec2 vPosition;

out vec3 fFragColor;

vec3 attenuation(float a, float b, vec2 vCentre, vec2 vPosition, vec3 vFragColor){
	float alpha = a*exp(-b*distance(vPosition, vCentre)*distance(vPosition, vCentre));
	return vFragColor*alpha;
}

vec3 grid(float space, vec2 vPosition, float sizeLine){
	float nbLine = 2./space;
	int i = 0;
	for (i = 0; i < nbLine; i++){
		if (abs(vPosition.x) < i*space + sizeLine*0.5){
			if (abs(vPosition.x) > i*space - sizeLine*0.5) {
				return attenuation(0.3, 70, vec2(sign(vPosition.x)*i*space, vPosition.y), vPosition, vec3(0.2, 0.2, 1));
				//return attenuation(0.3, 60, vec2(sign(vPosition.x)*i*space, vPosition.y), vPosition, vec3(1, 0, 1));
			}
		}
	}
	for (i = 0; i < nbLine; i++){
		if (abs(vPosition.y) < i*space*1.3 + sizeLine*0.5){
			if (abs(vPosition.y) > i*space*1.3 - sizeLine*0.5) {
				return attenuation(0.3, 70, vec2(vPosition.x, sign(vPosition.y)*i*space*1.3), vPosition, vec3(0.2, 0.2, 1));
				//return attenuation(0.3, 60, vec2(sign(vPosition.x)*i*space, vPosition.y), vPosition, vec3(1, 0, 1));
			}
		}
	}
	return vec3(0,0,0);
}


void main() {
	
	fFragColor = grid(0.2, vPosition, 0.01);
};