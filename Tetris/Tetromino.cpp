#include "Tetromino.h"



Tetromino::Tetromino() :currentRotation(0)
{
}


Tetromino::~Tetromino()
{
}

int Tetromino::rotate()
{
	int aux = (currentRotation + 1) % cantRotPosibles;
	currentRotation = aux;
	return currentRotation;
}

int Tetromino::rotateInversed()
{
	int aux = (currentRotation +cantRotPosibles - 1) % cantRotPosibles;
	currentRotation = aux;
	return currentRotation;
}

void Tetromino::setRotation(int ind)
{
	currentRotation = ind;
}

int Tetromino::getRotation()
{
	return currentRotation;
}

void Tetromino::resetRotation()
{
	currentRotation = 0;
}

unsigned Tetromino::getTetroWidth()
{
	return tetroWidth;
}

unsigned Tetromino::getTetroHeight()
{
	return tetroHeight;
}



