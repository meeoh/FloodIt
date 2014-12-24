#include "cell.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "board.h"

using namespace std;

//Cell constructor
Cell::Cell(int x, int y, Board *board):x(x),y(y),board(board),currentNeighbour(0),neighbours(4,NULL){	
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
void Cell::notify(char oldColour,char newColour){	
	if (oldColour == colour){			
		this->switchColour(newColour);		
	}	
}

//switchColour(char newColour)
//Switches colour of current cell to 'newColour'
void Cell::switchColour(char newColour) {
	//oldColour is our current colour
	char oldColour = colour;	
	//if we're assigning our cell to its current colour
	//nothing happens
	if (oldColour == newColour){return; }
	colour = newColour;	
	//Set notified to true so it doesnt get notified again
	notified = true;
	//Add the colour to our total, so we can tell if a player has won
	board->addColour(colour);

	//Loop through all neighbours, and call notify on each one
	for (int i = 0; i < 4; i++){
		//If the neighbour exists
		if (neighbours[i]){
			//If the neighbour hasnt been already notified
			if (!neighbours[i]->notified){				
				//Notify it!
				neighbours[i]->notify(oldColour, newColour);
			}
		}
	}
}

//Basic Getters
int Cell:: getX(){ return x; }
int Cell::getY(){ return y; }

