#pragma once
#include "Tetromino.h"

class TetrominoI :
	public Tetromino
{
public:
	TetrominoI();
	~TetrominoI();
	int getCell(int x, int y);
	void generateShapes();
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];

};
