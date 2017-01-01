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

class Interface {

private: 

	Map map;
	unsigned int nbPink;
	unsigned int nbBlue;
	std::vector<Aleatoirus> listAleatoirus;
	std::vector<Monster> listMonsters;

public: 
	MainCaracter player;
	Interface();
	~Interface();

	void createWorld ();
	void readMap (std::string mapFile);


	void readMonsterAndAleatoirusInfos (std::ifstream &file);
	void addMonster(std::string line);
	void addAleatoirus(std::string line);

	void collision();
	bool collisionMountains(float step);
	bool collisionBorder(float step);
	bool collisionMonster(int numMonster);
	void showCursor ();


	// getters
	Map getMap ();
	unsigned int getNbPink();
	unsigned int getNbBlue();
	std::vector<Aleatoirus> *getListAleatoirus ();
	std::vector<Monster> *getListMonsters ();
	MainCaracter getPlayer ();

	// setters
	void setMap (Map m);
	void setNbPink(unsigned int p);
	void setNbBlue(unsigned int b);
	void setListAleatoirus (std::vector<Aleatoirus> list);
	void setListMonsters (std::vector<Monster> list);
	void setPlayer (MainCaracter m);

	void updateMonster(int i, glm::vec3 position);
};

#endif