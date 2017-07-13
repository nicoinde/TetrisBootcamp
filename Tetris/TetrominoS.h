#pragma once
#include "Tetromino.h"


class TetrominoS :
	public Tetromino
{
public:
	TetrominoS();
	~TetrominoS();
	int getCell(int x, int y);
	void generateShapes();
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
};