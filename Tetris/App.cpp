#include "App.h"





App::App()
{
}
int App::ejecucion() {
	juego.iniciar();
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
