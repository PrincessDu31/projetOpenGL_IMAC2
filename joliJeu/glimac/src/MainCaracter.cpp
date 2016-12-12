#include <glimac/MainCaracter.hpp>

MainCaracter::MainCaracter() {
//	speed = 1.5;
	setAttack(3);
	setDefense(2);
	setPosition(glm::vec2(0,0));
	setLife(1);
	setOrientation (glm::vec2(0,1));
}
MainCaracter::~MainCaracter(){}

void MainCaracter::changeWeapon (Weapon) { }
void MainCaracter::attack () { }
void MainCaracter::camera () { }