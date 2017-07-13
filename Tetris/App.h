#pragma once
#include "Game.h"
class App
{
public:
	App();
	~App();
	int loop();
	void draw();
private:
	
	bool modified;
	GestorGrafico ges;
	Game juego;
	
};

