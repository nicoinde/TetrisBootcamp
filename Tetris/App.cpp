#include "App.h"
#include <chrono>
#include <thread>





App::App()
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
	sf::Event event(ges.getEvent());
	while (ges.getVentana()->isOpen()) {
		while (ges.getVentana()->pollEvent(event)) {
			modified = true;
			if (event.type == sf::Event::EventType::Closed) {
				ges.getVentana()->close();
			}
			juego.tick(event, ges.getClock());
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
			ges.drawScore(juego.getScore());
			ges.getVentana()->display();
			modified = false;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

	}
	return 0;
}