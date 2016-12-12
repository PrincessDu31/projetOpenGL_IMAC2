#include <vector>
#include <iostream>
#include <fstream>
#include <glimac/Map.hpp>

using namespace std;



Pixel::Pixel(){}
Pixel::Pixel( char red,  char green,  char blue){
	r = red;
	g = green;
	b = blue;
}
Pixel::~Pixel(){}
unsigned char Pixel::getR () { return r;}
unsigned char Pixel::getG () { return g;}
unsigned char Pixel::getB () { return b;}

void Pixel::printPixel () {
	cout << (int)r << " " << (int)g << " " << (int)b << endl;
}
int Pixel::moyennePixels () {
	int moy = (int)r + (int)g + (int)b;
	return moy / 3;
}


Map::Map(){}
Map::Map(int w, int h){
	width = w;
	height = h;
}
Map::~Map(){}
	
Pixel Map::getValueMap ( int row,  int col) { return tabMap[(row-1)*width + col]; }
Pixel Map::getValueMap (int numVal) { return tabMap[numVal]; }

void Map::addValueTab (Pixel p) { tabMap.push_back(p); }

void Map::printElement (int numElement) {
	if (mapElements[numElement] == SOL) { cout << "_"; }
	else if (mapElements[numElement] == MONTAGNE) { cout << "^"; }
	else { cout << " "; }
}
void Map::printElement (int row, int col) {
	printElement(width*(row-1) + col);
}

void Map::setWidth( int w) {	width = w; }
void Map::setHeight( int h) { height = h; }


int Map::getWidth () { return width; }
int Map::getHeight () { return height; }




void Map::loadMapFromPPM (std::string mapFile) {


	ifstream file (mapFile);
	
	if(file == NULL){
		printf("Erreur dans l'image\n");
	}
	else{

		char tmpChar;

		file.get(tmpChar);
		file.get(tmpChar);
		file.get(tmpChar);

		int width = 0, height = 0, valMax = 0;
		char widthTmp = ZERO, heightTmp = ZERO, valMaxTmp = ZERO;


		while (widthTmp != ASCII_SPACE){
			width = width*10 + (widthTmp - ZERO);
			file.get(widthTmp);
		}

		while (heightTmp != ASCII_NEW_LINE){
			height = height*10 + (heightTmp - ZERO);
			file.get(heightTmp);
		}

		while (valMaxTmp != ASCII_NEW_LINE){
			valMax = valMax*10 + (valMaxTmp - ZERO);
			file.get(valMaxTmp);
		}	

		setWidth(width);
		setWidth(height);
			
		unsigned char rUnsigned;
		unsigned char gUnsigned;
		unsigned char bUnsigned;
		
		Pixel tmp;
		char r,g,b;

		while (!file.eof()) {
			file.get(r);
			rUnsigned = (int)r;

			file.get(g);
			gUnsigned = (int) g;

			file.get(b);
			bUnsigned = (int) b;

			addValueTab((Pixel(rUnsigned,gUnsigned,bUnsigned)));
			addElementMap(Pixel(rUnsigned,gUnsigned,bUnsigned).moyennePixels());
		}

		file.close();
	}

}


void Map::addElementMap (unsigned char val) {
	if (val > SOL - MARGE_ERREUR && val < SOL + MARGE_ERREUR) {
		mapElements.push_back(SOL);
	} else if (val > MONTAGNE - MARGE_ERREUR && val < MONTAGNE + MARGE_ERREUR) {
		mapElements.push_back(MONTAGNE);

	} else {
		mapElements.push_back(3);
	}
}


void Map::testMapLoading (Map m) {
	int w = m.getWidth();
	int h = m.getWidth();
	cout << "width : " << w << endl;
	cout << "height : " << h << endl;
	
	int rowToTest = 1, colToTest = 12;
	Pixel val = m.getValueMap(rowToTest,colToTest);
	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	val.printPixel();
	cout << "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	m.printElement (rowToTest,colToTest);
	cout << endl;

	rowToTest = 1;
	colToTest = 199;
	val = m.getValueMap(rowToTest,colToTest);
	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	val.printPixel();
	cout <<  "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	m.printElement (rowToTest,colToTest);
	cout << endl;


	int i, j;


	for (i = 1; i <= w; i++) {
		cout << endl;
		for (j = 1; j <= h; j++) {
			m.printElement (i,j);
		}

	}

}

