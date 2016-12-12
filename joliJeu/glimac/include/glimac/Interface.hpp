<<<<<<< HEAD:joliJeu/glimac/include/glimac/Interface.hpp
#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "glimac/glm.hpp"
#include "MainCaracter.hpp"
#include "Monster.hpp"
#include "Aleatoirus.hpp"
#include "Map.hpp"
=======
#pragma once

>>>>>>> 1512b7c381901b1d88539924358c4280d7133751:joliJeu/TP_template/include/Interface.hpp
#include <vector>
#include <string>
#include <fstream>
#include "Aleatoirus.hpp"
#include "Monster.hpp"
#include "MainCaracter.hpp"



class Interface {
public: 
	Interface();
	~Interface();

private: 
<<<<<<< HEAD:joliJeu/glimac/include/glimac/Interface.hpp

	Map map;
=======
	glm::mat3 map;
>>>>>>> 1512b7c381901b1d88539924358c4280d7133751:joliJeu/TP_template/include/Interface.hpp
	unsigned int nbPink;
	unsigned int nbBlue;
	std::vector<Aleatoirus> listAleatoirus;
	MainCaracter player;
	std::vector<Monster> listMonsters;

public: 
	
	void createWorld ();
<<<<<<< HEAD:joliJeu/glimac/include/glimac/Interface.hpp
	void readMap (std::string mapFile);
	void readMonsterAndAleatoirusInfos (ifstream file);
	void collision();
	void showCursor ();

	// getters
	Map getMap ();
=======
	void readMap (std::string Filename);
	void readMonsterAndAleatoirusInfos (std::ifstream &file);
	void addMonstre(std::string line);
	void addAleatoirus(std::string line);

	void collision();
	void showCursor ();

	//getters
	glm::mat3 getMap ();
>>>>>>> 1512b7c381901b1d88539924358c4280d7133751:joliJeu/TP_template/include/Interface.hpp
	unsigned int getNbPink();
	unsigned int getNbBlue();
	std::vector<Aleatoirus> getListAleatoirus ();
	std::vector<Monster> getListMonsters ();
	MainCaracter getPlayer ();

	// setters
<<<<<<< HEAD:joliJeu/glimac/include/glimac/Interface.hpp
	void setMap (Map m);
=======
	void setMap (glm::mat3 m);
>>>>>>> 1512b7c381901b1d88539924358c4280d7133751:joliJeu/TP_template/include/Interface.hpp
	void setNbPink(unsigned int p);
	void setNbBlue(unsigned int b);
	void setListAleatoirus (std::vector<Aleatoirus> list);
	void setListMonsters (std::vector<Monster> list);
	void setPlayer (MainCaracter m);

};

