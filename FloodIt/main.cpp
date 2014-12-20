#include <iostream>
#include "cell.h"
#include "board.h"
#include <time.h>

using namespace std;

int main(){
	srand(time(NULL));

	cout << "Hello World!" << endl;
	Board *board = new Board(5, 10);
	cout << *board;



	delete board;
	getchar();
}