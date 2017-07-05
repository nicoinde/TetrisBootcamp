#include "Game.h"
#include <random>
#include <iostream>
#include <chrono>
#include <thread>

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


bool Game::tick(sf::Event event, sf::) {

	// se que deberia trabajar con un metodo gestor.getVentana() 
	//en vez de acceder directamente a la ventana, pero esto es para probar la funcionalidad nomas
	
		while (ventana.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				ventana.close();
			}

			if (event.type==sf::Event::EventType::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::Q: ventana.close();
					break;
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
		}
		if (clock.getElapsedTime().asSeconds() > intervalo) {
			stepDown();
		}
		ventana.clear(sf::Color::White);
		ventana.draw(gestor.bgSpr);
		makeTableroPrueba();
		gestor.drawPieces(ventana, tableroPrueba);
		gestor.trySprites(ventana);
		ventana.display();
		//system.sleep(1/60);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	return !endGame;
}


bool Game::stepDown() {
	bool aux=true;//=tablero.moveDown(pieza.pieza.getPosicion(), pieza.posX, pieza.posY);
	//aun no decido si bajar aca la pieza y utilizar board.asentar o usar board.boveDown con referencia
	return aux;
}

bool Game::fastDown() {
	intervalo /= 4;
	return true;
}

bool Game::moveLeft() {
	if (pieza.posX>=0) {
		pieza.posX--;
	}
	else {
		return false;
	}
	return true;
}
bool Game::moveRight() {
	if (pieza.posX<20) {
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
		piezaSig.pieza= &tetros[0]; break;
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
			tableroPrueba[i][j] = randomPiezas(randomPieces)+1;

		}
	}
}