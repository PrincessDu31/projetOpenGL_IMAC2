#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Aleatoirus.hpp"
#include "Monster.hpp"
#include "MainCaracter.hpp"


class Interface {
private: 
	glm::mat3 map;
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
	void readMonsterAndAleatoirusInfos (std::ifstream &file);
	void addMonstre(std::string line);
	void addAleatoirus(std::string line);

	void collision();
	void showCursor ();

	//getters
	glm::mat3 getMap ();
	unsigned int getNbPink();
	unsigned int getNbBlue();
	std::vector<Aleatoirus> getListAleatoirus ();
	std::vector<Monster> getListMonsters ();
	MainCaracter getPlayer ();

	// setters
	void setMap (glm::mat3 m);
	void setNbPink(unsigned int p);
	void setNbBlue(unsigned int b);
	void setListAleatoirus (std::vector<Aleatoirus> list);
	void setListMonsters (std::vector<Monster> list);
	void setPlayer (MainCaracter m);

};

