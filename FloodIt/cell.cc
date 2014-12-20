#include "cell.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

//Cell constructor
Cell::Cell(int x, int y):x(x),y(y){

	//Generate random colour
	int colourChoice = (rand()%3) + 1;	
	//Assign colour
	switch (colourChoice){		
	case 1:		colour = 'R';	break;
	case 2:		colour = 'B';	break;
	case 3:		colour = 'G';	break;
	case 4:		colour = 'Y';	break;
	}
}

//getColour()
//Returns colour of the current cell
char Cell :: getColour(){
	return colour;
}

//notify()
//notifies all neighbours of the current cell
void Cell::notify(){
	//Loop through all neighbours, and call notify on each one
	for(int i = 0; i < numNeighbours; i++){
	neighbours[i]->notify();
	}
}