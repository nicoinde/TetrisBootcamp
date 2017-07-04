#include "Game.h"
#include <random>
#include <iostream>

using namespace std;

uniform_int_distribution<int> randomPiezas(0, 6);
random_device rd;
mt19937 randomPieces(rd());
sf::RenderWindow ventana(sf::VideoMode(412, 600), "Tetris");


Game::Game()
{
	endGame = false;
	intervalo = 0.5;
	/*gestor.setVentana(&ventana);*/
	//pieza=generarPieza();
}

Game::~Game()
{
}

int Game::iniciar() {
//	gestor.cargarImagenes();
	ciclo();
	return 0;
}

bool Game::ciclo() {
	sf::Event event;
	sf::Clock clock;
	// se que deberia trabajar con un metodo gestor.getVentana() 
	//en vez de acceder directamente a la ventana, pero esto es para probar la funcionalidad nomas
	while (ventana.isOpen()) { 
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
		ventana.draw(gestor.bg);
		drawPieces();
		ventana.display();
	}
	return !endGame;
}

bool Game::drawPieces() {

	return false;
}

bool Game::stepDown() {
	return true;
}

bool Game::fastDown() {
	intervalo /= 4;
	return true;
}

bool Game::moveLeft() {
	return true;
}
bool Game::moveRight() {
	
	return true;
}
bool Game::rotateTetro() {
	//pieza.rotar();
	return true;
}



Tetromino Game::generarPieza() {
	Tetromino tetro;
	int aux = randomPiezas(randomPieces);
	switch (aux)
	{
	case 0: 
		tetro = TetrominoI::TetrominoI(); break;
	case 1:
		tetro = TetrominoJ::TetrominoJ(); break;
	case 2:
		tetro = TetrominoL::TetrominoL(); break;
	case 3:
		tetro = TetrominoO::TetrominoO(); break;
	case 4:
		tetro = TetrominoS::TetrominoS(); break;
	case 5:
		tetro = TetrominoT::TetrominoT(); break;
	case 6:
		tetro = TetrominoZ::TetrominoZ(); break;
	default:
		break;
	}
	
	
	return tetro;
}