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
};



#endif