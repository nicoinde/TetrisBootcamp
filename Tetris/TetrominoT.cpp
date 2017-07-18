#include "TetrominoT.h"


TetrominoT::TetrominoT() :Tetromino()
{
	cantRotPosibles = 4;
	generateShapes();
}


TetrominoT::~TetrominoT()
{
	//delete pos0;
	//delete pos1;
	//delete pos2;
	//delete pos3;
}


void TetrominoT::generateShapes() {
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((i == 2 && j > 0) || (i == 3 && j == 2)) {
				pos0[i][j] = 6;
			}
			else {
				pos0[i][j] = 0;
			}
		}
	}
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((j == 2 && i >0) || (i == 2 && j == 3)) {
				pos1[i][j] = 6;
			}
			else {
				pos1[i][j] = 0;
			}
		}
	}
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((i == 2 && j>0) || (i == 1 && j == 2)) {
				pos2[i][j] = 6;
			}
			else {
				pos2[i][j] = 0;
			}
		}
	}
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((j == 2 && i>0) || (j == 1 && i == 2)) {
				pos3[i][j] = 6;
			}
			else {
				pos3[i][j] = 0;
			}
		}
	}



	/*pos0=
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,6,6,6 },
	{ 0,0,6,0 } };
	pos1=
	{ 0,0,0,0 },
	{ 0,0,6,0 },
	{ 0,0,6,6 },
	{ 0,0,6,0 } };
	pos2=
	{ 0,0,0,0 },
	{ 0,0,6,0 },
	{ 0,6,6,6 },
	{ 0,0,0,0 } };
	pos3=
	{ 0,0,0,0 },
	{ 0,0,6,0 },
	{ 0,6,6,0 },
	{ 0,0,6,0 } };*/
}
int TetrominoT::getCell(int x, int y)
{
	if (x >= 0 && x < tetroHeight && y >= 0 && y < tetroWidth) {

		switch (currentRotation) {
		case 0: return pos0[y][x]; break;
		case 1: return pos1[y][x]; break;
		case 2: return pos2[y][x]; break;
		case 3: return pos3[y][x]; break;
		default: return -1;
		}
	}
	return -1;
}