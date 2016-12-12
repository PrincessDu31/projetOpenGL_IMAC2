#include "MainCaracter.hpp"

MainCaracter::MainCaracter() {
	speed = 1.5;
	attack = 3;
	defense = 2;
	position = (0,0);
	life = 1;
	orientation (0,1);
}

void MainCaracter::changeWeapon (Weapon) { }
void MainCaracter::attack () { }
void MainCaracter::camera () { }