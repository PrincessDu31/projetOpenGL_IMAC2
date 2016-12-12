#define SOL 0
#define MONTAGNE 255
#define MARGE_ERREUR 127
#define ZERO 48
#define ASCII_SPACE 32
#define ASCII_NEW_LINE 10

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;



class Pixel {
friend class Map;
private:
	unsigned char r;
	unsigned char g;
	unsigned char b;

public:
	Pixel(){}
	Pixel( char red,  char green,  char blue){
		r = red;
		g = green;
		b = blue;
	}
	~Pixel(){}
	unsigned char getR () { return r;}
	unsigned char getG () { return g;}
	unsigned char getB () { return b;}

	void printPixel () {
		cout << (int)r << " " << (int)g << " " << (int)b << endl;
	}
	int moyennePixels () {
		int moy = (int)r + (int)g + (int)b;
		return moy / 3;
	}
};


class Map {
private:
	vector <Pixel> tabMap;
	int width;
	int height;
	vector <unsigned short> mapElements;
	
public:
	Map(){}
	Map(int w, int h){
		width = w;
		height = h;
	}
	~Map(){}
		
	Pixel getValueMap ( int row,  int col) { return tabMap[(row-1)*width + col]; }
	Pixel getValueMap (int numVal) { return tabMap[numVal]; }

	void addValueTab (Pixel p) { tabMap.push_back(p); }
	void addElementMap (unsigned char val);

	void printElement (int numElement) {
		if (mapElements[numElement] == SOL) { cout << "_"; }
		else if (mapElements[numElement] == MONTAGNE) { cout << "^"; }
		else { cout << " "; }
	}
	void printElement (int row, int col) {
		printElement(width*(row-1) + col);
	}

	void setWidth( int w) {	width = w; }
	void setHeight( int h) { height = h; }


	int getWidth () { return width; }
	int getHeight () { return height; }

	Map loadMapFromPPM();
	void testMapLoading (Map m);

};


Map Map::loadMapFromPPM () {

	Map map;

	ifstream file ("map/test3.ppm");
	
	if(file == NULL){
		printf("Erreur dans l'image\n");
	}
	else{

		char poubelle;

		file.get(poubelle);
		file.get(poubelle);
		file.get(poubelle);

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

		map.setWidth(width);
		map.setWidth(height);
			
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

			map.addValueTab((Pixel(rUnsigned,gUnsigned,bUnsigned)));
			map.addElementMap(Pixel(rUnsigned,gUnsigned,bUnsigned).moyennePixels());
		}

		file.close();
	}

	return map;
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



int main () {
	Map m = m.loadMapFromPPM();
	m.testMapLoading(m);
	return 0;
}


