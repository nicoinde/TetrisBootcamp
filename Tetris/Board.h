#pragma once
#include "Tetromino.h"
class Board
{
public:
	Board();
	~Board();
	int verificarLineasCompletas();
	void limpiarLinea(int x);
	bool hayColision(Tetromino *pieza, int x, int y);
	bool clearTetromino(Tetromino *pieza, int x, int y);
	bool asentar(Tetromino *pieza, int x, int y);
	int getCell(int x, int y);
	void restart();
	static const unsigned short boardWidth = 13;
	static const unsigned short boardHeight = 22;
	static const unsigned short softLeftBorder = 0;
	static const unsigned short softRightBorder = 11;
	static const unsigned short softBottomBorder = 22;
	static const unsigned short softUpperBorder = 1;
private:
	int tablero[boardHeight][boardWidth];

};

