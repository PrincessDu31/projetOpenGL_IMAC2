#include <iostream>
#include <glimac/Monster.hpp>

using namespace std;

Monster::Monster(){
	detection = DISACTIVE;
	setSpeed(1);
}

Monster::Monster(glm::vec2 pos) {
	detection = DISACTIVE;
	setSpeed(1);
	setAttack(3);
	setDefense(2);
	setPosition(pos);
	setLife(1);
	setOrientation(glm::vec2(0,1));
}

Monster::~Monster() {

}



// void Monster::attack1(MainCaracter m) {

// }
// void Monster::attack2(MainCaracter m) {
	
// }
// void Monster::attack3(MainCaracter m) {
	
// }


// void Monster::doAction (MainCaracter m) {
// // 	switch(monsterType){
// // 		case M1:
// // 		{
// // 			attack1(m);
// // 			break;
// // 		}
// // 		case M2:
// // 		{
// // 			attack2(m);
// // 			break;
// // 		}
// // 		case M3:
// // 		{
// // 			attack3(m);
// // 			break;
// // 		}
		
// // 		default :
// // 			break;
// // 	}
// }

// void Monster::setPosition(glm::vec2 p){ 
// 		setPosition(p);
// }

void Monster::setType(std::string t){ 
	if (t == "groark") {
		monsterType = M1;
	} else if ( t == "bzzz") {
		monsterType = M2;
	} else {
		monsterType = M3;
	}
}	

void Monster::setDetection(Detection d){
	detection = d;
}

void Monster::setDistanceToPlayer(float d){
	distanceToPlayer = d;
}

Detection Monster::getDetection(){
	return detection;
}

float Monster::getDistanceToPlayer(){
	return distanceToPlayer;
}


void Monster::updatePosition(glm::vec3 v){
	glm::vec2 position;
	position.x = getPosition().x + v.x;
	position.y = getPosition().y + v.z;
	setPosition(position);
}


std::string Monster::fromEnumToString() {
	switch (monsterType){
		case M1:
			return "M1";
			break;
		case M2:
			return "M2";
			break;
		case M3:
			return "M3";
			break;
		
		default:
			return "NO_TYPE";
			break;
	}

}

std::string Monster::fromEnumToStringDetection(){
	switch (detection){
		case ACTIVE:
			return "ACTIVE";
			break;
		case DISACTIVE:
			return "DISACTIVE";
			break;
		default:
			return "NO_FUNCTION";
			break;
	}

}