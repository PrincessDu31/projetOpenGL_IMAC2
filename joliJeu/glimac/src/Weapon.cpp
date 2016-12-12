#include <glimac/Weapon.hpp>
#include  <cstdlib>

Weapon::Weapon(int arme) {
	switch (arme)
	{
		case 2 : 
			typeWeapon = w2;
			power = 3;
			break;
		case 3 : 
			typeWeapon = w3;
			power = 6;
			break;
		default:
			typeWeapon = w1;
			power = 1;
			break;
	}
}

Weapon::Weapon() {
	int arme = rand() % NB_ARMES;
	switch (arme)
	{
		case 2 : 
			typeWeapon = w2;
			power = 3;
			break;
		case 3 : 
			typeWeapon = w3;
			power = 6;
			break;
		default:
			typeWeapon = w1;
			power = 1;
			break;
	}
}


Weapon::~Weapon() {}