#pragma once
#include "Tetromino.h"


class TetrominoJ :
	public Tetromino
{
public:
	TetrominoJ();
	~TetrominoJ();
	int getCell(int x, int y);
	
private:
	void generateShapes();
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
	int pos2[tetroHeight][tetroWidth];
	int pos3[tetroHeight][tetroWidth];
};
