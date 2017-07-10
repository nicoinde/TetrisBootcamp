#include "Tetromino.h"



Tetromino::Tetromino() :rotacionActual(0)
{
}


Tetromino::~Tetromino()
{
}

int Tetromino::rotar()
{
	int aux = (rotacionActual + 1) % cantRotPosibles;
	rotacionActual = aux;
	return rotacionActual;
}

int Tetromino::rotarInverso()
{
	int aux = (rotacionActual +cantRotPosibles - 1) % cantRotPosibles;
	rotacionActual = aux;
	return rotacionActual;
}

int Tetromino::getRotacion()
{
	return rotacionActual;
}

void Tetromino::resetRotacion()
{
	rotacionActual = 0;
}

void Tetromino::mostrarTetro()
{

}



