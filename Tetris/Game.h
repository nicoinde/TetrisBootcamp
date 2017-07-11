#pragma once
#include "GestorGrafico.h"
#include "TetrominoEsp.h"
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
	Board* getBoard();
	Board tablero;
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
	int score, lineasCompletas, nivel, last;
	bool endGame,acelerado;
	float intervalo, lastIntervalo;
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
	void generarPieza();
	

};

