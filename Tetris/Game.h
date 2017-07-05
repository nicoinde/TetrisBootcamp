#pragma once
#include "GestorGrafico.h"
#include "Tetromino.h"
#include "Board.h"
class Game
{
public:
	//template<Tetromino Tetro>
	Game();
	//Game(Gestor &ges);
	~Game();
	bool tick();
	bool stepDown();
	bool rotateTetro();
	bool moveLeft();
	bool moveRight();
	bool fastDown();
	
	//TetrominoI pieza;

private:
	
	struct Piezas pieza;
	struct Piezas piezaSig;
	bool endGame;
	float intervalo;
	int** tableroPrueba;
	void makeTableroPrueba();
	Tetromino tetros[7];	
	Board tablero;
	void generarPieza();
};

