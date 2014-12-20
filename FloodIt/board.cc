#include "board.h"
#include <iostream>
#include "cell.h"

using namespace std;

Board::Board(int sizeX, sizeY):board(sizeY, vector< Cell* >(sizeX)) {
	cout << "board constructor called" << endl;
}