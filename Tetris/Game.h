#pragma once
#include "Gestor.h"
class Game
{
public:
	Game();
	//Game(Gestor &ges);
	~Game();
	int iniciar();
	bool ciclo();
	bool stepDown();
	bool girarTetromino();

private:
	Gestor gestor;
	bool endGame;
	float intervalo;
};

