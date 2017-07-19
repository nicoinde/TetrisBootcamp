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

//this method takes care of checking if there are any tetromino's collisions on the position determined with parameters "x" and "y" 
//by checking tetromino's cells one by one, only doing something when the current cell value is != 0, which means there is a part of the tetromino in that place
bool Board::collision(Tetromino *piece, int x, int y) {
	for (int i = 0; i < piece->getTetroHeight(); ++i)
	{
		for (short j = 0; j < piece->getTetroWidth(); ++j)
		{
			if (piece->getCell(j, i) != 0) {
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

//this method clears the shape of a tetromino on the board, avoiding collision checking faliures by colliding with them selves
bool Board::clearTetromino(Tetromino *piece, int x, int y) {
	for (int i = 0; i < piece->getTetroHeight(); ++i)
	{
		for (int j = 0; j < piece->getTetroWidth(); ++j)
		{
			if (piece->getCell(j, i) != 0) {
				tablero[y + i][x + j] = 0;
			}
		}
	}
	return true;
}


//this settle the piece on the board
bool Board::settle(Tetromino *piece, int x, int y) {

	for (int i = 0; i < piece->getTetroHeight(); ++i)
	{
		for (short j = 0; j < piece->getTetroWidth(); ++j)
		{
			if (piece->getCell(j, i) > 0) {

				tablero[y + i][x + j] = piece->getCell(j, i);

			}
			else {
				if (piece->getCell(j, i) == -1) {
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

//this make every cell of "tablero" change it's value to 0, thus restarting the game
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


//this method is responsible of check every line of the board looking for full lines, and, every time it found it, calls the "clearLine" function,
int Board::checkFullLines(float y) {
	int cont = 0;
	bool completa;
	short i;
	for (i =softBottomBorder-1; i >=y; --i) {
		completa = true;
		for (short j = softLeftBorder + 1; (j > softLeftBorder && j < softRightBorder&&i>=y); ++j) {
			completa = true;
			if (tablero[i][j] == 0) {
				completa = false;
				j = softLeftBorder;
				if (i >= y-1) {
					--i;
				}
			}
		}
		if (completa) {
			clearLine(i);
			cont++;
			i=softBottomBorder-1; 
		}
	}
	return cont;
}

//this replace the full line with the upper line and update the rest of the board
void Board::clearLine(int y) {
	for (short i = y; i > softUpperBorder; --i) {
		for (short j = softLeftBorder; j < softRightBorder; ++j) {
			tablero[i][j] = tablero[i - 1][j];
	
		}
	}

}

unsigned short Board::getBoardHeight() {
	return boardHeight;
}

unsigned short Board::getBoardWidth() {
	return boardWidth;
}

unsigned short Board::getSoftLeftBorder() {
	return softLeftBorder;
}

unsigned short Board::getSoftRightBorder() {
	return softRightBorder;
}

unsigned short Board::getSoftUpperBorder() {
	return softUpperBorder;
}

unsigned short Board::getSoftBottomBorder() {
	return softBottomBorder;
}
Board::~Board()
{
	//delete tablero;
}
