<<<<<<< HEAD:joliJeu/jeu/include/jeu/Character.hpp
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
=======
#pragma once
>>>>>>> 1512b7c381901b1d88539924358c4280d7133751:joliJeu/TP_template/include/Caracter.hpp

#include "glimac/glm.hpp"
#include "Weapon.hpp"


class Character {
private: 
	const float speed;
	int attack;
	int defense;
	glm::vec2 position;
	Weapon weapon;
	double life;
	glm::vec2 orientation;

public: 

	void move ();
	void rotate (int direction);
	void makeAttack (Character c);

	// getters
	float getSpeed ();
	int getAttack();
	int getDefense();
	glm::vec2 getPosition();
	Weapon getWeapon();
	double getLife();
	glm::vec2 getOrientation();

	// setters
	void setAttack(int a);
	void setDefense(int d);
	void setPosition (glm::vec2 p);
	void setWeapon (Weapon w);
	void setLife (double l);
	void setOrientation (glm::vec2 o);

};
