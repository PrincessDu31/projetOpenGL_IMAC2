#include <glimac/MainCaracter.hpp>

MainCaracter::MainCaracter() {
//	speed = 1.5;
	setAttack(3);
	setDefense(2);
	setPosition(glm::vec2(0,0));
	setLife(1);
	setOrientation (glm::vec3(0,0, 1));
}
MainCaracter::~MainCaracter(){}

void MainCaracter::changeWeapon (Weapon) { }
void MainCaracter::attack () { }
void MainCaracter::camera () { }
void MainCaracter::setOrientationCamera(glm::vec3 o){

	 if (o.x == 1){
        setOrientation(glm::vec3(1, 0, 0));
    } else if (o.z == 1){
    	setOrientation(glm::vec3(0, 0, 1));
    } else if (o.z == 0) {
    	setOrientation(glm::vec3(-1, 0, 0));
    } else {
    	setOrientation(glm::vec3(0, 0, -1));
    }
}               