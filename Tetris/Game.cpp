#include "Game.h"
#include <random>
#include <iostream>


using namespace std;

uniform_int_distribution<int> randomPiezas(0, 6);
random_device rd;
mt19937 randomPieces(rd());

const unsigned short posInicialY = 0;
const unsigned short posInicialX = 3;



Game::Game() :score(0), lineasCompletas(0), nivel(1), endGame(false), acelerado(false), intervalo(0.5), lastIntervalo(intervalo), tetroI(new TetrominoI), tetroJ(new TetrominoJ), tetroL(new TetrominoL), tetroO(new TetrominoO), tetroS(new TetrominoS), tetroT(new TetrominoT), tetroZ(new TetrominoZ)
{
	piezaSig.pieza = tetroL;
	generarPieza();
	generarPieza();
	stepDown2();
}

Game::~Game()
{
}



bool Game::tick(sf::Keyboard::Key input) {
	handleInput(input);
	return !endGame;
}





void Game::handleInput(sf::Keyboard::Key input)
{
		switch (input) {
		case sf::Keyboard::A:
		case sf::Keyboard::Left:
			moveLeft();
			break;
		case sf::Keyboard::W:
		case sf::Keyboard::Up:
			rotateTetro();
			break;
		case sf::Keyboard::D:
		case sf::Keyboard::Right:
			moveRight();
			break;
		case sf::Keyboard::S:
		case sf::Keyboard::Down:
			fastDown();
			break;
		default:break;
		}
}

void Game::releaseFastDown(){
	intervalo = lastIntervalo;
	acelerado = false;
}


bool Game::stepDown() {
	int lineas = 0;
	if (!tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY + 1)) {
		tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY + 1);
		pieza.posY++;
		cout<<"stepdown succesfull"<<endl;
	}
	else
	{
		cout << "stepdown unsuccesfull" << endl;
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
			cout << "fin del juego" << endl;
		}
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);

	}
	return !endGame;
}

bool Game::stepDown2() {
	int lineas = 0;
	if (!tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY + 1)) {
		tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY + 1);
		pieza.posY++;
	}
	else
	{
		lineas = tablero.verificarLineasCompletas();
		if (lineas > 0) {
			score += lineas * 10;

			if (lineasCompletas / 10 != (lineasCompletas + lineas) / 10) {
				subirNivel();
			}
			lineasCompletas += lineas;

		}
		/*generarPieza();
		if (tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY)) {
			endGame = true;
		}
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);*/

	}
	return !endGame;
}

void Game::subirNivel() {
	++nivel;
	lastIntervalo = intervalo;
	intervalo += 0.05f;
}

bool Game::fastDown() {
	if (!acelerado) {
		intervalo /= 4;
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

Tetromino * Game::getPiezaSig()
{
	return piezaSig.pieza;
}

bool Game::moveLeft() {
	if (pieza.posX >= tablero.softLeftBorder) {
		if (!tablero.hayColision(pieza.pieza, pieza.posX - 1, pieza.posY)) {
			tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
			pieza.posX--;			
			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
		}
	}
	else {
		return false;
	}
	return true;
}
bool Game::moveRight() {
	if (pieza.posX < tablero.softRightBorder) {
		if (!tablero.hayColision(pieza.pieza, pieza.posX + 1, pieza.posY)) {
			tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
			pieza.posX++;
			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
		}
	}
	else {
		return false;
	}
	return true;
}
bool Game::rotateTetro() {
	pieza.pieza->rotar();
	if (!tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY)) {
		tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
	}else {
		pieza.pieza->rotarInverso();
	}
	return true;
	
}



void Game::generarPieza() {
	pieza.pieza = piezaSig.pieza;
	pieza.posX = posInicialX;
	pieza.posY = posInicialY;
	int aux = randomPiezas(randomPieces);
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
