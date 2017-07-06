#include "Game.h"
#include <random>
#include <iostream>


using namespace std;

uniform_int_distribution<int> randomPiezas(0, 6);
random_device rd;
mt19937 randomPieces(rd());

const unsigned short posInicialY = 9;
const unsigned short posInicialX = 0;


Game::Game()
{
	endGame = false;
	intervalo = 0.5;
	tableroPrueba = nullptr;
	makeTableroPrueba();
	/*gestor.setVentana(&ventana);*/
	//pieza=generarPieza();
}

Game::~Game()
{
}

void Game::cargarTetrominos()
{
	tetroI = new TetrominoI();
}


bool Game::tick(sf::Event &event, sf::Clock &clock) {
	handleInput(event);


}



bool Game::handleInput(sf::Event &event)
{
	if (event.type == sf::Event::EventType::KeyPressed) {
		switch (event.key.code) {
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
	return true;
}


bool Game::stepDown() {
	bool aux = true;//=tablero.moveDown(pieza.pieza.getPosicion(), pieza.posX, pieza.posY);
	//aun no decido si bajar aca la pieza y utilizar board.asentar o usar board.boveDown con referencia
	return aux;
}

bool Game::fastDown() {
	intervalo /= 4;
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

bool Game::moveLeft() {
	if (pieza.posX >= 0) {
		pieza.posX--;
	}
	else {
		return false;
	}
	return true;
}
bool Game::moveRight() {
	if (pieza.posX < 20) {
		pieza.posX++;
	}
	else {
		return false;
	}
	return true;
}
bool Game::rotateTetro() {
	//pieza.pieza.rotar();
	return true;
}



void Game::generarPieza() {
	pieza = piezaSig;
	int aux = randomPiezas(randomPieces);
	switch (aux)
	{
	case 0:
		piezaSig.pieza = &tetros[0]; break;
	case 1:
		piezaSig.pieza = &tetros[1]; break;
	case 2:
		piezaSig.pieza = &tetros[2]; break;
	case 3:
		piezaSig.pieza = &tetros[3]; break;
	case 4:
		piezaSig.pieza = &tetros[4]; break;
	case 5:
		piezaSig.pieza = &tetros[5]; break;
	case 6:
		piezaSig.pieza = &tetros[6]; break;
	default:
		break;
	}
	piezaSig.posX = posInicialX;
	piezaSig.posY = posInicialY;
}

void Game::makeTableroPrueba() {
	tableroPrueba = new int*[10];
	for (short i = 0; i < 10; ++i)
	{
		tableroPrueba[i] = new int[20];
		for (short j = 0; j < 20; ++j)
		{
			tableroPrueba[i][j] = randomPiezas(randomPieces) + 1;

		}
	}
}