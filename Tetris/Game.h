#pragma once
#include "GestorGrafico.h"
#include "Tetromino.h"
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
	float getIntervalo();
	
	//TetrominoI pieza;

private:
	
	struct Piezas pieza;
	struct Piezas piezaSig;
	bool endGame;
	float intervalo;
	int** tableroPrueba;
	void makeTableroPrueba();
	Tetromino * tetroI, * tetroJ, * tetroL, * tetroO, * tetroS, * tetroT, * tetroZ;	
	Board tablero;
	void generarPieza();
};

