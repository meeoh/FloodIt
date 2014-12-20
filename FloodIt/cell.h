#ifndef _CELL_
#define _CELL_

#include <iostream>
#include <vector>

class Cell {

	int numNeighbours;
	std::vector< Cell* > neighbours;
	int x,y;
	char colour;

public:
	void notifyNeighbours(char oldColour, char newColour);
	void notify(char oldColour, char newColour);
	Cell(int x, int y);
	char getColour();
	void switchColour(char newColour);
	int getX();
	int getY();
};

#endif