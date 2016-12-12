#include <glimac/Interface.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;


Interface::Interface(){}
Interface::~Interface(){}

void Interface::createWorld (){
	string line;
	ifstream myfile("./config.txt");
	myfile.is_open();
	int count = 0;
	while (!myfile.eof()) {
		getline(myfile, line);
   		count ++;
   		if (line[0] == '#'){
   			getline(myfile, line);
   			count ++;
   		}
   		if (count == 1){
   			readMap(line);
   			getline(myfile, line);
   			count ++;
   		} else {
   			readMonsterAndAleatoirusInfos(myfile);
   		} 
   	myfile.close();
	}
}

void Interface::readMap (string mapFile) {
	map.loadMapFromPPM(mapFile);
}

void Interface::readMonsterAndAleatoirusInfos (ifstream &file) {
	string line;
	getline(file, line);
	int i = 0;
	long int numberAlea = strtol (line.c_str(),NULL,10);
	for (i=0; i < numberAlea ; i++){
		getline(file, line);
		addAleatoirus(line);
		cout << "Alea "<< i << ": " << line << endl;
	}
	getline(file, line);
	long int numberMonster = strtol (line.c_str(),NULL,10);
	for (i=0; i < numberMonster ; i++){
		getline(file, line);
		addMonstre(line);
		cout << "monstre "<< i << ": " << line << endl;
	}
}

void Interface::addMonstre(string line){
	std::vector<std::string> elems;
	std::stringstream line_stream;
	line_stream.str(line);
	std::string item;
	Monster monster;
	while (std::getline(line_stream, item, ':')) {
		elems.push_back(item);
	}

	long int positionX = strtol (elems.at(1).c_str(),NULL,10);
	long int positionY = strtol (elems.at(2).c_str(),NULL,10);
	long int id_weapon = strtol (elems.at(4).c_str(),NULL,10);
	long int attack = strtol (elems.at(5).c_str(),NULL,10);
	long int defense= strtol (elems.at(6).c_str(),NULL,10);
	long int life = strtod (elems.at(7).c_str(),NULL);

	monster.setPosition(glm::vec2(positionX,positionY)):
	monster.setType(elems.at(3));
	monster.setWeapon(Weapon myweapon(id_weapon));
	monster.setAttack(attack);
	monster.setDefense(defense);
	monster.setLife();
	listMonsters.push_back(monster);

	//id:X:Y:type:id_arme:attack:defense:lifespan:?
}

void Interface::addAleatoirus(string line){
	std::vector<std::string> elems;
	std::stringstream line_stream;
   	line_stream.str(line);
   	std::string item;
   	Aleatoirus alea;
   	while (std::getline(line_stream, item, ':')) {
       	elems.push_back(item);
   	}

	long int positionX = strtol (elems.at(1).c_str(),&ptr,10);
	long int positionY = strtol (elems.at(2).c_str(),&ptr,10);
	alea.setPosition(glm::vec2(positionX, positionY));
	alea.setType(elems.at(3));

	listAleatoirus.push_back(alea);
}

void Interface::collision() {

}

void Interface::showCursor () {

}


// getters
glm::mat Interface::getMap () {return map;}
unsigned int Interface::getNbPink() {return nbPink;}
unsigned int Interface::getNbBlue() {return nbBlue;}
std::vector<Aleatoirus> Interface::getListAleatoirus () {return listAleatoirus;}
std::vector<Monster> Interface::getListMonsters () {return listMonsters;}
MainCaracter Interface::getPlayer () {return player;}


// setters
void Interface::setMap (glm::mat m) { map = m; }
void Interface::setNbPink(unsigned int p){ nbPink = p; }	
void Interface::setNbBlue(unsigned int b) { nbBlue = b; }
void Interface::setListAleatoirus (std::vector<Aleatoirus> list) { listAleatoirus = list; }
void Interface::setListMonsters (std::vector<Monster> list) { listMonsters = list; }
void Interface::setPlayer (MainCaracter m) { player = m; }

