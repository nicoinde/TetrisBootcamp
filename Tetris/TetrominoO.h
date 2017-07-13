#pragma once
#include "Tetromino.h"

class TetrominoO :
	public Tetromino
{
public:
	TetrominoO();
	~TetrominoO();
	int getCell(int x, int y);
	void generateShapes();
private:
	int pos0[tetroHeight][tetroWidth];

}; 
