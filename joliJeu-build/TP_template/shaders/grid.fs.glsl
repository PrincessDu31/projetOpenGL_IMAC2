#version 330 core

in vec3 vFragColor;
in vec3 vPosition;

out vec3 fFragColor;

uniform vec2 uSizeMap;




struct InfosMaps
{
  int find;
  int alea;
  int ground;
};

uniform InfosMaps uniformArrayOfMapInfos[30*30];
 






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
				// else
				// 	return attenuation(0.3, 60, vec2(sign(vPosition.x)*i*spaceX, vPosition.y), vPosition, vec3(1, 0, 1));
			}
		}
	}
	nbLine = uSizeMap.y/spaceY;
	for (i = 0; i < nbLine; i++){
		if (abs(vPosition.y) < i*spaceY + sizeLine*0.5){
			if (abs(vPosition.y) > i*spaceY - sizeLine*0.5) {
				//if (uFind == 0)
					return attenuation(0.3, 70, vec2(vPosition.x, sign(vPosition.y)*i*spaceY), vPosition, vec3(0.2, 0.2, 1));
				// else
				// 	return attenuation(0.3, 60, vec2(sign(vPosition.x)*i*spaceY, vPosition.y), vPosition, vec3(1, 0, 1));
			}
		}
	}
	return vec3(0,0,0);
}

vec3 actuFind (vec3 currentColor, vec2 currentPos) {
	// int i = 0;
	// for (i = 0; i < 900; i++) currentColor = vec3(uniformArrayOfMapInfos[i]*255, uniformArrayOfMapInfos[i]*255, uniformArrayOfMapInfos[i]*255);
	
	int i = int(currentPos.x*30);		// i max = 15
	int j = int(currentPos.y *  30);
	if (uniformArrayOfMapInfos[14].find > 0.5) return  vec3(1, 0, 1);
//	if (i > 15) return  vec3(1, 1, 1);
	return currentColor;
}



void main() {
	
	fFragColor = grid(0.01, 0.03, vPosition.xy, 0.00065);

	fFragColor = actuFind(fFragColor, vPosition.xy);
};