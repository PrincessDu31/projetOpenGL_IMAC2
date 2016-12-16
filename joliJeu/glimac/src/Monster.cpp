
#include <glimac/Monster.hpp>

Monster::Monster(){

}

Monster::Monster(glm::vec2 pos) {
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


// void Monster::draw(){ }

// glm::vec2 Monster::getPosition() {
// 	return getPosition();
// }


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