#include "TetrominoEsp.h"


// ---------------------------TETROMINO I ------------------------------------------------

TetrominoI::TetrominoI()
{
	generarFormas();
}


TetrominoI::~TetrominoI()
{
}

int TetrominoI::rotar() {
	return 0;
}

void TetrominoI::generarFormas() {
	posiciones.pos1[width][height] = { { 0,0,0,0 },{ 0,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 } };
	posiciones.pos2[width][height] = { { 0,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 } };

}


// ---------------------------TETROMINO J ------------------------------------------------

TetrominoJ::TetrominoJ()
{
	generarFormas();
}


TetrominoJ::~TetrominoJ()
{
}

int TetrominoJ::rotar() {
	return 0;
}

void TetrominoJ::generarFormas() {
	posiciones.pos1[width][height] = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,2,0,0 },{ 0,2,2,2 } };
	posiciones.pos2[width][height] = { { 0,0,0,0 },{ 0,0,2,0 },{ 0,0,2,0 },{ 0,2,2,0 } };
	posiciones.pos3[width][height] = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,2,2,2 },{ 0,0,0,2 } };
	posiciones.pos4[width][height] = { { 0,0,0,0 },{ 0,2,2,0 },{ 0,2,0,0 },{ 0,2,0,0 } };
}

// ---------------------------TETROMINO L ------------------------------------------------

TetrominoL::TetrominoL()
{
	generarFormas();
}


TetrominoL::~TetrominoL()
{
}

int TetrominoL::rotar() {
	return 0;
}
void TetrominoL::generarFormas() {
	posiciones.pos1[width][height] = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,3 },{ 0,3,3,3 } };
	posiciones.pos2[width][height] = { { 0,0,0,0 },{ 0,3,0,0 },{ 0,3,0,0 },{ 0,3,3,0 } };
	posiciones.pos3[width][height] = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,3,3,3 },{ 0,3,0,0 } };
	posiciones.pos4[width][height] = { { 0,0,0,0 },{ 0,3,3,0 },{ 0,0,3,0 },{ 0,0,3,0 } };
}

// ---------------------------TETROMINO O ------------------------------------------------

TetrominoO::TetrominoO()
{
	generarFormas();
}


TetrominoO::~TetrominoO()
{
}

int TetrominoO::rotar() {
	return 0;
}

void TetrominoO::generarFormas() {
	posiciones.pos1[width][height] = { { 0,0,0,0 },{ 0,0,0,0 },{ 0,4,4,0 },{ 0,4,4,0 } };

}


// ---------------------------TETROMINO S ------------------------------------------------

TetrominoS::TetrominoS()
{
	generarFormas();
}


TetrominoS::~TetrominoS()
{
}

int TetrominoS::rotar() {
	return 0;
}

void TetrominoS::generarFormas() {
	posiciones.pos1[width][height] = {
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,0,5,5 },
		{ 0,5,5,0 } };
	posiciones.pos2[width][height] = { 
		{ 0,0,0,0 },
		{ 0,5,0,0 },
		{ 0,5,5,0 },
		{ 0,0,5,0 } };
}


// ---------------------------TETROMINO T ------------------------------------------------

TetrominoT::TetrominoT()
{
	generarFormas();
}


TetrominoT::~TetrominoT()
{
}

int TetrominoT::rotar() {
	return 0;
}
void TetrominoT::generarFormas() {
	posiciones.pos1[width][height] = { 
		{ 0,0,0,0 },
		{ 0,0,0,0 },
		{ 0,6,6,6 },
		{ 0,0,6,0 } };
	posiciones.pos2[width][height] = { 
		{ 0,0,0,0 },
		{ 0,0,6,0 },
		{ 0,0,6,6 },
		{ 0,0,6,0 } };
	posiciones.pos3[width][height] = {
		{ 0,0,0,0 },
		{ 0,0,6,0 },
		{ 0,6,6,6 },
		{ 0,0,0,0 } };
	posiciones.pos4[width][height] = { 
		{ 0,0,0,0 },
		{ 0,0,6,0 },
		{ 0,6,6,0 },
		{ 0,0,6,0 } };
}


// ---------------------------TETROMINO Z ------------------------------------------------

TetrominoZ::TetrominoZ()
{
	generarFormas();
}


TetrominoZ::~TetrominoZ()
{
}

int TetrominoZ::rotar() {
	return 0;
}

void TetrominoZ::generarFormas() {
	posiciones.pos1[width][height] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,7,7,0},
		{0,0,7,7}
	};
	posiciones.pos2[width][height] = {
		{ 0,0,0,0 },
		{ 0,0,7,0 },
		{ 0,7,7,0 },
		{ 0,7,0,0 } };
}
