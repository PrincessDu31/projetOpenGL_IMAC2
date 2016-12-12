#ifndef MONSTER_HPP
#include "Caracter.hpp"

class Monster : public Caracter {
private: 
	enum Type {m1, m2, m3 }; 

public: 
	Monster();
	Monster(glm::vec2 pos);
	~Monster();

};

#endif