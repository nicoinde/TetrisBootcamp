#include "Board.h"
#include <iostream>
using namespace std;

static const unsigned short boardWidth = 13;
static const unsigned short boardHeight = 22;

Board::Board()
{
	tablero = new int*[boardHeight]  ;
	for (int  i = 0; i < boardHeight; ++i)
	{
		tablero[i] = new int[boardWidth];
		for (short j = 0; j < boardWidth; ++j)
		{
			tablero[i][j] = 0;
		}
	}
}

void Board::mostrar() {
	for (short i = 0; i < boardHeight; ++i)
	{
		for (short j = 0; j < boardWidth; ++j)
		{
			cout << tablero[i][j];
		}
		cout << endl;
	}
	
}

Board::~Board()
{
}
