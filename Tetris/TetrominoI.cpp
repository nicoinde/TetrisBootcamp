#include "TetrominoI.h"

TetrominoI::TetrominoI() :Tetromino()
{
	cantRotPosibles = 2;
	generateShapes();
}


TetrominoI::~TetrominoI()
{
	/*delete pos0;
	delete pos1;*/
}



void TetrominoI::generateShapes() {
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if (i == 2) {
				pos0[i][j] = 1;
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
			if (j == 1) {
				pos1[i][j] = 1;
			}
			else {
				pos1[i][j] = 0;
			}
		}
	}

	/*
	pos0=
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 1,1,1,1 },
	{ 0,0,0,0 }
	pos1 =
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 }
	*/

}

int TetrominoI::getCell(int x, int y)
{
	if (x >= 0 && x < tetroHeight && y >= 0 && y < tetroWidth) {

		switch (rotacionActual) {
		case 0: return pos0[y][x]; break;
		case 1: return pos1[y][x]; break;
		default: return -1;
		}
	}
	return -1;
}