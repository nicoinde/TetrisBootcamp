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
	nivel(1), last(0), 
	endGame(false), 
	acelerado(false), 
	intervalo(1.0), 
	lastIntervalo(1.0),
	tetroI(new TetrominoI),
	tetroJ(new TetrominoJ),
	tetroL(new TetrominoL),
	tetroO(new TetrominoO),
	tetroS(new TetrominoS),
	tetroT(new TetrominoT),
	tetroZ(new TetrominoZ)
{
	piezaSig.pieza = tetroI;
	generatePieces();
	generatePieces();
}

Game::~Game()
{
	//delete pieza.pieza;
	//delete piezaSig.pieza;
	//delete tetroI;
	//delete tetroJ;
	//delete tetroL;
	//delete tetroO;
	//delete tetroS;
	//delete tetroT;
	//delete tetroZ;
}

void Game::releaseFastDown(){
	intervalo = lastIntervalo;
	acelerado = false;
}


bool Game::stepDown() {
	int lines = 0;
	tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
	/*cout << "despues del clear" << endl;
	tablero.mostrar();*/
	if (!tablero.collision(pieza.pieza, pieza.posX, pieza.posY + 1)) {
		//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
		tablero.settle(pieza.pieza, pieza.posX, pieza.posY + 1);
		/*cout << "despues del settle sin colision" << endl;
		tablero.mostrar();*/
		pieza.posY++;
	}
	else
	{
		tablero.settle(pieza.pieza, pieza.posX, pieza.posY);
		/*cout << "despues del settle con colision" << endl;
		tablero.mostrar();*/
		lines = tablero.checkFullLines(pieza.posY);
		if (lines > 0) {
			score += lines * 10;

			if (fullLines / 10 != (fullLines + lines) / 10) {
				subirNivel();
			}
			fullLines += lines;

		}
		generatePieces();
		if (tablero.collision(pieza.pieza, pieza.posX, pieza.posY)) {
			endGame = true;
		}
		/*cout << "antes" << endl;
		tablero.mostrar();*/
		tablero.settle(pieza.pieza, pieza.posX, pieza.posY);
		/*cout << "despues" << endl;
		tablero.mostrar();*/
	}
	return !endGame;
}

void Game::subirNivel() {
	++nivel;
	releaseFastDown();
	float aumento = 0;
	if (intervalo>1.5f) {
		aumento = 0.25f;
	}
	else if (intervalo<=1.5f&&intervalo>0.5f) {
		aumento = 0.10f;
	}
	else if (intervalo<=0.5f&&intervalo>0.2f) {
		aumento = 0.05f;
	}
	else if((intervalo<=0.2f)){
		aumento = 0;
	}
	intervalo -= aumento;
	lastIntervalo = intervalo;

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

int Game::getNivel()
{
	return nivel;
}

bool Game::fastDown() {
	if (!acelerado) {
		intervalo /= 10;
		acelerado = true;

	}
	return true;
}

Board &Game::getBoard()
{
	return tablero;
}

float Game::getIntervalo()
{
	return intervalo;
}

int Game::getScore()
{
	return score;
}

void Game::restart()
{
	tablero.restart();
	score = 0;
	nivel = 1;
	generatePieces();
}

Tetromino * Game::getPiezaSig()
{
	piezaSig.pieza->setRotation(1);
	return piezaSig.pieza;
}

bool Game::moveLeft() {
	if (pieza.posX >= tablero.softLeftBorder) {
		tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
		/*cout << "despues del clear" << endl;
		tablero.mostrar();*/
		if (!tablero.collision(pieza.pieza, pieza.posX - 1, pieza.posY)) {
			//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
			pieza.posX--;
			tablero.settle(pieza.pieza, pieza.posX, pieza.posY);
			/*cout << "despues del settle sin colision" << endl;
			tablero.mostrar();*/
		}
		else {
			tablero.settle(pieza.pieza, pieza.posX, pieza.posY);
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
	if (pieza.posX < tablero.softRightBorder) {
		tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
		/*cout << "despues del clear" << endl;
		tablero.mostrar();*/
		if (!tablero.collision(pieza.pieza, pieza.posX + 1, pieza.posY)) {
			//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
			pieza.posX++;
			tablero.settle(pieza.pieza, pieza.posX, pieza.posY);
			/*cout << "despues del settle sin colision" << endl;
			tablero.mostrar();*/
		}
		else {
			tablero.settle(pieza.pieza, pieza.posX, pieza.posY);
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
	tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
	pieza.pieza->rotate();
	if (!tablero.collision(pieza.pieza, pieza.posX, pieza.posY)) {
		//cout << "settle sin colision" << endl;
		tablero.settle(pieza.pieza, pieza.posX, pieza.posY);
		//tablero.mostrar();
	}
	else {
		pieza.pieza->rotateInversed();
		tablero.settle(pieza.pieza, pieza.posX, pieza.posY);
		//cout << "settle con colision" << endl;
		//tablero.mostrar();
		return false;
	}
	return true;

}


void Game::generatePieces() {
	pieza.pieza = piezaSig.pieza;
	pieza.posX = posInicialX;
	pieza.posY = posInicialY;
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
		piezaSig.pieza = tetroI; break;
	case 1:
		piezaSig.pieza = tetroJ; break;
	case 2:
		piezaSig.pieza = tetroL; break;
	case 3:
		piezaSig.pieza = tetroO; break;
	case 4:
		piezaSig.pieza = tetroS; break;
	case 5:
		piezaSig.pieza = tetroT; break;
	case 6:
		piezaSig.pieza = tetroZ; break;
	default:
		break;
	}
	pieza.pieza->resetRotation();
	piezaSig.pieza->resetRotation();

}
