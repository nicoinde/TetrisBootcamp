#include "App.h"





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
			juego.tick(ges.getEvent(), ges.getClock());
		}
		ges.drawPieces(juego.getBoard());
	}

}