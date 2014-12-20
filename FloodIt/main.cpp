#include <iostream>
#include "cell.h"
#include "board.h"

using namespace std;

int main(){
	cout << "Hello World!" << endl;
	Board *board = new Board(5, 10);
	cout << *board;




	getchar();
}