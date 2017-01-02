#version 330 core

in vec3 vFragColor;
in vec3 vPosition;

out vec3 fFragColor;

uniform vec2 uSizeMap;


vec3 attenuation(float a, float b, vec2 vCentre, vec2 vPosition, vec3 vFragColor){
	float alpha = a*exp(-b*distance(vPosition, vCentre)*distance(vPosition, vCentre));
	return vFragColor*alpha;
}

vec3 grid(float spaceX, float spaceY, vec3 vPosition, float sizeLine){
	float nbLine = uSizeMap.x/spaceX; 
	int i = 0;
	for (i = 0; i < nbLine; i++){
		if (abs(vPosition.x)*uSizeMap.x < i*spaceX + sizeLine){
			if (abs(vPosition.x)*uSizeMap.x > i*spaceX - sizeLine) {
				return vec3(0.2, 0.2, 1);
			}
		}
	}

	nbLine = uSizeMap.y/spaceY; //change 30 into 
	for (i = 0; i < nbLine; i++){
		if (abs(vPosition.z)*uSizeMap.y < i*spaceY + sizeLine){
			if (abs(vPosition.z)*uSizeMap.y > i*spaceY - sizeLine) {
				
					return vec3(0.2, 0.2, 1);
				
			}
		}
	}
	return vec3(0,0,0);
}



void main() {
	
	fFragColor = grid(0.5, 0.5, vPosition, 0.01);


}