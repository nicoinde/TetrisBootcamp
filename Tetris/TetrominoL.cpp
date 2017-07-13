
#include "TetrominoL.h"

TetrominoL::TetrominoL() :Tetromino()
{
	cantRotPosibles = 4;
	generateShapes();
}


TetrominoL::~TetrominoL()
{
	/*delete pos0;
	delete pos1;
	delete pos2;
	delete pos3;*/
}


void TetrominoL::generateShapes() {
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((i == 2 && j == 3) || (i == 3 && j>0)) {
				pos0[i][j] = 3;
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
			if ((i == 1 && j == 1) || (i>0 && j == 2)) {
				pos1[i][j] = 3;
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
			if ((i == 2 && j>0) || (i == 3 && j == 1)) {
				pos2[i][j] = 3;
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
			if ((j == 1 && i>0) || (j == 2 && i == 3)) {
				pos3[i][j] = 3;
			}
			else {
				pos3[i][j] = 0;
			}
		}
	}

	/*pos0
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,3 },
	{ 0,3,3,3 } };
	pos1=
	{ 0,0,0,0 },
	{ 0,3,3,0 },
	{ 0,0,3,0 },
	{ 0,0,3,0 } }

	pos2
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,3,3,3 },
	{ 0,3,0,0 } };
	pos3= {
	{ 0,0,0,0 },
	{ 0,3,0,0 },
	{ 0,3,0,0 },
	{ 0,3,3,0 } };
	;*/
}
int TetrominoL::getCell(int x, int y)
{
	if (x >= 0 && x < tetroHeight && y >= 0 && y < tetroWidth) {

		switch (rotacionActual) {
		case 0: return pos0[y][x]; break;
		case 1: return pos1[y][x]; break;
		case 2: return pos2[y][x]; break;
		case 3: return pos3[y][x]; break;
		default: return -1;
		}
	}
	return -1;
}