#include "Game.h"
#include <random>
#include <iostream>
#include <string.h>


using namespace std;

uniform_int_distribution<int> randomPiezas(0, 6);
random_device rd;
mt19937 randomPieces(rd());

const unsigned short posInicialY = 0;
const unsigned short posInicialX = 3;



Game::Game() :score(0),
	fullLines(0), 
	level(1), last(0), 
	endGame(false), 
	acelerated(false), 
	interval(1.0), 
	lastInterval(1.0),
	tetroI(new TetrominoI),
	tetroJ(new TetrominoJ),
	tetroL(new TetrominoL),
	tetroO(new TetrominoO),
	tetroS(new TetrominoS),
	tetroT(new TetrominoT),
	tetroZ(new TetrominoZ)
{
	nextPiece.piece = tetroI;
	generatePieces();
	generatePieces();
}

Game::~Game()
{
	//delete piece.piece;
	//delete nextPiece.piece;
	//delete tetroI;
	//delete tetroJ;
	//delete tetroL;
	//delete tetroO;
	//delete tetroS;
	//delete tetroT;
	//delete tetroZ;
}

void Game::releaseFastDown(){
	interval = lastInterval;
	acelerated = false;
}


bool Game::stepDown() {
	int lines = 0;
	tablero.clearTetromino(piece.piece, piece.posX, piece.posY);
	/*cout << "despues del clear" << endl;
	tablero.mostrar();*/
	if (!tablero.collision(piece.piece, piece.posX, piece.posY + 1)) {
		//tablero.clearTetromino(piece.piece, piece.posX, piece.posY);
		tablero.settle(piece.piece, piece.posX, piece.posY + 1);
		/*cout << "despues del settle sin colision" << endl;
		tablero.mostrar();*/
		piece.posY++;
	}
	else
	{
		tablero.settle(piece.piece, piece.posX, piece.posY);
		/*cout << "despues del settle con colision" << endl;
		tablero.mostrar();*/
		lines = tablero.checkFullLines(piece.posY);
		if (lines > 0) {
			score += lines * 10;

			if (fullLines / 10 != (fullLines + lines) / 10) {
				levelUp();
			}
			fullLines += lines;

		}
		generatePieces();
		if (tablero.collision(piece.piece, piece.posX, piece.posY)) {
			endGame = true;
		}
		/*cout << "antes" << endl;
		tablero.mostrar();*/
		tablero.settle(piece.piece, piece.posX, piece.posY);
		/*cout << "despues" << endl;
		tablero.mostrar();*/
	}
	return !endGame;
}

void Game::levelUp() {
	++level;
	releaseFastDown();
	float aumento = 0;
	if (interval>1.5f) {
		aumento = 0.25f;
	}
	else if (interval<=1.5f&&interval>0.5f) {
		aumento = 0.10f;
	}
	else if (interval<=0.5f&&interval>0.2f) {
		aumento = 0.05f;
	}
	else if((interval<=0.2f)){
		aumento = 0;
	}
	interval -= aumento;
	lastInterval = interval;

}

bool Game::getEndGame()
{
	return endGame;
}

void Game::showEndGame() // mensaje interno para ver si anda el corte
{
	cout << "Hay EndGame==TRUE!!!"<<endl;
}

void Game::stop() // esto es solo para pausar la ejecucion 
{
	char nombre =0;
	cout << "Su Puntaje es de: " << score << endl;
	cout << "Restart?(Y/N): ";
	cin >> nombre;
	cout << endl;
	if (nombre =='y') {
		restart();
	}
	endGame = false;
}

int Game::getLevel()
{
	return level;
}

bool Game::fastDown() {
	if (!acelerated) {
		interval /= 10;
		acelerated = true;

	}
	return true;
}

Board &Game::getBoard()
{
	return tablero;
}

float Game::getInterval()
{
	return interval;
}

int Game::getScore()
{
	return score;
}

void Game::restart()
{
	tablero.restart();
	score = 0;
	level = 1;
	generatePieces();
}

Tetromino * Game::getNextPiece()
{
	nextPiece.piece->setRotation(1);
	return nextPiece.piece;
}

bool Game::moveLeft() {
	if (piece.posX >= tablero.getSoftLeftBorder()) {
		tablero.clearTetromino(piece.piece, piece.posX, piece.posY);
		/*cout << "despues del clear" << endl;
		tablero.mostrar();*/
		if (!tablero.collision(piece.piece, piece.posX - 1, piece.posY)) {
			//tablero.clearTetromino(piece.piece, piece.posX, piece.posY);
			piece.posX--;
			tablero.settle(piece.piece, piece.posX, piece.posY);
			/*cout << "despues del settle sin colision" << endl;
			tablero.mostrar();*/
		}
		else {
			tablero.settle(piece.piece, piece.posX, piece.posY);
			/*cout << "despues del settle con colision" << endl;
			tablero.mostrar();*/
			return false;
		}
	}
	else {

		return false;
	}
	return true;
}


bool Game::moveRight() {
	if (piece.posX < tablero.getSoftRightBorder()) {
		tablero.clearTetromino(piece.piece, piece.posX, piece.posY);
		/*cout << "despues del clear" << endl;
		tablero.mostrar();*/
		if (!tablero.collision(piece.piece, piece.posX + 1, piece.posY)) {
			//tablero.clearTetromino(piece.piece, piece.posX, piece.posY);
			piece.posX++;
			tablero.settle(piece.piece, piece.posX, piece.posY);
			/*cout << "despues del settle sin colision" << endl;
			tablero.mostrar();*/
		}
		else {
			tablero.settle(piece.piece, piece.posX, piece.posY);
			/*cout << "despues del settle con colision" << endl;
			tablero.mostrar();*/
			return false;
		}
	}
	else {
		return false;
	}
	return true;
}


bool Game::rotateTetro() {
	tablero.clearTetromino(piece.piece, piece.posX, piece.posY);
	piece.piece->rotate();
	if (!tablero.collision(piece.piece, piece.posX, piece.posY)) {
		//cout << "settle sin colision" << endl;
		tablero.settle(piece.piece, piece.posX, piece.posY);
		//tablero.mostrar();
	}
	else {
		piece.piece->rotateInversed();
		tablero.settle(piece.piece, piece.posX, piece.posY);
		//cout << "settle con colision" << endl;
		//tablero.mostrar();
		return false;
	}
	return true;

}


void Game::generatePieces() {
	piece.piece = nextPiece.piece;
	piece.posX = posInicialX;
	piece.posY = posInicialY;
	int aux = randomPiezas(randomPieces);
	//este pedazo de codigo es provisional hasta que descubra como arreglar el problema que surge a veces cuando sale la mismapieza varias veces seguidas
	if (aux == last) {
		while (aux == last) {
			aux = randomPiezas(randomPieces);
		}
	}
	last = aux;
	switch (aux)
	{
	case 0:
		nextPiece.piece = tetroI; break;
	case 1:
		nextPiece.piece = tetroJ; break;
	case 2:
		nextPiece.piece = tetroL; break;
	case 3:
		nextPiece.piece = tetroO; break;
	case 4:
		nextPiece.piece = tetroS; break;
	case 5:
		nextPiece.piece = tetroT; break;
	case 6:
		nextPiece.piece = tetroZ; break;
	default:
		break;
	}
	piece.piece->resetRotation();
	nextPiece.piece->resetRotation();

}
