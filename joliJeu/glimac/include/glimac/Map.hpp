#ifndef MAP_HPP
#define MAP_HPP


#define VAL_SOL 255
#define VAL_MONTAGNE 0
#define MARGE_ERREUR 127
#define ZERO 48
#define ASCII_SPACE 32
#define ASCII_NEW_LINE 10

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


enum MapType {SOL, MONTAGNE, OTHER }; 


class Pixel {
friend class Map;
private:
	unsigned char r;
	unsigned char g;
	unsigned char b;

public:
	Pixel();
	Pixel( char red,  char green,  char blue);
	~Pixel();
	unsigned char getR ();
	unsigned char getG ();
	unsigned char getB ();

	void printPixel ();
	int moyennePixels ();
};



class Map {
private:
	vector <Pixel> tabMap;
	int width;
	int height;
	vector <MapType> mapElements;
	vector <bool> mapTrouve;
	
public:
	friend class Interface;
	Map();
	Map(int w, int h);
	~Map();
		
	Pixel getValueMap ( int row,  int col);
	Pixel getValueMap (int numVal);

	void addValueTab (Pixel p);
	void addElementMap (unsigned char val);

	void printElement (int numElement);
	void printElement (int row, int col);

	void setWidth(int w);
	void setHeight(int h);

	int getWidth ();
	int getHeight ();

	MapType getType(int row,  int col);

	void loadMapFromPPM (std::string mapFile);
	void testMapLoading ();

	string fromEnumToString(MapType t);

	 
};

#endif