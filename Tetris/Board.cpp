#include "Board.h"
#include <iostream>
using namespace std;

static const unsigned short boardWidth = 13;
static const unsigned short boardHeight = 22;
static const unsigned short softLeftBorder = 0;
static const unsigned short softRightBorder = 11;
static const unsigned short softBottomBorder = 22;
static const unsigned short softUpperBorder = 1;
Board::Board()
{
	colision = false;
	tablero = new int *[boardHeight];
	for (int i = 0; i < boardHeight; ++i)
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

//este metodo se encarga de registrar el movimiento del tetromino en el tablero
bool Board::moveDown(int pieza[Tetromino::tetroHeight][Tetromino::tetroWidth], int x, int y) {
	colision = asentar(pieza, x, y+1);
	
	
	return !colision;
}


//me falta implementar los templates para la derivacion de los tetrominos
bool Board::asentar(int pieza[Tetromino::tetroHeight][Tetromino::tetroWidth], int x, int y) {

	for (int i=3; i>=x; --i)
	{	
		for (short j =0; j<y+3; ++j)
		{
			if(pieza[i][j]!=0){
				if (x + i < softLeftBorder||x + i > softRightBorder || y + j > softBottomBorder) {
					colision = true;
					return !colision;
				}

				if (tablero[x + i][y + j] !=0) {
					colision = true;
					return !colision;
				}else{
					tablero[x + i][y + j] = pieza[i][j];
				}
			}
			
		}
	}
	return !colision;
}

int Board::verificarLineasCompletas(){
	int cont=0;
	for (short i = softBottomBorder; i > softUpperBorder;--i) {
		bool completa = true;
		for (short j = softLeftBorder; j < softRightBorder; ++j) {
			if (tablero[i][j] = 0) {
				completa = false;
				j = 0;
				--i;
			}
		}
		if (completa) {
			limpiarLinea(i);
			++cont;
			++i;
		}
	}
	return cont;
}

void Board::limpiarLinea(int x) {
	
	for (short i = x; i > softUpperBorder; --i) {
		for (short j = softLeftBorder; j < softRightBorder; ++j) {
			tablero[i][j] = tablero[i + 1][j + 1];
		}
		
	}

}

Board::~Board()
{
}
