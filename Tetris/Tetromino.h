#pragma once

class Tetromino
{
public:
	Tetromino();
	virtual ~Tetromino();
	int rotar();
	int rotarInverso();
	virtual int getRotacion();
	virtual void resetRotacion();
	virtual int getCelda(int x, int y) = 0;
	virtual void mostrarTetro();
	static const unsigned tetroWidth = 4;
	static const unsigned tetroHeight = 4;


protected:
	int cantRotPosibles;
	int rotacionActual;
	
	
};

