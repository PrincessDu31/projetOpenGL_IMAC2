#ifndef ALEATOIRUS_HPP
#define ALEATOIRUS_HPP

#include "glimac/glm.hpp"

class Aleatoirus {
private: 
	enum Type {a1, a2, a3 }; 
	glm::vec2 position;

public: 
	Aleatoirus();
	~Aleatoirus();
	void doAction (MainCaracter m);

};

#endif