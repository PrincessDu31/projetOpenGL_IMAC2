#include "Caracter.hpp"


Caracter::Caracter() {}
Caracter::~Caracter() {}


void Caracter::move () {}
void Caracter::rotate (int direction) {}
void Caracter::makeAttack (Caracter c) {}

// getters
float Caracter::getSpeed () const { return speed; }
int Caracter::getAttack() { return attack; }
int Caracter::getDefense() { return defense; }
glm::vec2 Caracter::getPosition(){ return position; }
Weapon Caracter::getWeapon(){ return weapon; }
double Caracter::getLife(){ return life; }
glm::vec2 Caracter::getOrientation(){ return orientation; }

// setters
void Caracter::setAttack(int a){ attack = a; }
void Caracter::setDefense(int d){ defense = d; }
void Caracter::setPosition (glm::vec2 p){ position = p}
void Caracter::setWeapon (Weapon w){ weapon = w; }
void Caracter::setLife (double l){ life = l; }
void Caracter::setOrientation (glm::vec2 o){ orientation = o; }