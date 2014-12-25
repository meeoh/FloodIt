#ifndef _CELL_
#define _CELL_

#include <iostream>
#include <vector>

class Board;

class Cell {

	int numNeighbours;
	std::vector< Cell* > neighbours;
	int x,y;
	char colour;
	Board *board;
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