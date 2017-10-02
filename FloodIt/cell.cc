#include "cell.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "board.h"

using namespace std;

//Cell constructor
Cell::Cell(int x, int y, Board *board):x(x),y(y),board(board),neighbours(4,NULL),currentNeighbour(0){	
	notified = 0;
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

//setNeighbour (Cell *cell)
//Sets the neighbour of a cell to 'cell'
void Cell::setNeighbour(Cell *cell){			
	neighbours[currentNeighbour] = cell;
	currentNeighbour++;
}


//notify()
//Checks if we need to do another colour switch
void Cell::notify(char oldColour,char newColour, Cell *cell){	
	if (oldColour == colour){			
		this->switchColour(newColour,cell);		
	}	
}

//switchColour(char newColour)
//Switches colour of current cell to 'newColour'
void Cell::switchColour(char newColour, Cell *cell) {
	//oldColour is our current colour
	char oldColour = colour;	
	//if we're assigning our cell to its current colour
	//nothing happens
	if (oldColour == newColour){return; }
	colour = newColour;			
	//Add the colour to our total, so we can tell if a player has won
	board->addColour(oldColour,colour);

	//Loop through all neighbours, and call notify on each one
	for (int i = 0; i < 4; i++){
		//If the neighbour exists
		if (neighbours[i] && neighbours[i] != cell){			
				neighbours[i]->notify(oldColour, newColour,this);
		}
	}
}

//Basic Getters
int Cell:: getX(){ return x; }
int Cell::getY(){ return y; }

