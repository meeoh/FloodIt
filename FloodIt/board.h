#ifndef _BOARD_
#define _BOARD_

#include "vector"
//#include "cell.h"

class Board {

	vector< vector < Cell* > > board;

public:
	Board(int sizeX, int sizeY);

};



#endif