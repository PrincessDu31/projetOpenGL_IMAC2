#include <glimac/Interface.hpp>
#include <glimac/Monster.hpp>
#include <glimac/Weapon.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;


#define  DETECTION 7
#define CLOSE_ENOUGH 2
#define TOO_FAR 15


Interface::Interface(){}
Interface::~Interface(){}

void Interface::createWorld (){

	string line;
	ifstream myfile("../../joliJeu/config.txt");
	myfile.is_open();
	if (myfile.fail())
	{
		cout << " Error!";
		myfile.clear( );
	} else {

		while (!myfile.eof()) {
			getline(myfile, line);
	   		while (line[0] == '#'){
	   			getline(myfile, line);
	   		}
	   		readMap(line);
	   		readMonsterAndAleatoirusInfos(myfile);

	   	myfile.close();
		}
	}
}

void Interface::readMap (string mapFile) {
	cout << mapFile << endl;
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
		addMonster(line);
		cout << "monstre "<< i << ": " << line << endl;
	}
} 

void Interface::addMonster(std::string line){
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
	monster.setPosition(glm::vec2(positionX,positionY));
	monster.setType(elems.at(3));
	Weapon myweapon = Weapon(id_weapon);
	monster.setWeapon(myweapon);
	monster.setAttack(attack);
	monster.setDefense(defense);
	monster.setLife(life);
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

	long int positionX = strtol (elems.at(1).c_str(),NULL,10);
	long int positionY = strtol (elems.at(2).c_str(),NULL,10);
	alea.setPosition(glm::vec2(positionX, positionY));
	alea.setType(elems.at(3));

	listAleatoirus.push_back(alea);
}


void Interface::collision() {
	//ALEATOIRUS
	int i = 0;

	for (i=0; i< listAleatoirus.size(); i++){
		if (abs(player.getPosition().x + 20 - listAleatoirus.at(i).getPosition().x) < 1){
			if (abs(player.getPosition().y + 20 - listAleatoirus.at(i).getPosition().y) < 1){
				//cout << "COLLISION ALEATOIRUS ETAT" << listAleatoirus.at(i).fromEnumToStringState() << endl;
				if (listAleatoirus.at(i).getState() == ON){
					listAleatoirus.at(i).doAction(player);
					listAleatoirus.at(i).setState(OFF);
				}
			}
		}
	}


	for (i=0; i< listMonsters.size(); i++){
		if (abs(player.getPosition().x + 20 - listMonsters.at(i).getPosition().x) < DETECTION){
			if (abs(player.getPosition().y + 20 - listMonsters.at(i).getPosition().y) < DETECTION){
				//cout << "MONSTRE ETAT" << listMonsters.at(i).fromEnumToStringDetection() << endl;
				listMonsters.at(i).setDetection(ACTIVE);
				cout << "position " << listMonsters.at(i).getPosition().x << " , " << listMonsters.at(i).getPosition().y << endl;

			}
		}
	}

}

bool Interface::collisionMountains(float step){
	
	int i = floor(player.getPosition().x + step*player.getOrientation().x + 20);
	int j = floor(player.getPosition().y + step*player.getOrientation().y + 20);
	if (getMap().getType(i, j) == MONTAGNE){

		cout << "MONTAGNE, i:" << i << " j: " << j << endl;
		return true;
	}
	
	return false;
}

bool Interface::collisionBorder(float step){
	
	int i = floor(player.getPosition().x + step*player.getOrientation().x + 20);
	int j = floor(player.getPosition().y + step*player.getOrientation().y + 20);
	if ((i < 0) || (i > getMap().getHeight()-1) || (j < 0) || (j > getMap().getHeight()-1) ){
		cout << "COLLISION BORDURE" << endl;
		return true;
	}	
	return false;
}


bool Interface::collisionMonster(int numMonster) {
	
	if (abs(player.getPosition().x + 15 - listMonsters.at(numMonster).getPosition().x) < 3){
		if (abs(player.getPosition().y +15 - listMonsters.at(numMonster).getPosition().y) < 3){
			return true;
		}
	}
	return false;
}



void Interface::showCursor () {

}


// getters
Map Interface::getMap () {return map;}
unsigned int Interface::getNbPink() {return nbPink;}
unsigned int Interface::getNbBlue() {return nbBlue;}
std::vector<Aleatoirus> * Interface::getListAleatoirus () {return &listAleatoirus;}
std::vector<Monster> * Interface::getListMonsters () {return &listMonsters;}
MainCaracter Interface::getPlayer () {return player;}


// setters
void Interface::setMap (Map m) { map = m; }
void Interface::setNbPink(unsigned int p){ nbPink = p; }	
void Interface::setNbBlue(unsigned int b) { nbBlue = b; }
void Interface::setListAleatoirus (std::vector<Aleatoirus> list) { listAleatoirus = list; }
void Interface::setListMonsters (std::vector<Monster> list) { listMonsters = list; }
void Interface::setPlayer (MainCaracter m) { player = m; }



void Interface::updateMonster(int i, glm::vec3 position){
	cout << "Player X: " << player.getPosition().x + 20 << endl;
	cout << "Player Y: " << player.getPosition().y + 20 << endl;
	cout << "Monstre X: " << listMonsters.at(i).getPosition().x << endl;
	cout << "Monstre Y: " << listMonsters.at(i).getPosition().y << endl;
	if ((abs(player.getPosition().x + 20 - listMonsters.at(i).getPosition().x) > CLOSE_ENOUGH) ||
	 (abs(player.getPosition().y + 20 - listMonsters.at(i).getPosition().y) > CLOSE_ENOUGH)) {
	 		cout << "UPDATE" << endl;
			listMonsters.at(i).updatePosition(position);
	}
	if ((abs(player.getPosition().x + 20 - listMonsters.at(i).getPosition().x) > TOO_FAR) ||
	 (abs(player.getPosition().y + 20 - listMonsters.at(i).getPosition().y) > TOO_FAR)) {
			listMonsters.at(i).setDetection(DISACTIVE);
			cout << "TOO FAR" << endl;
	}
}

