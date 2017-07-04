#pragma once
#include "Gestor.h"
#include "TetrominoEsp.h"
#include "Board.h"
class Game
{
public:
	//template<Tetromino Tetro>
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
	//TetrominoI pieza;

private:
	Gestor gestor;
	bool endGame;
	float intervalo;
	
	//template<Tetromino> piezaSig;
	Board tablero;
	//template<Tetromino> generarPieza();
};

