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
	void cargarTetrominos();
	bool tick(sf::Keyboard::Key input);
	void handleInput(sf::Keyboard::Key input);
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
	Tetromino * getPiezaSig();
	void subirNivel();
	
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
	struct Piezas pieza;
	struct Piezas piezaSig;
	//Board *tablero;
	void generarPieza();
	void makeTableroPrueba();
};

