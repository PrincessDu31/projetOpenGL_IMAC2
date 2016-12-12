#pragma once

#include "glimac/glm.hpp"
#include "MainCaracter.hpp"

class Aleatoirus {
private: 
	enum Type {a1, a2, a3 }; 
	glm::vec2 position;

public: 
	void doAction (MainCaracter m);

	void setPosition(glm::vec2 p);
	void setType(Type t);
};
