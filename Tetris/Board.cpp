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

bool Board::hayColision(Tetromino *pieza, int x, int y) {
	for (int i = 0; i < pieza->tetroHeight; ++i)
	{
		for (short j = 0; j < pieza->tetroWidth; ++j)
		{
			if (pieza->getCelda(j, i) != 0) {
				if (x + j <= softLeftBorder || x + j >= softRightBorder || y + i >= softBottomBorder) {
					return true;;
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
	for (int i = 0; i < pieza->tetroHeight; ++i)
	{
		for (int j = 0; j < pieza->tetroWidth; ++j)
		{
			if (pieza->getCelda(j, i) != 0) {
				tablero[y + i][x + j] = 0;
			}
		}
	}
	return true;
}


//me falta implementar los templates para la derivacion de los tetrominos
bool Board::asentar(Tetromino *pieza, int x, int y) {

	for (int i = 0; i < pieza->tetroHeight; ++i)
	{
		for (short j = 0; j < pieza->tetroWidth; ++j)
		{
			if (pieza->getCelda(j, i) > 0) {

				tablero[y + i][x + j] = pieza->getCelda(j, i);

			}
			else {
				if (pieza->getCelda(j, i) == -1) {
					return false;
				}
			}

		}
	}
	return true;
}

int Board::getCelda(int x, int y)
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
	for (short i = (softBottomBorder - 1); i > 1; --i) {
		bool completa = true;
		for (short j = softLeftBorder + 1; (j > softLeftBorder && j < softRightBorder&&i>0); ++j) {
			if (tablero[i][j] == 0) {
				completa = false;
				j = softLeftBorder;
				if (i > 0) {
					--i;
				}
			}
		}
		if (completa) {
			limpiarLinea(i);
			completa = false;
			++cont;
			++i;
		}
	}
	return cont;
}

void Board::limpiarLinea(int y) {
	for (short i = y; i > softUpperBorder; --i) {
		int cont = 0;
		for (short j = softLeftBorder + 1; j < softRightBorder; ++j) {
			tablero[i][j] = tablero[i - 1][j];
			if (tablero[i][j] != 0) {
				cont++;
			}

			/*mostrar();
			cout << "---------------------------------------" << endl;*/
		}
		if (cont == 0) {
			i = softUpperBorder;
		}
	}

}

Board::~Board()
{
}
