#include "Game.h"
#include <random>
#include <iostream>


using namespace std;

uniform_int_distribution<int> randomPiezas(0, 6);
random_device rd;
mt19937 randomPieces(rd());

const unsigned short posInicialY = 1;
const unsigned short posInicialX = 3;



Game::Game() :score(0), lineasCompletas(0), nivel(1), endGame(false), acelerado(false), intervalo(8.0), lastIntervalo(intervalo), tetroI(new TetrominoI), tetroJ(new TetrominoJ), tetroL(new TetrominoL), tetroO(new TetrominoO), tetroS(new TetrominoS), tetroT(new TetrominoT), tetroZ(new TetrominoZ)
{
	piezaSig.pieza = tetroL;
	generarPieza();
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


//bool Game::stepDown() {
//	int lineas = 0;
//	if (!tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY + 1)) {
//		tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
//		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY + 1);
//		pieza.posY++;
//		cout<<"stepdown succesfull"<<endl;
//	}
//	else
//	{
//		cout << "stepdown unsuccesfull" << endl;
//		lineas = tablero.verificarLineasCompletas();
//		if (lineas > 0) {
//			score += lineas * 10;
//
//			if (lineasCompletas / 10 != (lineasCompletas + lineas) / 10) {
//				subirNivel();
//			}
//			lineasCompletas += lineas;
//
//		}
//		generarPieza();
//		if (tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY)) {
//			endGame = true;
//			cout << "fin del juego" << endl;
//		}
//		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
//
//	}
//	return !endGame;
//}

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
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);

	}
	return !endGame;
}

void Game::subirNivel() {
	++nivel;
	lastIntervalo = intervalo;
	intervalo += 0.05f;
}

bool Game::getEndGame()
{
	return endGame;
}

void Game::showEndGame()
{
	cout << "Hay EndGame==TRUE!!!"<<endl;
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

//bool Game::moveLeft() {
//	if (pieza.posX >= tablero.softLeftBorder) {
//		tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
//		if (!tablero.hayColision(pieza.pieza, pieza.posX - 1, pieza.posY)) {
//			//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
//			pieza.posX--;			
//			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
//		}
//		else {
//			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
//			return false;
//		}
//	}
//	else {
//		
//		return false;
//	}
//	return true;
//}

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

//bool Game::moveRight() {
//	if (pieza.posX < tablero.softRightBorder) {
//		tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
//		cout << "despues del clear" << endl;
//		tablero.mostrar();
//		if (!tablero.hayColision(pieza.pieza, pieza.posX + 1, pieza.posY)) {
//			//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
//			pieza.posX++;
//			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
//		}
//		else {
//			tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
//			return false;
//		}
//	}
//	else {
//		return false;
//	}
//	return true;
//}

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
//bool Game::rotateTetro() {
//	tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
//	pieza.pieza->rotar();
//	if (!tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY)) {
//		//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
//		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
//	}else {
//		pieza.pieza->rotarInverso();
//		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
//	}
//	return true;
//	
//}

bool Game::rotateTetro() {
	tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
	pieza.pieza->rotar();
	if (!tablero.hayColision(pieza.pieza, pieza.posX, pieza.posY)) {
		//tablero.clearTetromino(pieza.pieza, pieza.posX, pieza.posY);
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
	}
	else {
		pieza.pieza->rotarInverso();
		tablero.asentar(pieza.pieza, pieza.posX, pieza.posY);
		return false;
	}
	return true;

}

//void Game::mostrarTetromino() {
//	tetroI->mostrarTetro();
//	tetroI->rotar();
//	tetroI->mostrarTetro();
//	tetroI->rotar();
//	tetroJ->mostrarTetro();
//	tetroJ->rotar();
//	tetroJ->mostrarTetro();
//	tetroJ->rotar();
//	tetroJ->mostrarTetro();
//	tetroJ->rotar();
//	tetroJ->mostrarTetro();
//	tetroJ->rotar();
//	tetroL->mostrarTetro();
//	tetroL->rotar();
//	tetroL->mostrarTetro();
//	tetroL->rotar();
//	tetroL->mostrarTetro();
//	tetroL->rotar();
//	tetroL->mostrarTetro();
//	tetroL->rotar();
//	tetroO->mostrarTetro();
//	tetroO->rotar();
//	tetroS->mostrarTetro();
//	tetroS->rotar();
//	tetroS->mostrarTetro();
//	tetroS->rotar();
//	tetroT->mostrarTetro();
//	tetroT->rotar();
//	tetroT->mostrarTetro();
//	tetroT->rotar();
//	tetroT->mostrarTetro();
//	tetroT->rotar();
//	tetroT->mostrarTetro();
//	tetroT->rotar();
//	tetroZ->mostrarTetro();
//	tetroZ->rotar();
//	tetroZ->mostrarTetro();
//	tetroZ->rotar();
//	
//}


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
