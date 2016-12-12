#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>

#include <glimac/Interface.hpp>

// //#include "glimac/glm.hpp"
// #include "include/MainCaracter.hpp"
// #include "include/Monster.hpp"
// #include "include/Aleatoirus.hpp"
// // #include "include/Map.hpp"
// #include <vector>
// #include <string>



// #define SOL 0
// #define MONTAGNE 255
// #define MARGE_ERREUR 127
// #define ZERO 48
// #define ASCII_SPACE 32
// #define ASCII_NEW_LINE 10


// #include <fstream>


using namespace glimac;
using namespace std;
// using namespace jeu;

// class Map;

// class Pixel {
// friend class Map;
// private:
// 	unsigned char r;
// 	unsigned char g;
// 	unsigned char b;

// public:

// 	Pixel(){}
// 	Pixel( char red,  char green,  char blue){
// 		r = red;
// 		g = green;
// 		b = blue;
// 	}
// 	~Pixel(){}
// 	unsigned char getR () { return r;}
// 	unsigned char getG () { return g;}
// 	unsigned char getB () { return b;}

// 	void printPixel () {
// 		cout << (int)r << " " << (int)g << " " << (int)b << endl;
// 	}
// 	int moyennePixels () {
// 		int moy = (int)r + (int)g + (int)b;
// 		return moy / 3;
// 	}

// };



// class Map {
// private:
// 	vector <Pixel> tabMap;
// 	int width;
// 	int height;
// 	vector <unsigned short> mapElements;
	
// public:


// Map(){}
// Map(int w, int h){
// 	width = w;
// 	height = h;
// }
// ~Map(){}
	
// Pixel getValueMap ( int row,  int col) { return tabMap[(row-1)*width + col]; }
// Pixel getValueMap (int numVal) { return tabMap[numVal]; }

// void addValueTab (Pixel p) { tabMap.push_back(p); }

// void printElement (int numElement) {
// 	if (mapElements[numElement] == SOL) { cout << "_"; }
// 	else if (mapElements[numElement] == MONTAGNE) { cout << "^"; }
// 	else { cout << " "; }
// }
// void printElement (int row, int col) {
// 	printElement(width*(row-1) + col);
// }

// void setWidth( int w) {	width = w; }
// void setHeight( int h) { height = h; }


// int getWidth () { return width; }
// int getHeight () { return height; }




// void loadMapFromPPM (std::string mapFile) {


// 	ifstream file (mapFile);
	
// 	if(file == NULL){
// 		printf("Erreur dans l'image\n");
// 	}
// 	else{

// 		char charTmp;

// 		file.get(charTmp);
// 		file.get(charTmp);
// 		file.get(charTmp);

// 		int width = 0, height = 0, valMax = 0;
// 		char widthTmp = ZERO, heightTmp = ZERO, valMaxTmp = ZERO;


// 		while (widthTmp != ASCII_SPACE){
// 			width = width*10 + (widthTmp - ZERO);
// 			file.get(widthTmp);
// 		}

// 		while (heightTmp != ASCII_NEW_LINE){
// 			height = height*10 + (heightTmp - ZERO);
// 			file.get(heightTmp);
// 		}

// 		while (valMaxTmp != ASCII_NEW_LINE){
// 			valMax = valMax*10 + (valMaxTmp - ZERO);
// 			file.get(valMaxTmp);
// 		}	

// 		// mapElements.setWidth(width);
// 		// mapElements.setHeight(height);
			
// 		unsigned char rUnsigned;
// 		unsigned char gUnsigned;
// 		unsigned char bUnsigned;
		
// 		Pixel tmp;
// 		char r,g,b;

// 		while (!file.eof()) {
// 			file.get(r);
// 			rUnsigned = (int)r;

// 			file.get(g);
// 			gUnsigned = (int) g;

// 			file.get(b);
// 			bUnsigned = (int) b;

// 			addValueTab((Pixel(rUnsigned,gUnsigned,bUnsigned)));
// 			addElementMap(Pixel(rUnsigned,gUnsigned,bUnsigned).moyennePixels());
// 		}

// 		file.close();
// 	}

// }


// void addElementMap (unsigned char val) {
// 	if (val > SOL - MARGE_ERREUR && val < SOL + MARGE_ERREUR) {
// 		mapElements.push_back(SOL);
// 	} else if (val > MONTAGNE - MARGE_ERREUR && val < MONTAGNE + MARGE_ERREUR) {
// 		mapElements.push_back(MONTAGNE);

// 	} else {
// 		mapElements.push_back(3);
// 	}
// }


// void testMapLoading (Map m) {
// 	int w = m.getWidth();
// 	int h = m.getWidth();
// 	cout << "width : " << w << endl;
// 	cout << "height : " << h << endl;
	
// 	int rowToTest = 1, colToTest = 12;
// 	Pixel val = m.getValueMap(rowToTest,colToTest);
// 	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
// 	val.printPixel();
// 	cout << "moyenne des pixels : " << (int) val.moyennePixels() << endl;
// 	m.printElement (rowToTest,colToTest);
// 	cout << endl;

// 	rowToTest = 1;
// 	colToTest = 199;
// 	val = m.getValueMap(rowToTest,colToTest);
// 	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
// 	val.printPixel();
// 	cout <<  "moyenne des pixels : " << (int) val.moyennePixels() << endl;
// 	m.printElement (rowToTest,colToTest);
// 	cout << endl;


// 	int i, j;


// 	for (i = 1; i <= w; i++) {
// 		cout << endl;
// 		for (j = 1; j <= h; j++) {
// 			m.printElement (i,j);
// 		}

// 	}

// }
// };






// class Interface {


// private: 

// 	Map map;
// 	unsigned int nbPink;
// 	unsigned int nbBlue;
// 	std::vector<Aleatoirus> listAleatoirus;
// 	MainCaracter player;
// 	std::vector<Monster> listMonsters;

// public: 
	

// 	Interface(){};
// 	~Interface(){};

// 	void createWorld (){
// 		string line;
// 		ifstream myfile("./config.txt");
// 		int count = 0;
// 	//	if (myfile.is_open()) {
// 	   		//while (!myfile.eof()){
// 	   			// if (line == '#'){
// 	   			// 	getLine(myfile, line);
// 	   			// 	count ++;
// 	   			// }
// 	   			// if (count == 2){
// 	   			// 	// readMap(line);
// 	   				readMap("../map/test3.ppm");
// 	   			// 	getLine(myfile, line);
// 	   			// 	count ++;
// 	   			// } else {
// 	   			// 	readMonsterAndAleatoirusInfos(& myfile);
// 	   			// }
// 	   		//} 
// //myfile.close();
// 	//	}
// 	}

// 	void readMap (std::string mapFile) {
// 		Map m = loadMapFromPPM(mapFile)
// 	}


// };











int main(int argc, char** argv) {

	Interface interface;
	cout << "okiki" << endl;


	// Initialize SDL and open a window
	SDLWindowManager windowManager(800, 600, "GLImac");

	// Initialize glew for OpenGL3+ support
	GLenum glewInitError = glewInit();
	if(GLEW_OK != glewInitError) {
		std::cerr << glewGetErrorString(glewInitError) << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    // Application loop:
	bool done = false;
	while(!done) {
		// Event loop:
		SDL_Event e;
		while(windowManager.pollEvent(e)) {
			if(e.type == SDL_QUIT) {
				done = true; // Leave the loop after this iteration
			}
		}

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
