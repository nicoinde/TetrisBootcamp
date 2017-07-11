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



Game::Game() :score(0), lineasCompletas(0), nivel(1),last(0), endGame(false), acelerado(false), intervalo(10.0), lastIntervalo(10.0), tetroI(new TetrominoI), tetroJ(new TetrominoJ), tetroL(new TetrominoL), tetroO(new TetrominoO), tetroS(new TetrominoS), tetroT(new TetrominoT), tetroZ(new TetrominoZ)
{
	piezaSig.pieza = tetroL;
	generarPieza();
}

Game::~Game()
{
}

void Game::releaseFastDown(){
	intervalo = lastIntervalo;
	acelerado = false;
}


bool Game::stepDown() {
	int lineas = 0;
	tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
	/*cout << "despues del clear" << endl;
	tablero.mostrar();*/
	if (!tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY + 1)) {
		//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY + 1);
		/*cout << "despues del asentar sin colision" << endl;
		tablero.mostrar();*/
		pieza.posY++;
	}
	else
	{
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
		/*cout << "despues del asentar con colision" << endl;
		tablero.mostrar();*/
		lineas = tablero.verificarLineasCompletas();
		if (lineas > 0) {
			score += lineas * 10;

			if (lineasCompletas / 10 != (lineasCompletas + lineas) / 10) {
				subirNivel();
			}
			lineasCompletas += lineas;

		}
		generarPieza();
		if (tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY)) {
			endGame = true;
		}
		/*cout << "antes" << endl;
		tablero.mostrar();*/
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
		/*cout << "despues" << endl;
		tablero.mostrar();*/
	}
	return !endGame;
}

void Game::subirNivel() {
	++nivel;
	lastIntervalo = intervalo;
	intervalo -= 0.25f;
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

Board* Game::getBoard()
{
	return &tablero;
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
	generarPieza();
}

Tetromino * Game::getPiezaSig()
{
	piezaSig.pieza->setRotacion(1);
	return piezaSig.pieza;
}

bool Game::moveLeft() {
	if (pieza.posX >= tablero.softLeftBorder) {
		tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
		/*cout << "despues del clear" << endl;
		tablero.mostrar();*/
		if (!tablero.hayColision(pieza.pieza, pieza.posX - 1, pieza.posY)) {
			//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
			pieza.posX--;
			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
			/*cout << "despues del asentar sin colision" << endl;
			tablero.mostrar();*/
		}
		else {
			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
			/*cout << "despues del asentar con colision" << endl;
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
		if (!tablero.hayColision(pieza.pieza, pieza.posX + 1, pieza.posY)) {
			//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
			pieza.posX++;
			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
			/*cout << "despues del asentar sin colision" << endl;
			tablero.mostrar();*/
		}
		else {
			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
			/*cout << "despues del asentar con colision" << endl;
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
	pieza.pieza->rotar();
	if (!tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY)) {
		//cout << "asentar sin colision" << endl;
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
		//tablero.mostrar();
	}
	else {
		pieza.pieza->rotarInverso();
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
		//cout << "asentar con colision" << endl;
		//tablero.mostrar();
		return false;
	}
	return true;

}


void Game::generarPieza() {
	pieza.pieza = piezaSig.pieza;
	pieza.posX = posInicialX;
	pieza.posY = posInicialY;
	int aux = randomPiezas(randomPieces);
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
	pieza.pieza->resetRotacion();
	piezaSig.pieza->resetRotacion();

}
