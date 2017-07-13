
#include "TetrominoO.h"

TetrominoO::TetrominoO() :Tetromino()
{
	cantRotPosibles = 1;
	generateShapes();
}


TetrominoO::~TetrominoO()
{
	//delete pos0;
}

void TetrominoO::generateShapes() {

	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if (i > 1 && j < 3 && j > 0) {
				pos0[i][j] = 4;
			}
			else {
				pos0[i][j] = 0;
			}
		}
	}//pos0 { { 0,0,0,0 },{ 0,0,0,0 },{ 0,4,4,0 },{ 0,4,4,0 } };

}

int TetrominoO::getCell(int x, int y)
{
	return pos0[y][x];
}