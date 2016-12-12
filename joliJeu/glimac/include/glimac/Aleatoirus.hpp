#ifndef ALEATOIRUS_HPP
#define ALEATOIRUS_HPP

#include "glimac/glm.hpp"
#include <glimac/MainCaracter.hpp>
#include <string>

class Aleatoirus {
	enum Type {a1, a2, a3 }; 

private: 
	glm::vec2 position;
	Type typeAlea;
public: 
	Aleatoirus();
	~Aleatoirus();
	void doAction (MainCaracter m);
	void setPosition(glm::vec2 p);
	void setType(std::string t);

};

#endif