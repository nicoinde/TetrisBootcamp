#pragma once
#include "Tetromino.h"


class TetrominoS :
	public Tetromino
{
public:
	TetrominoS();
	~TetrominoS();
	int getCell(int x, int y);
	
private:
	void generateShapes();
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
};