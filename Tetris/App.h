#pragma once
#include "Game.h"
class App
{
public:
	App();
	~App();
	int ejecucion();
	int loop();
private:
	GestorGrafico ges;
	Game juego;
};

