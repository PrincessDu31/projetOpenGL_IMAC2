<<<<<<< HEAD:joliJeu/jeu/include/jeu/Aleatoirus.hpp
#ifndef ALEATOIRUS_HPP
#define ALEATOIRUS_HPP
=======
#pragma once
>>>>>>> 1512b7c381901b1d88539924358c4280d7133751:joliJeu/TP_template/include/Aleatoirus.hpp

#include "glimac/glm.hpp"
#include "MainCaracter.hpp"

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
