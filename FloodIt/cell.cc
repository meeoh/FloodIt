#include "cell.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

//Cell constructor
Cell::Cell(int x, int y):x(x),y(y),neighbours(4,NULL){

	//Generate random colour
	int colourChoice = (rand()%3) + 1;	
	colour = 'B';
	//Assign colour
	/*
	switch (colourChoice){		
	case 1:		colour = 'R';	break;
	case 2:		colour = 'B';	break;
	case 3:		colour = 'G';	break;
	case 4:		colour = 'Y';	break;
	
	}*/
}

//getColour()
//Returns colour of the current cell
char Cell :: getColour(){
	return colour;
}



//notify()
void Cell::notify(char oldColour,char newColour){
	cout << "old colour : " << oldColour << " newColour : " << newColour << endl;
	if (oldColour == colour){			
		this->switchColour(newColour);		
	}	
}

void Cell::switchColour(char newColour) {
	char oldColour = colour;
	//cout << "old colour : " << oldColour << " newColour : " << newColour << endl;
	if (oldColour == newColour){ return; }	
	colour = newColour;	

	//Loop through all neighbours, and call notify on each one
	for (int i = 0; i < numNeighbours; i++){
		neighbours[i]->notify(oldColour, newColour);
	}
}


int Cell:: getX(){ return x; }
int Cell::getY(){ return y; }

