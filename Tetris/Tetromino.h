#pragma once

class Tetromino
{
public:
	Tetromino();
	virtual ~Tetromino();
	virtual int rotar();
	virtual int getRotacion();
	virtual int getCelda(int x, int y) = 0;
	static const unsigned tetroWidth = 4;
	static const unsigned tetroHeight = 4;


protected:
	int cantRotPosibles;
	int rotacionActual;
	
	
};

