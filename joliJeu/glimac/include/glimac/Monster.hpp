#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <glimac/Character.hpp>
#include <glimac/MainCaracter.hpp>
#include <string>

enum Detection {ACTIVE, DISACTIVE}; 

enum LifeStatus {ALIVE, UNDER_ATTACK, DEAD};

class Monster : public Character {
	enum Type {M1, M2, M3 }; 

private: 
	Type monsterType;
	Detection detection;
	LifeStatus lifeStatus;
	float distanceToPlayer;
	
public: 
	Monster();
	Monster(glm::vec2 pos);
	~Monster();
	void setType(std::string t);
	void setDetection(Detection d);
	void setLifeSatus(LifeStatus s);
	void setDistanceToPlayer(float d);
	Detection getDetection();
	LifeStatus getLifeStatus();
	float getDistanceToPlayer();

	void updatePosition(glm::vec3 v);

	// void doAction (MainCaracter m);
	// void setPosition(glm::vec2 p);
	// void draw();
	// glm::vec2 getPosition();
	std::string fromEnumToString();
	std::string fromEnumToStringDetection();
	std::string fromEnumToStringLifeStatus();

	void attacked(int attack);
	// void attack1(MainCaracter m);
	// void attack2(MainCaracter m);
	// void attack3(MainCaracter m);

};



#endif