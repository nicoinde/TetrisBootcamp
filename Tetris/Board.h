#pragma once
#include "Tetromino.h"
class Board
{
public:
	Board();
	~Board();
	int checkFullLines(float y);
	void clearLine(int y);
	bool collision(Tetromino *piece, int x, int y);
	bool clearTetromino(Tetromino *piece, int x, int y);
	bool settle(Tetromino *piece, int x, int y);
	int getCell(int x, int y);
	void restart();
	unsigned short getBoardWidth();
	unsigned short getBoardHeight();
	unsigned short getSoftLeftBorder();
	unsigned short getSoftRightBorder();
	unsigned short getSoftUpperBorder();
	unsigned short getSoftBottomBorder();
private:
	static const unsigned short boardWidth = 13;
	static const unsigned short boardHeight = 22;
	static const unsigned short softLeftBorder = 0;
	static const unsigned short softRightBorder = 11;
	static const unsigned short softBottomBorder = 22;
	static const unsigned short softUpperBorder = 1;
	int tablero[boardHeight][boardWidth];

};

