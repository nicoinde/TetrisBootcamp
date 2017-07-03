#pragma once
class Tetromino
{
public:
	Tetromino();
	virtual ~Tetromino();
	virtual int rotar();
	virtual int getPosicion();
	virtual int** getForma()=0;
private:
	int rotacionActual;
protected:
	static const unsigned width = 4;
	static const unsigned height = 4;
	
};

