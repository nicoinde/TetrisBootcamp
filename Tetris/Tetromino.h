#pragma once
struct Piezas {
	Tetromino * pieza;
	float posX;
	float posY;
};
class Tetromino
{
public:
	Tetromino();
	virtual ~Tetromino();
	virtual int rotar();
	virtual int getPosicion();
	virtual int** getForma();
	static const unsigned tetroWidth = 4;
	static const unsigned tetroHeight = 4;
	struct Posiciones;


protected:
	
	int rotacionActual;
	
};

