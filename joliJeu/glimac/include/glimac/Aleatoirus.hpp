#ifndef ALEATOIRUS_HPP
#define ALEATOIRUS_HPP

#include "glimac/glm.hpp"
#include <glimac/MainCaracter.hpp>
#include <string>

enum State {ON, OFF}; 

class Aleatoirus {
	enum Type {BONUS, MALUS, WEAPON_UPGRADE, WEAPON_DOWNGRADE, NO_FUNCTION }; 
	

private: 
	glm::vec2 position;
	Type typeAlea;
	State state;

public: 
	Aleatoirus();
	~Aleatoirus();
	void doAction (MainCaracter m);
	void setPosition(glm::vec2 p);
	void setType(std::string t);
	void setState(State t);
	void draw();
	glm::vec2 getPosition();
	State getState();
	std::string fromEnumToString();
	std::string fromEnumToStringState();

};

#endif