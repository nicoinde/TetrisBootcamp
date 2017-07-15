#include "Board.h"
#include <iostream>
using namespace std;

static const unsigned short boardWidth = 13;
static const unsigned short boardHeight = 21;
static const unsigned short softLeftBorder = 1;
static const unsigned short softRightBorder = 12;
static const unsigned short softBottomBorder = 21;
static const unsigned short softUpperBorder = 1;
Board::Board()
{
	restart();
}


bool Board::collision(Tetromino *pieza, int x, int y) {
	for (int i = 0; i < pieza->getTetroHeight(); ++i)
	{
		for (short j = 0; j < pieza->getTetroWidth(); ++j)
		{
			if (pieza->getCell(j, i) != 0) {
				if (x + j <= softLeftBorder || x + j >= softRightBorder || y + i >= softBottomBorder || y + i <= softUpperBorder) {
					return true;
				}

				if (tablero[y + i][x + j] != 0) {
					return true;
				}

			}

		}
	}
	return false;
}

bool Board::clearTetromino(Tetromino *pieza, int x, int y) {
	for (int i = 0; i < pieza->getTetroHeight(); ++i)
	{
		for (int j = 0; j < pieza->getTetroWidth(); ++j)
		{
			if (pieza->getCell(j, i) != 0) {
				tablero[y + i][x + j] = 0;
			}
		}
	}
	return true;
}


//me falta implementar los templates para la derivacion de los tetrominos
bool Board::asentar(Tetromino *pieza, int x, int y) {

	for (int i = 0; i < pieza->getTetroHeight(); ++i)
	{
		for (short j = 0; j < pieza->getTetroWidth(); ++j)
		{
			if (pieza->getCell(j, i) > 0) {

				tablero[y + i][x + j] = pieza->getCell(j, i);

			}
			else {
				if (pieza->getCell(j, i) == -1) {
					return false;
				}
			}

		}
	}
	return true;
}

int Board::getCell(int x, int y)
{
	return tablero[y][x];
}

void Board::restart()
{
	for (int i = 0; i < boardHeight; ++i)
	{

		for (short j = 0; j < boardWidth; ++j)
		{
			tablero[i][j] = 0;
		}
	}
}

int Board::verificarLineasCompletas() {
	int cont = 0;
	bool completa;
	for (short i = (softBottomBorder - 1); i >softUpperBorder; --i) {
		//completa = true;
		for (short j = softLeftBorder + 1; (j > softLeftBorder && j < softRightBorder&&i>softUpperBorder); ++j) {
			completa = true;
			if (tablero[i][j] == 0) {
				completa = false;
				j = softLeftBorder;
				if (i > softUpperBorder) {
					--i;
				}
			}
		}
		if (completa) {
			limpiarLinea(i);
			cont++;
			i=softBottomBorder-1; // deberia andar con ++i pero a veces se deja una linea completra sin limpiar
		}
	}
	return cont;
}

void Board::limpiarLinea(int y) {
	for (short i = y; i > softUpperBorder; --i) {
		for (short j = softLeftBorder; j < softRightBorder; ++j) {
			tablero[i][j] = tablero[i - 1][j];
		//	mostrar();
	
		}
	}

}

Board::~Board()
{
	//delete tablero;
}
