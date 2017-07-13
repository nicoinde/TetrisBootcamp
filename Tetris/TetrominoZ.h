#pragma once
#include "Tetromino.h"

class TetrominoZ :
	public Tetromino
{
public:
	TetrominoZ();
	~TetrominoZ();
	int getCell(int x, int y);
	void generateShapes();
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
};

