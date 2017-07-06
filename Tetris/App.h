#pragma once
#include "Game.h"
class App
{
public:
	App();
	~App();
	int loop();
private:
	bool modified;
	GestorGrafico ges;
	Game juego;
	
};

