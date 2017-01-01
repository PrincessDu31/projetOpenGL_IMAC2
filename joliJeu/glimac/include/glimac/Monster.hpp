#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <glimac/Character.hpp>
#include <glimac/MainCaracter.hpp>
#include <string>

enum Detection {ACTIVE, DISACTIVE}; 

class Monster : public Character {
	enum Type {M1, M2, M3 }; 

private: 
	Type monsterType;
	Detection detection;
	float distanceToPlayer;
	
public: 
	Monster();
	Monster(glm::vec2 pos);
	~Monster();
	void setType(std::string t);
	void setDetection(Detection d);
	void setDistanceToPlayer(float d);
	Detection getDetection();
	float getDistanceToPlayer();

	void updatePosition(glm::vec3 v);

	// void doAction (MainCaracter m);
	// void setPosition(glm::vec2 p);
	// void draw();
	// glm::vec2 getPosition();
	std::string fromEnumToString();
	std::string fromEnumToStringDetection();

	// void attack1(MainCaracter m);
	// void attack2(MainCaracter m);
	// void attack3(MainCaracter m);

};



#endif