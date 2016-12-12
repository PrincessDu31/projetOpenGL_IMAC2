
#include <glimac/Monster.hpp>

Monster::Monster(glm::vec2 pos) {
//	speed = 1.5;
	setAttack(3);
	setDefense(2);
	setPosition(pos);
	setLife(1);
	setOrientation(glm::vec2(0,1));
}

Monster::~Monster() {

}

void Monster::setType(Type t){
	
	monsterType = t;

}