#ifndef _CELL_
#define _CELL_

#include <iostream>

class Cell {

	int numNeighbours;
	Cell* neighbours[4];
	int x,y;
	char colour;

public:
	void notify();
	Cell(int x, int y);
	std::string getColour();
};

#endif