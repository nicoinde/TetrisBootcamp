#include "App.h"
#include <chrono>
#include <thread>





App::App():modified(true)
{
}


int main(int argc, char** args) {
	App app;
	app.loop();
	return 0;
}

App::~App()
{
}

int App::loop() {
	ges.getClock().restart();
	while (ges.getVentana()->isOpen()) {
		while (ges.getVentana()->pollEvent(ges.event)) {
			modified = true;
			if (ges.event.type == sf::Event::EventType::Closed) {
				ges.getVentana()->close();
			}
			
			if (ges.event.type == sf::Event::EventType::KeyPressed) {
				juego.tick(ges.getEvent().key.code);
			}
			if (ges.event.type == sf::Event::EventType::KeyReleased) {
				if (ges.event.key.code == sf::Keyboard::S) {
					juego.releaseFastDown();
				}
			}
			if (ges.getClock().getElapsedTime().asSeconds() > juego.getIntervalo()) {
				juego.stepDown();
				ges.getClock().restart();
			}

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
		if (ges.getClock().getElapsedTime().asSeconds() > juego.getIntervalo()) {
			juego.stepDown();
			ges.getClock().restart();
		}

		if (modified) {
			ges.getVentana()->clear(sf::Color::White);
			ges.drawBg();
			//makeTableroPrueba();
			//gestor.drawPieces(ventana, tableroPrueba);
			//gestor.trySprites(ventana);

			//system.sleep(1/60);

			ges.drawPieces(juego.tablero);
			//ges.drawScore(juego.getScore());
			//ges.drawPiezaSig(juego.getPiezaSig());
			ges.getVentana()->display();
			modified = false;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		

	}
	return 0;
}