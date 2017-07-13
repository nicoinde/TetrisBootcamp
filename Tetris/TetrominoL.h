#pragma once
#include "Tetromino.h"

class TetrominoL :
	public Tetromino
{
public:
	TetrominoL();
	~TetrominoL();
	int getCell(int x, int y);
	void generateShapes();
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
	int pos2[tetroHeight][tetroWidth];
	int pos3[tetroHeight][tetroWidth];
};
