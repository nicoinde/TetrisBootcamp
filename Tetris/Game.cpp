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
	interval(1.7), 
	lastInterval(1.7),
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

//this method handles the timed movement DOWN, and if there any collision it calls updateScore and generatePieces functions making a new piece to start moving
bool Game::stepDown() {
	
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
		updateScore();
		updateScore();//sometimes just one call fails to get all.. this is something I must change ASAP
		generatePieces();
		if (tablero.collision(piece.piece, piece.posX, piece.posY)) {
			endGame = true;
		}
		tablero.settle(piece.piece, piece.posX, piece.posY);
	}
	return !endGame;
}

void Game::updateScore()
{
	int lines = 0;
	lines = tablero.checkFullLines(piece.posY);
	if (lines > 0) {
		score += lines * 10;

		if (fullLines / 10 != (fullLines + lines) / 10) {
			levelUp();
		}
		fullLines += lines;

	}
}

//handles the interval increase amount
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
	else if (interval<=0.5f&&interval>0.15f) {
		aumento = 0.05f;
	}
	else if((interval<=0.15f&&interval>0.03f)){
		aumento = 0.01;
	}
	else {
		aumento = 0;
	}

	interval -= aumento;
	lastInterval = interval;

}

bool Game::getEndGame()
{
	return endGame;
}
bool Game::restartGame() // this stops the loop when endGame==true, and allow to restart the game
{
	char answer =0;
	cout << "Su Puntaje es de: " << score << endl;
	cout << "Restart?(Y/N): ";
	cin >> answer;
	cout << endl;
	if (answer =='y'|| answer == 'Y'|| answer == 'R'|| answer == 'r') {
		restart();
		return true;
	}
	else {
		return false;
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
	endGame = false;
	score = 0;
	level = 1;
	generatePieces();
	interval = 1.7f;
	lastInterval = 1.7f;
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
