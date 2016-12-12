#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "glimac/glm.hpp"
#include "MainCaracter.hpp"
#include "Monster.hpp"
#include "Aleatoirus.hpp"
#include "Map.hpp"
#include <vector>
#include <string>


class Interface {
public: 
	Interface();
	~Interface();

private: 

	Map map;
	unsigned int nbPink;
	unsigned int nbBlue;
	std::vector<Aleatoirus> listAleatoirus;
	MainCaracter player;
	std::vector<Monster> listMonsters;

public: 
	
	void createWorld ();
	void readMap (std::string mapFile);
	void readMonsterAndAleatoirusInfos (ifstream file);
	void collision();
	void showCursor ();

	// getters
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

#endif 