#include "board.h"
#include <iostream>
#include <string>
#include "cell.h"

using namespace std;



Board::Board(int sizeX, int sizeY):board(sizeX, vector< Cell* >(sizeY)), sizeX(sizeX), sizeY(sizeY) {
	cout << "board constructor called" << endl;
	
	for (int i = 0; i < sizeY; i++){
		for (int j = 0; j < sizeX; j++){
			board[j][i] = new Cell(j, i);
		}		
	}
	
	
}

std::ostream& operator<<(std::ostream &out, const Board &b){
	cout << "board operator<< called" << endl;
	for (int i = 0; i < b.sizeY; i++){
		for (int j = 0; j < b.sizeX; j++){
			out << b.board[j][i]->getColour();
		}
		out << std::endl;
	}
	return out;
}

