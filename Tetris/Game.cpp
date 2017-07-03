#include "Game.h"



Game::Game()
{
	endGame = false;
	intervalo = 0.5;
}

Game::~Game()
{
}

int Game::iniciar() {
	gestor.cargarImagenes();
	ciclo();
	return 0;
}

bool Game::ciclo() {
	sf::Event event;
	sf::Clock clock;
	while (gestor.ventana.isOpen()) {
		while (gestor.ventana.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed) {
				gestor.ventana.close();
			}

			if (event.type==sf::Event::EventType::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::Q: gestor.ventana.close();
					break;
				}
			}
		}
		if (clock.getElapsedTime().asSeconds() > intervalo) {
			stepDown();
		}
		gestor.ventana.clear();
		gestor.ventana.draw(gestor.bg);
		gestor.ventana.display();
	}
	return !endGame;
}

bool Game::stepDown() {
	return true;
}