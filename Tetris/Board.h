#pragma once
#include "TetrominoEsp.h"
class Board
{
public:
	Board();
	~Board();
	//enum valores{0,1,2,3,4,5,6,7};
	void mostrar();             //solo para ver como se crea el tablero borrar despues
	int** getTablero();
	void setTablero(int** tab);
	int verificarLineasCompletas();
	void limpiarLinea(int x);
	bool asentar(int pieza[Tetromino::tetroHeight][Tetromino::tetroWidth], int x, int y);
	bool moveDown(int pieza[Tetromino::tetroHeight][Tetromino::tetroWidth], int x, int y);
private:
	int** tablero;
	bool colision;

};

