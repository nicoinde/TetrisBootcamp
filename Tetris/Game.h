#pragma once
#include "GestorGrafico.h"
#include "TetrominoI.h"
#include "TetrominoJ.h"
#include "TetrominoL.h"
#include "TetrominoO.h"
#include "TetrominoS.h"
#include "TetrominoT.h"
#include "TetrominoZ.h"

struct Piezas {
	Tetromino *pieza;
	int posX;
	int posY;
};

class Game
{
public:
	//template<Tetromino Tetro>
	Game();
	//Game(Gestor &ges);
	~Game();
	bool stepDown();
	bool rotateTetro();
	bool moveLeft();
	bool moveRight();
	bool fastDown();
	void releaseFastDown();
	Board &getBoard();
	
	float getIntervalo();
	int getScore();
	void restart();
	Tetromino * getPiezaSig();
	void subirNivel();
	bool getEndGame();
	void showEndGame();
	void stop();
	int getNivel();
	//void mostrarTetromino();
	
	//TetrominoI pieza;

private:
	int score, fullLines, nivel, last;
	bool endGame,acelerado;
	float intervalo, lastIntervalo;
	Board tablero;
	Tetromino *tetroI;
	Tetromino *tetroJ;
	Tetromino *tetroL;
	Tetromino *tetroO;
	Tetromino *tetroS;
	Tetromino *tetroT;
	Tetromino *tetroZ;
	struct Piezas pieza;
	struct Piezas piezaSig;
	//Board *tablero;
	void generatePieces();
	

};

