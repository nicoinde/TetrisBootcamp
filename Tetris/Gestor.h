#pragma once
#include "SFML\Graphics.hpp"

class Gestor
{
public:
	Gestor();
	~Gestor();
	sf::RenderWindow ventana;
	void trySprites(sf::RenderWindow &vent);
	bool cargarImagenes();
	sf::Event getEvent();
	//sf::RenderWindow getVentana();
	void setVentana(sf::RenderWindow vent);
	bool openWindow();
	sf::Sprite bgSpr, iSpr, jSpr, lSpr, oSpr, sSpr, tSpr, zSpr;
	sf::Clock clock;
	void drawPieces(sf::RenderWindow &vent, int** tablero);
	//sf::RenderWindow *ventana;
	//void drawTablero(int tablero[22][13]);
	//void drawAll(int** tablero, Tetromino pieza);

private:
	
	float offsetX = 5.0;
	float offsetY = 5.0;
	float squareOffset = 30.0;
	sf::Event event;
	sf::Texture bgTex, iTex, jTex, lTex, oTex, sTex, tTex, zTex;
	
};

