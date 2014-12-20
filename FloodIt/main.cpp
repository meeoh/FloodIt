#include <iostream>
#include "cell.h"
#include "board.h"
#include <time.h>

using namespace std;

int main(){
	srand(time(NULL));

	cout << "Hello World!" << endl;
	Board *board = new Board(5, 5);
	cout << *board;

	Cell *origin = board->getCell(0, 0);

	origin->switchColour('R');

	cout << *board;


	delete board;
	getchar();
}