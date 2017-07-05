#pragma once
#include "Gestor.h"
#include "Game.h"
class App
{
public:
	App();
	~App();
	int ejecucion();
private:
	Gestor ges;
	Game juego;
};

