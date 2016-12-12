
#include "Monster.hpp"

Monster::Monster(vec2 pos) {
	speed = 1.5;
	attack = 3;
	defense = 2;
	position =  pos;
	life = 1;
	orientation (0,1);
}

Monster::~Monster() {

}

void Monster::setType(Type t){
	Type = t;
}