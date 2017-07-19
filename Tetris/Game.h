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
	Tetromino *piece;
	int posX;
	int posY;
};

class Game
{
public:
	Game();
	~Game();
	bool stepDown();
	void updateScore();
	bool rotateTetro();
	bool moveLeft();
	bool moveRight();
	bool fastDown();
	void releaseFastDown();
	Board &getBoard();	
	float getInterval();
	int getScore();
	void restart();
	Tetromino * getNextPiece();
	void levelUp();
	bool getEndGame();
	bool restartGame();
	int getLevel();
private:
	int score, fullLines, level, last;
	bool endGame,accelerated;
	float interval, lastInterval;
	Board tablero;
	Tetromino *tetroI;
	Tetromino *tetroJ;
	Tetromino *tetroL;
	Tetromino *tetroO;
	Tetromino *tetroS;
	Tetromino *tetroT;
	Tetromino *tetroZ;
	struct Piezas piece;
	struct Piezas nextPiece;
	//Board *tablero;
	void generatePieces();
	

};

