#ifndef _CELL_
#define _CELL_

class Cell {

	int numNeighbours;
	Cell* neighbours[4];
	int x,y;

public:
	void notify();
	Cell();
};

#endif