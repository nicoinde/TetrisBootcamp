#include "Tetromino.h"



Tetromino::Tetromino()
{
	rotacionActual = 0;
}


Tetromino::~Tetromino()
{
}

//int Tetromino::rotar()
//{
//	int aux = (rotacionActual + 1) % 4;
//	rotacionActual = aux;
//	return rotacionActual;
//}

int Tetromino::getPosicion()
{
	return rotacionActual;
}
