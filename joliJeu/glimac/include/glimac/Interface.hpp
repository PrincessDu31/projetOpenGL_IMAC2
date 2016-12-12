#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "glimac/glm.hpp"
#include <glimac/MainCaracter.hpp>
#include <glimac/Monster.hpp>
#include <glimac/Aleatoirus.hpp>
#include <glimac/Map.hpp>

#include <vector>
#include <string>
#include <fstream>


private: 

	Map map;
	unsigned int nbPink;
	unsigned int nbBlue;
	std::vector<Aleatoirus> listAleatoirus;
	MainCaracter player;
	std::vector<Monster> listMonsters;

public: 
	Interface();
	~Interface();

	void createWorld ();
	void readMap (std::string mapFile);


	// getters
	Map getMap ();
	void readMonsterAndAleatoirusInfos (std::ifstream &file);
	void addMonstre(std::string line);
	void addAleatoirus(std::string line);

	void collision();
	void showCursor ();

	//getters
	Map getMap ();
	unsigned int getNbPink();
	unsigned int getNbBlue();
	std::vector<Aleatoirus> getListAleatoirus ();
	std::vector<Monster> getListMonsters ();
	MainCaracter getPlayer ();

	// setters
	void setMap (Map m);
	void setNbPink(unsigned int p);
	void setNbBlue(unsigned int b);
	void setListAleatoirus (std::vector<Aleatoirus> list);
	void setListMonsters (std::vector<Monster> list);
	void setPlayer (MainCaracter m);

};

