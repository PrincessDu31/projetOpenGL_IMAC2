#ifndef ALEATOIRUS_HPP
#include "glimac/glm.hpp"

class Aleatoirus {
private: 
	enum Type {a1, a2, a3 }; 
	glm::vec2 position;

public: 
	void doAction (MainCaracter m);

};

#endif