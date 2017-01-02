#include <glimac/Character.hpp>


Character::Character() {}
Character::~Character() {}


void Character::move () {}
void Character::rotate (int direction) {}
void Character::makeAttack (Character c) {}

// getters
float Character::getSpeed () { return speed; }
int Character::getAttack() { return attack; }
int Character::getDefense() { return defense; }
glm::vec2 Character::getPosition(){ return position; }
Weapon Character::getWeapon(){ return weapon; }
double Character::getLife(){ return life; }
glm::vec3 Character::getOrientation(){ return orientation; }

// setters
void Character::setAttack(int a){ attack = a; }
void Character::setDefense(int d){ defense = d; }
void Character::setPosition (glm::vec2 p){ position = p; }
void Character::setWeapon (Weapon w){ weapon = w; }
void Character::setLife (double l){ life = l; }
void Character::setOrientation (glm::vec3 o){ orientation = o; }
void Character::setSpeed(float s) { speed = s;}