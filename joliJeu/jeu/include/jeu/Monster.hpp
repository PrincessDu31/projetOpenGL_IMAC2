<<<<<<< HEAD:joliJeu/jeu/include/jeu/Monster.hpp
#ifndef MONSTER_HPP
#define MONSTER_HPP
=======
#pragma once

#include "Caracter.hpp"
>>>>>>> 1512b7c381901b1d88539924358c4280d7133751:joliJeu/TP_template/include/Monster.hpp

#include "Character.hpp"

class Monster : public Character {
private: 
	enum Type {m1, m2, m3 }; 

public: 
	Monster();
	Monster(glm::vec2 pos);
	~Monster();
	void setType(Type t);

};

