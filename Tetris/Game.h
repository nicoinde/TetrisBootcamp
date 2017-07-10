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
	bool tick(sf::Keyboard::Key input);
	void handleInput(sf::Keyboard::Key input);
	bool stepDown();
	bool stepDown2();
	bool rotateTetro();
	bool moveLeft();
	bool moveRight();
	bool rotateTetro2();
	bool moveLeft2();
	bool moveRight2();
	bool fastDown();
	void releaseFastDown();
	Board* getBoard();
	Board tablero;
	float getIntervalo();
	int getScore();
	Tetromino * getPiezaSig();
	void subirNivel();
	void mostrarTetromino();
	
	//TetrominoI pieza;

private:
	int score, lineasCompletas, nivel;
	bool endGame,acelerado;
	float intervalo, lastIntervalo;
	Tetromino *tetroI;
	Tetromino *tetroJ;
	Tetromino *tetroL;
	Tetromino *tetroO;
	Tetromino *tetroS;
	Tetromino *tetroT;
	Tetromino *tetroZ;
//	Tetromino *prueba;
	struct Piezas pieza;
	struct Piezas piezaSig;
	//Board *tablero;
	void generarPieza();
//	void makeTableroPrueba();
};

