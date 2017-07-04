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
	bool drawPieces();
	//TetrominoI pieza;

private:
	Gestor gestor;
	struct Piezas{
		Tetromino pieza;
		float posX;
		float posY;
	}pieza, piezaSig;
	bool endGame;
	float intervalo;
	
	//template<Tetromino> piezaSig;
	Board tablero;
	void generarPieza();
};

