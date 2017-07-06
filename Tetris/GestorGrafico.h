#pragma once
#include "SFML\Graphics.hpp"
#include "Board.h"

class GestorGrafico
{
public:
	GestorGrafico();
	~GestorGrafico();
	
	void trySprites(sf::RenderWindow &vent);
	bool cargarImagenes();
	sf::Event &getEvent();
	sf::RenderWindow * getVentana();
	//void setVentana(sf::RenderWindow &vent);
	sf::Clock getClock();
	void drawPieces(Board &tablero);
	void drawBg();
	void drawScore(int score);
	

private:
	
	float offsetX = 5.0;
	float offsetY = 5.0;
	float squareOffset = 30.0;
	sf::RenderWindow * ventana;
	sf::Event event;
	sf::Texture bgTex, iTex, jTex, lTex, oTex, sTex, tTex, zTex;
	sf::Sprite bgSpr, iSpr, jSpr, lSpr, oSpr, sSpr, tSpr, zSpr;
	sf::Clock clock;
	sf::Font font;
	sf::Text score;
	
};

