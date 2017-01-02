#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "glimac/glm.hpp"
#include "Weapon.hpp"


class Character {
private: 
	float speed;
	int attack;
	int defense;
	glm::vec2 position;
	Weapon weapon;
	double life;
	glm::vec3 orientation;

public: 
	Character();
	~Character();
	
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
	glm::vec3 getOrientation();

	// setters
	void setAttack(int a);
	void setDefense(int d);
	void setPosition (glm::vec2 p);
	void setWeapon (Weapon w);
	void setLife (double l);
	void setOrientation (glm::vec3 o);
	void setSpeed(float s);

};

#endif