<<<<<<< HEAD:joliJeu/jeu/include/jeu/Weapon.hpp
#ifndef WEAPON_HPP
#define WEAPON_HPP
=======
#pragma once
>>>>>>> 1512b7c381901b1d88539924358c4280d7133751:joliJeu/TP_template/include/Weapon.hpp

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

