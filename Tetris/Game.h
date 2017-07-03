#pragma once
#include "Gestor.h"
#include "TetrominoEsp.h"
#include "Board.h"
class Game
{
public:
	Game();
	//Game(Gestor &ges);
	~Game();
	int iniciar();
	bool ciclo();
	bool stepDown();
	bool rotateTetro();
	bool moveLeft();
	bool moveRight();
	bool fastDown();

private:
	Gestor gestor;
	bool endGame;
	float intervalo;
	Tetromino pieza;
	Tetromino piezaSig;
	Board tablero;
	Tetromino generarPieza();
};

