#include "cell.h"
#include <iostream>

using namespace std;

Cell::Cell(int x, int y):x(x),y(y){
}


void Cell::notify(){
	#ifdef DEBUG 
	cout << "notify called" << endl;
	#endif
	for(int i = 0; i < numNeighbours; i++){
	neighbours[i]->notify();
	}
}