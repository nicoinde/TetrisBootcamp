#include "TetrominoEsp.h"


// ---------------------------TETROMINO I ------------------------------------------------

TetrominoI::TetrominoI():Tetromino()
{	
	cantRotPosibles = 2;
	generarFormas();
}


TetrominoI::~TetrominoI()
{
}

int TetrominoI::rotar() {
	return 0;
}


void TetrominoI::generarFormas() {
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if (i==2) {
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
				pos0[i][j] = 1;
			}
			else {
				pos0[i][j] = 0;
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

int TetrominoI::getCelda(int x, int y)
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





// ---------------------------TETROMINO J ------------------------------------------------

TetrominoJ::TetrominoJ() :Tetromino()
{
	cantRotPosibles = 4;
	generarFormas();
}


TetrominoJ::~TetrominoJ()
{
}

int TetrominoJ::rotar() {
	return 0;
}

void TetrominoJ::generarFormas() {
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((i == 2&&j==2)||(i==3&&j>0)) {
				pos0[i][j] = 2;
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
			if ((j == 1&&j==4)||(i>0&&j==2)) {
				pos1[i][j] = 2;
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
			if ((i == 2&&j>1)||(i==4&&j==4)) {
				pos2[i][j] = 2;
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
			if ((j == 1&&i>0)||(j==2&&i==1)) {
				pos3[i][j] = 2;
			}
			else {
				pos3[i][j] = 0;
			}
		}
	}
		
	/*
	pos0 =
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,2,0,0 },
		{ 0,2,2,2 }
	pos1=
		{ 0,0,0,0 },
		{ 0,0,2,0 },
		{ 0,0,2,0 },
		{ 0,2,2,0 } };
	pos2=
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,2,2,2 },
		{ 0,0,0,2 } };
	pos3=
		{ 0,0,0,0 },
		{ 0,2,2,0 },
		{ 0,2,0,0 },
		{ 0,2,0,0 } };*/
}

int TetrominoJ::getCelda(int x, int y)
{
	if (x >= 0 && x < tetroHeight && y >= 0 && y < tetroWidth) {

		switch (rotacionActual) {
		case 0: return pos0[x][y]; break;
		case 1: return pos1[x][y]; break;
		case 2: return pos2[x][y]; break;
		case 3: return pos3[x][y]; break;
		default: return -1;
		}
	}
	return -1;
}

// ---------------------------TETROMINO L ------------------------------------------------

TetrominoL::TetrominoL() :Tetromino()
{
	cantRotPosibles = 4;
	generarFormas();
}


TetrominoL::~TetrominoL()
{
}

int TetrominoL::rotar() {
	return 0;
}
void TetrominoL::generarFormas() {
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((i ==2  && j == 4) || (i == 3 && j>0)) {
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
			if ((i == 2 && j>1) || (i == 4 && j == 2)) {
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
int TetrominoL::getCelda(int x, int y)
{
	if (x >= 0 && x < tetroHeight && y >= 0 && y < tetroWidth) {

		switch (rotacionActual) {
		case 0: return pos0[x][y]; break;
		case 1: return pos1[x][y]; break;
		case 2: return pos2[x][y]; break;
		case 3: return pos3[x][y]; break;
		default: return -1;
		}
	}
	return -1;
}

// ---------------------------TETROMINO O ------------------------------------------------

TetrominoO::TetrominoO() :Tetromino()
{
	cantRotPosibles = 1;
	generarFormas();
}


TetrominoO::~TetrominoO()
{
}

int TetrominoO::rotar() {
	return 0;
}

void TetrominoO::generarFormas() {
	
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if (i > 1 && j < 4 && j > 0 ) {
				pos0[i][j] = 4;
			}
			else {
				pos0[i][j] = 0;
			}
		}
	}//pos0 { { 0,0,0,0 },{ 0,0,0,0 },{ 0,4,4,0 },{ 0,4,4,0 } };

}

int TetrominoO::getCelda(int x, int y)
{
return pos0[x][y]; 
}


// ---------------------------TETROMINO S ------------------------------------------------

TetrominoS::TetrominoS()
{
	cantRotPosibles = 2;
	generarFormas();
}


TetrominoS::~TetrominoS()
{
}

int TetrominoS::rotar() {
	return 0;
}

void TetrominoS::generarFormas() {
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((i == 2 && j > 1) || (i == 3 && j>0&&j<3)) {
				pos0[i][j] = 5;
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
			if ((i<3 && i > 0 && j ==1) || (i>1 && j == 2)) {
				pos1[i][j] = 5;
			}
			else {
				pos1[i][j] = 0;
			}
		}
	}
	/*pos0=
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,5,5 },
		{ 0,5,5,0 } };
	pos1=
		{ 0,0,0,0 },
		{ 0,5,0,0 },
		{ 0,5,5,0 },
		{ 0,0,5,0 } };*/
}

int TetrominoS::getCelda(int x, int y)
{
	if (x >= 0 && x < tetroHeight && y >= 0 && y < tetroWidth) {

		switch (rotacionActual) {
		case 0: return pos0[x][y]; break;
		case 1: return pos1[x][y]; break;
		default: return -1;
		}
	}
	return -1;
}


// ---------------------------TETROMINO T ------------------------------------------------

TetrominoT::TetrominoT() :Tetromino()
{
	cantRotPosibles = 4;
	generarFormas();
}


TetrominoT::~TetrominoT()
{
}

int TetrominoT::rotar() {
	return 0;
}
void TetrominoT::generarFormas() {
	for (short i = 0; i < tetroHeight; ++i)
	{
		for (short j = 0; j < tetroWidth; ++j)
		{
			if ((i == 2 && j > 0) || (i == 3 && j==2)) {
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
			if ((j == 2 && i >0) || (i==2 && j == 4)) {
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
			if ((j == 2 && i>0) || (j == 1 && i == 1)) {
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
int TetrominoT::getCelda(int x, int y)
{
	if (x >= 0 && x < tetroHeight && y >= 0 && y < tetroWidth) {

		switch (rotacionActual) {
		case 0: return pos0[x][y]; break;
		case 1: return pos1[x][y]; break;
		case 2: return pos2[x][y]; break;
		case 3: return pos3[x][y]; break;
		default: return -1;
		}
	}
	return -1;
}


// ---------------------------TETROMINO Z ------------------------------------------------

TetrominoZ::TetrominoZ() :Tetromino()
{
	cantRotPosibles = 2;
	generarFormas();
}


TetrominoZ::~TetrominoZ()
{
}

int TetrominoZ::rotar() {
	return 0;
}

void TetrominoZ::generarFormas() {
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

int TetrominoZ::getCelda(int x, int y)
{
	if (x >= 0 && x < tetroHeight && y >= 0 && y < tetroWidth) {

		switch (rotacionActual) {
		case 0: return pos0[x][y]; break;
		case 1: return pos1[x][y]; break;
		default: return -1;
		}
	}
	return -1;
}