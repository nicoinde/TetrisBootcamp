#pragma once
#include "Tetromino.h"

class TetrominoO :
	public Tetromino
{
public:
	TetrominoO();
	~TetrominoO();
	int getCell(int x, int y);
	
private:
	void generateShapes();
	int pos0[tetroHeight][tetroWidth];

}; 
