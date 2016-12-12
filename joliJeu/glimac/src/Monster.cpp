
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

void Monster::setType(std::string t){	
	//TODO check type
	// monsterType = t;
}