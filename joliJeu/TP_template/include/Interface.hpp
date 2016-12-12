#ifndef INTERFACE_HPP
#include "glimac/glm.hpp"
#include "MainCaracter.hpp"
#include "Monster.hpp"
#include "Aleatoirus.hpp"
#include <vector>
#include <string>

class Interface {
private: 
	glm::mat map;
	unsigned int nbPink;
	unsigned int nbBlue;
	std::vector<Aleatoirus> listAleatoirus;
	MainCaracter player;
	std::vector<Monster> listMonsters;
public: 
	Interface();
	~Interface();
	void createWorld ();
	void readMap (std::string Filename);
	void readMonsterAndAleatoirusInfos (ifstream file);
	void collision();
	void showCursor ();

	// getters
	glm::mat getMap ();
	unsigned int getNbPink();
	unsigned int getNbBlue();
	std::vector<Aleatoirus> getListAleatoirus ();
	std::vector<Monster> getListMonsters ();
	MainCaracter getPlayer ();

	// setters
	void setMap (glm::mat m);
	void setNbPink(unsigned int p);
	void setNbBlue(unsigned int b);
	void setListAleatoirus (std::vector<Aleatoirus> list);
	void setListMonsters (std::vector<Monster> list);
	void setPlayer (MainCaracter m);

};

#endif 