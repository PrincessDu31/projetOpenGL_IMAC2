#include "Interface.hpp"
#include <vector>
#include <fstream>


using namespace std;


Interface::Interface(){}
Interface::~Interface(){}

void Interface::createWorld (){
	string line;
	ifstream myfile("./config.txt");
	int count = 0;
	if (myfile.is_open()) {
   		//while (!myfile.eof()){
   			if (line == '#'){
   				getLine(myfile, line);
   				count ++;
   			}
   			if (count == 2){
   				// readMap(line);
   				readMap("../map/test3.ppm");
   				getLine(myfile, line);
   				count ++;
   			} else {
   				readMonsterAndAleatoirusInfos(& myfile);
   			}
   		//} 
   		myfile.close();
	}
}

void Interface::readMap (std::string mapFile) {
	Map = loadMapFromPPM(mapFile)
}

void Interface::readMonsterAndAleatoirusInfos (ifstream file) {
	cout << "monstre" << endl;
}

void Interface::collision() {
}

void Interface::showCursor () {

}


// getters
Map Interface::getMap () {return map;}
unsigned int Interface::getNbPink() {return nbPink;}
unsigned int Interface::getNbBlue() {return nbBlue;}
std::vector<Aleatoirus> Interface::getListAleatoirus () {return listAleatoirus;}
std::vector<Monster> Interface::getListMonsters () {return listMonsters;}
MainCaracter Interface::getPlayer () {return player;}


// setters
void Interface::setMap (Map m) { map = m; }
void Interface::setNbPink(unsigned int p){ nbPink = p; }	
void Interface::setNbBlue(unsigned int b) { nbBlue = b; }
void Interface::setListAleatoirus (std::vector<Aleatoirus> list) { listAleatoirus = list; }
void Interface::setListMonsters (std::vector<Monster> list) { listMonsters = list; }
void Interface::setPlayer (MainCaracter m) { player = m; }

