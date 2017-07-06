#include "App.h"
#include <chrono>
#include <thread>





App::App()
{
}
int App::ejecucion() {
	juego.tick();
	return 0;
}

int main(int argc, char** args) {
	App app;
	app.ejecucion();
	return 0;
}

App::~App()
{
}

int App::loop() {
	while (ges.getVentana()->isOpen()) {
		while (ges.getVentana()->pollEvent(ges.getEvent())) {
			modified = true;
			if (ges.getEvent().type == sf::Event::EventType::Closed) {
				ges.getVentana()->close();
			}
			juego.tick(ges.getEvent(), ges.getClock());
		}
		if (ges.getClock().getElapsedTime().asSeconds() > juego.getIntervalo()) {
			juego.stepDown();

		ges.drawPieces(juego.getBoard());
	}

}