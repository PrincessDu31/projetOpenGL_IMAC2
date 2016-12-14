#ifndef ALEATOIRUS_HPP
#define ALEATOIRUS_HPP

#include "glimac/glm.hpp"
#include <glimac/MainCaracter.hpp>
#include <string>

class Aleatoirus {
	enum Type {BONUS, MALUS, WEAPON_UPGRADE, WEAPON_DOWNGRADE }; 

private: 
	glm::vec2 position;
	Type typeAlea;

public: 
	Aleatoirus();
	~Aleatoirus();
	void doAction (MainCaracter m);
	void setPosition(glm::vec2 p);
	void setType(std::string t);
	void draw();
	glm::vec2 getPosition();

};

#endif