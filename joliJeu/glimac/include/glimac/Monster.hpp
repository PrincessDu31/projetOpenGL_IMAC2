#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <glimac/Character.hpp>

class Monster : public Character {
private: 
	enum Type {m1, m2, m3 }; 

public: 
	Monster();
	Monster(glm::vec2 pos);
	~Monster();

};

#endif