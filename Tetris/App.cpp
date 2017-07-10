#include "App.h"
#include <chrono>
#include <thread>





App::App() :modified(true)
{
}


int main(int argc, char** argv) {
	App app;
	app.loop();
	return 0;
}

App::~App()
{
}

int App::loop() {
	sf::Clock clock;
	clock.restart();
	//juego.stepDown2();
	//juego.tablero.mostrar();
	ges.drawBg();
	ges.drawPieces(juego.tablero);
	ges.getVentana()->display();
	while (ges.getVentana()->isOpen()) {
		while (ges.getVentana()->pollEvent(ges.event)) {
			modified = true;
			if (ges.event.type == sf::Event::EventType::Closed) {
				ges.getVentana()->close();
			}

			if (ges.event.type == sf::Event::EventType::KeyPressed) {
				//juego.tick(ges.getEvent().key.code);
				switch (ges.event.key.code) {
				case sf::Keyboard::A:
				case sf::Keyboard::Left:
					juego.moveLeft();
					juego.tablero.mostrar();
					break;
				case sf::Keyboard::W:
				case sf::Keyboard::Up:
					juego.rotateTetro();
					juego.tablero.mostrar();
					break;
				case sf::Keyboard::D:
				case sf::Keyboard::Right:
					juego.moveRight();
					juego.tablero.mostrar();
					break;
				case sf::Keyboard::S:
				case sf::Keyboard::Down:
					juego.fastDown();
					break;
					//case sf::Keyboard::X:
					//	juego.mostrarTetromino();
					//	break;

				case sf::Keyboard::B:
					juego.stepDown();
					juego.tablero.mostrar();
					break;
				case sf::Keyboard::R:
					ges.getVentana()->clear();
					ges.drawBg();
					ges.drawPieces(juego.tablero);
					ges.getVentana()->display();
					break;
				default:break;
				}
			}
			if (ges.event.type == sf::Event::EventType::KeyReleased) {
				if (ges.event.key.code == sf::Keyboard::S) {
					juego.releaseFastDown();
				}
			}

			if (clock.getElapsedTime().asSeconds() > juego.getIntervalo()) {
				//juego.stepDown2();
				juego.stepDown();
				/*juego.tablero.mostrar();*/
				clock.restart();
			}

			//if (modified) {
			ges.getVentana()->clear();
			ges.drawBg();


			ges.drawPieces(juego.tablero);
			//ges.drawScore(juego.getScore());
			//ges.drawPiezaSig(juego.getPiezaSig());
			ges.getVentana()->display();
			/*	modified = false;
			}*/
			//std::this_thread::sleep_for(std::chrono::milliseconds(100));

		}
		//if (ges.getClock().getElapsedTime().asSeconds() > juego.getIntervalo()) {
		//	juego.stepDown();
		//	//juego.stepDown2();
		//	ges.getClock().restart();
		//}

		//if (modified) {
		//	ges.getVentana()->clear(sf::Color::White);
		//	ges.drawBg();
		//	//makeTableroPrueba();
		//	//gestor.drawPieces(ventana, tableroPrueba);
		//	//gestor.trySprites(ventana);

		//	//system.sleep(1/60);

		//	ges.drawPieces(juego.tablero);
		//	//ges.drawScore(juego.getScore());
		//	//ges.drawPiezaSig(juego.getPiezaSig());
		//	ges.getVentana()->display();
		//	modified = false;
		//}
		//std::this_thread::sleep_for(std::chrono::milliseconds(100));


	}
	return 0;
}