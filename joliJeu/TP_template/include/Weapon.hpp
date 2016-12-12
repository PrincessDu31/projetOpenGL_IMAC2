#pragma once

#define NB_ARMES 3

class Weapon {
private: 
	int power;
	enum Type {w1, w2, w3 }; 

public: 
	Weapon();
	Weapon(int arme);
	~Weapon();

};

