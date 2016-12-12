#ifndef MAIN_CHARACTER_HPP
#define MAIN_CHARACTER_HPP

#include <glimac/Character.hpp>

class MainCaracter : public Character {
private: 
	

public: 
	MainCaracter();
	~MainCaracter();
	void changeWeapon (Weapon);
	void attack ();
	void camera ();

};

#endif