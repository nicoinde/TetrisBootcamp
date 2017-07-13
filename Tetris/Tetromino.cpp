#include "Tetromino.h"



Tetromino::Tetromino() :rotacionActual(0)
{
}


Tetromino::~Tetromino()
{
}

int Tetromino::rotate()
{
	int aux = (rotacionActual + 1) % cantRotPosibles;
	rotacionActual = aux;
	return rotacionActual;
}

int Tetromino::rotateInversed()
{
	int aux = (rotacionActual +cantRotPosibles - 1) % cantRotPosibles;
	rotacionActual = aux;
	return rotacionActual;
}

void Tetromino::setRotation(int ind)
{
	rotacionActual = ind;
}

int Tetromino::getRotation()
{
	return rotacionActual;
}

void Tetromino::resetRotation()
{
	rotacionActual = 0;
}

unsigned Tetromino::getTetroWidth()
{
	return tetroWidth;
}

unsigned Tetromino::getTetroHeight()
{
	return tetroHeight;
}



