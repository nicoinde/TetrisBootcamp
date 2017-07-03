#include "App.h"




App::App()
{
}
int App::main() {
	juego.iniciar();
	return 0;
}

int main(int argc, char** args) {
	App app;
	app.main();
	return 0;
}

App::~App()
{
}
