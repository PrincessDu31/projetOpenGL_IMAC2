#ifndef CARACTER_HPP
#include "glimac/glm.hpp"
#include "Weapon.hpp"

class Caracter {
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
	void makeAttack (Caracter c);

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

#endif