
#include "TetrominoZ.h"

TetrominoZ::TetrominoZ() :Tetromino()
{
	cantRotPosibles = 2;
	generateShapes();
}


TetrominoZ::~TetrominoZ()
{
	//delete pos0;
	//delete pos1;
}


void TetrominoZ::generateShapes() {
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((i == 3 && j > 1) || (i == 2 && j>0 && j<3)) {
				pos0[i][j] = 7;
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
			if ((i<3 && i > 0 && j == 2) || (i>1 && j == 1)) {
				pos1[i][j] = 7;
			}
			else {
				pos1[i][j] = 0;
			}
		}
	}
	/*pos0=
	{0,0,0,0},
	{0,0,0,0},
	{0,7,7,0},
	{0,0,7,7}

	pos1=
	{ 0,0,0,0 },
	{ 0,0,7,0 },
	{ 0,7,7,0 },
	{ 0,7,0,0 } };*/
}

int TetrominoZ::getCell(int x, int y)
{
	if (x >= 0 && x < tetroHeight && y >= 0 && y < tetroWidth) {

		switch (currentRotation) {
		case 0: return pos0[y][x]; break;
		case 1: return pos1[y][x]; break;
		default: return -1;
		}
	}
	return -1;
}
