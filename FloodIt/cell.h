#ifndef _CELL_
#define _CELL_

#include <iostream>
#include <vector>

class Board;

class Cell {

	int x,y;
	Board *board;
	std::vector< Cell* > neighbours;
	int numNeighbours;
	char colour;
public:
	int currentNeighbour;	
	void setNeighbour(Cell *);
	void notifyNeighbours(char oldColour, char newColour);
	void notify(char oldColour, char newColour, Cell* cell);
	Cell(int x, int y, Board *board);
	char getColour();
	void switchColour(char newColour, Cell* cell);
	int getX();
	int getY();
	bool notified;
};

#endif
