#include <vector>
#include <iostream>
#include <fstream>
#include <glimac/Map.hpp>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;



Pixel::Pixel(){}
Pixel::Pixel( char red,  char green,  char blue){
	r = red;
	g = green;
	b = blue;
}
Pixel::~Pixel(){}
unsigned char Pixel::getR () { return r; }
unsigned char Pixel::getG () { return g; }
unsigned char Pixel::getB () { return b; }

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
	int i;
	for (i = 0; i < width*height; i++)
		mapTrouve.push_back(false);
}
Map::~Map(){}
	
Pixel Map::getValueMap ( int row,  int col) { return tabMap[row*(width-1) + col]; }



MapType Map::getType(int row,  int col) { 
	if (row < width && col < height)
		return mapElements[row*(width - 1) + col]; 
	return OTHER;
}




Pixel Map::getValueMap (int numVal) { return tabMap[numVal]; }

void Map::addValueTab (Pixel p) { tabMap.push_back(p); }

void Map::printElement (int numElement) {
	if (mapElements[numElement] == SOL) { cout << "."; }
	else if (mapElements[numElement] == MONTAGNE) { cout << "^"; }
	else if (mapElements[numElement] == OTHER) { cout << "_"; }
}
void Map::printElement (int row, int col) {
	printElement(width*row + col);
}

void Map::setWidth( int w) {	width = w; }
void Map::setHeight( int h) { height = h; }


int Map::getWidth () { return width; }
int Map::getHeight () { return height; }




void Map::loadMapFromPPM (std::string mapFile) {


	
	string line;
	ifstream file (mapFile);

	if (file.fail())
	{
		cout << "Erreur dans l'image\n";
		file.clear( );
	}


	getline(file, line);
	getline(file, line);
   
   	// while (line[0] == '#')
   	// 	getline(file, line);

		// char tmpChar;

		// file.get(tmpChar);
		// file.get(tmpChar);
		// file.get(tmpChar);

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


		// while (valMaxTmp != ASCII_NEW_LINE){
		// 	valMax = valMax*10 + (valMaxTmp - ZERO);
		// 	file.get(valMaxTmp);
		// }	

		setWidth(width + 1);
		setHeight(height + 1);
			
		unsigned char rUnsigned;
		unsigned char gUnsigned;
		unsigned char bUnsigned;
		
		Pixel tmp;
		unsigned char r,g,b;
		char tmpChar = ZERO;
int i = 0;
		while (!file.eof()) {
			r = 0;
			g = 0;
			b = 0;

			while (file.get(tmpChar) && tmpChar != ASCII_NEW_LINE) {
				r = r*10 + (tmpChar - ZERO);
			}
			i++;
					// getline(file,r);
			// rUnsigned = (int) r;

			while (file.get(tmpChar) && tmpChar != ASCII_NEW_LINE && !file.eof()) {
				g = g*10 + (tmpChar - ZERO);

			}
			
			// getline(file, g);
			// gUnsigned = (int) g;

			while (file.get(tmpChar) && tmpChar != ASCII_NEW_LINE && !file.eof()) {
				b = b*10 + (tmpChar - ZERO);

			}
							

			// getline(file, b);
			// bUnsigned = (int)b;

			addValueTab((Pixel(r,g,b)));
			addElementMap(Pixel(r,g,b).moyennePixels());
			mapTrouve.push_back(false);
		}

		file.close();
	}




// void Map::loadMapFromPPM (std::string mapFile) {


// 	ifstream file (mapFile);
	
// 	if(file == NULL){
// 		printf("Erreur dans l'image\n");
// 	}
// 	else{

// 		char tmpChar;

// 		file.get(tmpChar);
// 		file.get(tmpChar);
// 		file.get(tmpChar);

// 		int width = 0, height = 0, valMax = 0;
// 		char widthTmp = ZERO, heightTmp = ZERO, valMaxTmp = ZERO;


// 		while (widthTmp != ASCII_SPACE){
// 			width = width*10 + (widthTmp - ZERO);
// 			file.get(widthTmp);
// 			cout << widthTmp << endl;
// 		}

// 		while (heightTmp != ASCII_NEW_LINE){
// 			height = height*10 + (heightTmp - ZERO);
// 			file.get(heightTmp);
// 		}

// 		while (valMaxTmp != ASCII_NEW_LINE){
// 			valMax = valMax*10 + (valMaxTmp - ZERO);
// 			file.get(valMaxTmp);
// 		}	

// 		setWidth(width);
// 		setWidth(height);
			
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


void Map::addElementMap (unsigned char val) {
	if (val > VAL_SOL - MARGE_ERREUR && val < VAL_SOL + MARGE_ERREUR) {
		mapElements.push_back(SOL);
	} else if (val > VAL_MONTAGNE - MARGE_ERREUR && val < VAL_MONTAGNE + MARGE_ERREUR) {
		mapElements.push_back(MONTAGNE);

	} else {
		mapElements.push_back(OTHER);
	}
}

string Map::fromEnumToString(MapType t) {
	if (t == SOL) return "SOL";
	else if (t == MONTAGNE) return "MONTAGNE";
	return "OTHER";

}

void Map::testMapLoading () {


	int i, j;
	cout << "begining";

	for (i = 0; i < width; i++) {
		cout << endl;
		for (j = 0; j < height; j++) {
			printElement (i,j);
		}

	}

	cout << endl; 
	cout << "width : " << width << endl;
	cout << "height : " << height << endl;
	
	int rowToTest = 0, colToTest = 0;
	Pixel val = getValueMap(rowToTest,colToTest);
	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	val.printPixel();
	cout << "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	printElement (rowToTest,colToTest);
	cout << endl;


	rowToTest = 0; colToTest = 1;
	val = getValueMap(rowToTest,colToTest);
	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	val.printPixel();
	cout << "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	printElement (rowToTest,colToTest);
	cout << endl;

	rowToTest = 0; colToTest = 3;
	val = getValueMap(rowToTest,colToTest);
	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	val.printPixel();
	cout << "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	printElement (rowToTest,colToTest);
	cout << endl;

	rowToTest = 0; colToTest = 30;
	val = getValueMap(rowToTest,colToTest);
	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	val.printPixel();
	cout << "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	printElement (rowToTest,colToTest);
	cout << endl;

	// rowToTest = 0; 
	// colToTest = 29;
	// val = getValueMap(rowToTest,colToTest);
	// cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	// val.printPixel();
	// cout << "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	// printElement (rowToTest,colToTest);
	// cout << endl;


	// rowToTest = 1; colToTest = 0;
	// val = getValueMap(rowToTest,colToTest);
	// cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	// val.printPixel();
	// cout << "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	// printElement (rowToTest,colToTest);
	// cout << endl;

	// rowToTest = 1;
	// colToTest = 29;
	// val = getValueMap(rowToTest,colToTest);
	// cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	// val.printPixel();
	// cout <<  "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	// printElement (rowToTest,colToTest);
	// cout << endl;

	rowToTest = 1;
	colToTest = 1;
	val = getValueMap(rowToTest,colToTest);
	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	val.printPixel();
	cout <<  "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	printElement (rowToTest,colToTest);
	cout << endl;

	rowToTest = 29;
	colToTest = 29;
	val = getValueMap(rowToTest,colToTest);
	cout << "pixel row " << rowToTest << " col " << colToTest << " : ";
	val.printPixel();
	cout <<  "moyenne des pixels : " << (int) val.moyennePixels() << endl;
	printElement (rowToTest,colToTest);
	cout << endl;


}

