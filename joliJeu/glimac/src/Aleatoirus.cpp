#include <glimac/Aleatoirus.hpp>

#define MAX_BONUS 1000
#define MAX_MALUS 750
#define VAL_WEAPON_UPGRADE 20
#define VAL_WEAPON_DOWNGRADE 15

Aleatoirus::Aleatoirus(){}
Aleatoirus::~Aleatoirus(){}

void Aleatoirus::doAction (MainCaracter m) {
	switch(typeAlea){
		case BONUS:
		{
			float lifeAddition = (rand() % MAX_BONUS) / MAX_BONUS;
			m.setLife(lifeAddition + m.getLife());
			break;
		}
		case MALUS:
		{
			float lifeDiminution = (rand() % MAX_MALUS) / MAX_MALUS;
			m.setLife(m.getLife() - lifeDiminution);
			break;
		}
		case WEAPON_UPGRADE:
		{
			int attackUpgrade = rand() % VAL_WEAPON_UPGRADE;
			int defenseUpgrade = rand() % VAL_WEAPON_UPGRADE;
			m.setAttack(attackUpgrade + m.getAttack());
			m.setDefense(defenseUpgrade + m.getDefense());
			break;
		}
		case WEAPON_DOWNGRADE:
		{
			int attackDowngrade = rand() % VAL_WEAPON_DOWNGRADE;
			int defenseDowngrade = rand() % VAL_WEAPON_DOWNGRADE;
			m.setAttack(attackDowngrade + m.getAttack());
			m.setDefense(defenseDowngrade + m.getDefense());
			break;
		}
		default :
			break;
	}
}

void Aleatoirus::setPosition(glm::vec2 p){ position = p; }

void Aleatoirus::setType(std::string t){ 
	if (t == "BONUS") {
		typeAlea = BONUS;
	} else if ( t == "MALUS") {
		typeAlea = MALUS;
	} else if ( t == "WEAPON_UPGRADE" ){
		typeAlea = WEAPON_UPGRADE;
	} else if ( t == "WEAPON_DOWNGRADE") {
		typeAlea = WEAPON_DOWNGRADE;
	} else {
		typeAlea = NO_FUNCTION;
	}
}	


void Aleatoirus::draw(){ }

glm::vec2 Aleatoirus::getPosition() {
	return position;
}

std::string Aleatoirus::fromEnumToString() {
	switch (typeAlea){
		case BONUS:
			return "BONUS";
			break;
		case MALUS:
			return "MALUS";
			break;
		case WEAPON_UPGRADE:
			return "WEAPON_UPGRADE";
			break;
		case WEAPON_DOWNGRADE :
			return "WEAPON_DOWNGRADE";
			break;
		default:
			return "NO_FUNCTION";
			break;
	}

}