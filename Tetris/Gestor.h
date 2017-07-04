#pragma once
#include "SFML\Graphics.hpp"

class Gestor
{
public:
	Gestor();
	~Gestor();
	sf::RenderWindow ventana;
	bool cargarImagenes();
	sf::Event getEvent();
	//sf::RenderWindow getVentana();
	void setVentana(sf::RenderWindow vent);
	bool openWindow();
	sf::Sprite bg, i, j, l, o, s, t, z;
	sf::Clock clock;
	//sf::RenderWindow *ventana;
	//void drawTablero(int tablero[22][13]);
	//void drawAll(int** tablero, Tetromino pieza);

private:
	

	sf::Event event;
	sf::Texture bgTex, iTex, jTex, lTex, oTex, sTex, tTex, zTex;
	
};

