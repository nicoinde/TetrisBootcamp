#pragma once
#include "TetrominoEsp.h"
class Board
{
public:
	Board();
	~Board();
	//enum valores{0,1,2,3,4,5,6,7};
	int** getTablero();
	void setTablero(int** tab);
	bool asentar(Board &tab, Tetromino &pieza, int x, int y);
private:
	int** tablero;

};

