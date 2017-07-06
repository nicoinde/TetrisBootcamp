#pragma once
#include "Game.h"
class App
{
public:
	App();
	~App();
	int loop();
private:
	GestorGrafico ges;
	Game juego;
	bool modified;
};

