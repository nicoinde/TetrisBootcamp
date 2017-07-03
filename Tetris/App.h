#pragma once
#include "Gestor.h"
#include "Game.h"
class App
{
public:
	App();
	~App();
	int main();
private:
	Gestor ges;
	Game juego;
};

