#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <glimac/Character.hpp>
#include <string>


class Monster : public Character {
	enum Type {m1, m2, m3 }; 

private: 
	Type monsterType;
	
public: 
	Monster();
	Monster(glm::vec2 pos);
	~Monster();
	void setType(std::string t);


};

#endif