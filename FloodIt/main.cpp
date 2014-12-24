#include <iostream>
#include "cell.h"
#include "board.h"
#include <time.h>
#include <limits>

using namespace std;

int main(){
	srand(time(NULL));

	int sizeX=0, sizeY=0;	
	
	//greeting
	cout << "Hello, Welcome to Shameels FloodIt 1.0!" << endl;
	cout << "To get started, enter the x dimension of the game board you wish to play on: ";
	//Dimension input
	cin >> sizeX;
	cout << "Now enter a y dimension: ";
	cin >> sizeY;

	//Create board and assign origin cell
	Board *board = new Board(sizeX, sizeY);
	Cell *origin = board->getCell(0, 0);
	//Display initial board
	cout << *board;

	//get input from user
	while (true){
		char choice;
		cout << "What colour would you like to change the origin (top left corner) to (R,B,G,Y)?" << endl;
		cin >> choice;
		//uppercase their choice
		origin->switchColour(choice);
		cout << *board;
		if (board->hasWon()){ cout << "YOU WIN"; break; }
		
	}
	getchar();
	delete board;
	getchar();
}