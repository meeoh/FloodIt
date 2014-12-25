#ifndef _BOARD_
#define _BOARD_

#include "vector"
#include "cell.h"
#include <iostream>

class Board {

	std::vector< std::vector < Cell* > > board;
	int sizeX, sizeY;
	

public:
	Board(int sizeX, int sizeY);
	friend std::ostream& operator<<(std::ostream& out, const Board &b);
	Cell* getCell(int x, int y);
	virtual ~Board();
	int redCount, blueCount, yellowCount, greenCount;
	void addColour(char oldColour, char newColour);
	bool hasWon();
};



#endif