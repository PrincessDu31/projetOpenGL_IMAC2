#ifndef ALEATOIRUS_HPP
#define ALEATOIRUS_HPP

#include "glimac/glm.hpp"
#include <glimac/MainCaracter.hpp>

class Aleatoirus {
private: 
	enum Type {a1, a2, a3 }; 
	glm::vec2 position;

public: 
	Aleatoirus();
	~Aleatoirus();
	void doAction (MainCaracter m);
	void setPosition(glm::vec2 p);
	void setType(Type t);

};

#endif