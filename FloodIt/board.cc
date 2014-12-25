#include "board.h"
#include <iostream>
#include <string>
#include "cell.h"

using namespace std;


//Board constructor
Board::Board(int sizeX, int sizeY):board(sizeX, vector< Cell* >(sizeY)), sizeX(sizeX), sizeY(sizeY) {	
	redCount = 0;
	blueCount = 0;
	yellowCount = 0;
	greenCount = 0;

	//Populate 2D Array with cells
	for (int i = 0; i < sizeY; i++){
		for (int j = 0; j < sizeX; j++){
			//Pass the cell a pointer to the board
			board[j][i] = new Cell(j, i,this);
			//Keep track of the colours of each cell, to tell if a player has won
			//If the cell is red
			if (board[j][i]->getColour() == 'R'){
				redCount++;
			}
			//If the cell is blue
			else if (board[j][i]->getColour() == 'B'){
				blueCount++;
			}
			//If the cell is green
			else if (board[j][i]->getColour() == 'G'){
				greenCount++;
			}
			//Otherwise the cell is yellow
			else {
				yellowCount++;
			}
		}		
	}

	//Loop through the 2D Array and assign each cell its neighbours
	for (int i = 0; i < sizeY; i++){
		for (int j = 0; j < sizeX; j++){
			//If the cell to the right of the current cell exists, assign it as a neighbour
			if (j + 1 < sizeX){								
				board[j][i]->setNeighbour(board[j+1][i]);
			}
			//If the cell to the left of the current cell exists, assign it as a neighbour
			if (j - 1 >= 0){				
				board[j][i]->setNeighbour(board[j - 1][i]);
			}
			//If the cell to the north of the current cell exists, assign it as a neighbour
			if (i + 1 < sizeY){				
				board[j][i]->setNeighbour(board[j][i + 1]);
			}
			//If the cell to the south of the current cell exists, assign it as a neighbour
			if (i - 1 >= 0){				
				board[j][i]->setNeighbour(board[j][i - 1]);
			}
		}
	}

}
//operator<<
//overload output operator to print grid correctly
std::ostream& operator<<(std::ostream &out, const Board &b){	
	for (int i = 0; i < b.sizeY; i++){
		for (int j = 0; j < b.sizeX; j++){
			out << b.board[j][i]->getColour();
		}
		out << std::endl;
	}
	return out;
}

//getCell(int x, int y)
//returns a cell on the board at (x,y)
Cell* Board::getCell(int x, int y){
	return board[x][y];
}

//Board destructor
Board::~Board(){
	for (int i = 0; i < sizeY; i++){
		for (int j = 0; j < sizeX; j++){
			delete board[j][i];
		}
	}
}

//addColour (char colour)
//adds one to the count of the passed in 'colour'
void Board::addColour(char oldColour, char newColour){
	if (newColour == 'R'){ redCount++; }
	else if (newColour == 'B'){ blueCount++; }
	else if (newColour == 'G'){ greenCount++; }
	else { yellowCount++; }

	if (oldColour == 'R'){ redCount--; }
	else if (oldColour == 'B'){ blueCount--; }
	else if (oldColour == 'G'){ greenCount--; }
	else { yellowCount--; }
}

//hasWon()
//Check if a player has won
bool Board::hasWon(){
	if (redCount == sizeX * sizeY || blueCount == sizeX * sizeY || greenCount == sizeX * sizeY || yellowCount == sizeX * sizeY){ return true; }
	return false;
}