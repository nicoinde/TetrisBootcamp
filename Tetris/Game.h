#pragma once
#include "GestorGrafico.h"
#include "Tetromino.h"
struct Piezas {
	Tetromino *pieza;
	float posX;
	float posY;
};

class Game
{
public:
	//template<Tetromino Tetro>
	Game();
	//Game(Gestor &ges);
	~Game();
	void cargarTetrominos();
	bool tick(sf::Event &event, sf::Clock &clock);
	bool handleInput(sf::Event &event);
	bool stepDown();
	bool rotateTetro();
	bool moveLeft();
	bool moveRight();
	bool fastDown();
	Board* getBoard();
	Board tablero;
	float getIntervalo();
	int getScore();
	
	//TetrominoI pieza;

private:
	
	bool endGame;
	float intervalo;
	int score;
	//int** tableroPrueba;
	
	Tetromino * tetroI, * tetroJ, * tetroL, * tetroO, * tetroS, * tetroT, * tetroZ;	
	struct Piezas pieza;
	struct Piezas piezaSig;
	//Board *tablero;
	void generarPieza();
	void makeTableroPrueba();
};

