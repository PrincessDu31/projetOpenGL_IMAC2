#version 330 core

in vec3 vFragColor;
in vec3 vPosition;

out vec3 fFragColor;

uniform vec2 uSizeMap;


vec3 blue = vec3(1, 0, 1);
vec3 pink = vec3(0.2, 0.2, 1);
vec3 yellow = vec3(0.8, 0.8, 0.6);

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
				//	return attenuation(0.3, 70, vec2(sign(vPosition.x)*i*spaceX, vPosition.y), vPosition, vec3(0.2, 0.2, 1));
				// else

				 	return attenuation(0.3, 60, vec2(sign(vPosition.x)*i*spaceX, vPosition.y), vPosition, yellow);
			}
		}
	}
	nbLine = uSizeMap.y/spaceY;
	for (i = 0; i < nbLine; i++){

		if (abs(vPosition.y) < i*spaceY*1.3 + sizeLine*0.5){
			if (abs(vPosition.y) > i*spaceY*1.3 - sizeLine*0.5) {
				//return attenuation(0.3, 70, vec2(vPosition.x, sign(vPosition.y)*i*spaceY*1.3), vPosition, vec3(0.2, 0.2, 1));

				return attenuation(0.3, 60, vec2(sign(vPosition.x)*i*spaceY, vPosition.y), vPosition, yellow);
			}
		}
	}
	return vec3(0,0,0);
}

// vec3 actuFind (vec3 currentColor, vec2 currentPos) {
// 	int i = int((currentPos.x + 1) * 15);		// i max = 30
// 	int j = int((currentPos.y + 1) * 15);	//j est supperieur ou egal à 14 et inferieur à 15
// 	if (i*30 + j < 500)
// 		if (uniformMapFind[i*30 + j] > 0) return  vec3((i*30 + j)/900,(i*30 + j)/900, 1);
// 	if (j == 14 && i == 14) return  vec3(0,0, 0.5);	// TEMPORAIRE
// 	return currentColor;
// }



void main() {
	
	fFragColor = grid(0.01, 0.03, vPosition.xy, 0.1);
	fFragColor = yellow;
}