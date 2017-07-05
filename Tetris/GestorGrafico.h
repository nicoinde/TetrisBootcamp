#pragma once
#include "SFML\Graphics.hpp"

class GestorGrafico
{
public:
	GestorGrafico();
	~GestorGrafico();
	
	void trySprites(sf::RenderWindow &vent);
	bool cargarImagenes();
	sf::Event getEvent();
	sf::RenderWindow * getVentana();
	void setVentana(sf::RenderWindow &vent);
	sf::Event getEvent();
	sf::Clock getClock();
	void drawPieces(sf::RenderWindow &vent, int** tablero);
	

private:
	
	float offsetX = 5.0;
	float offsetY = 5.0;
	float squareOffset = 30.0;
	sf::RenderWindow * ventana;
	sf::Event event;
	sf::Texture bgTex, iTex, jTex, lTex, oTex, sTex, tTex, zTex;
	sf::Sprite bgSpr, iSpr, jSpr, lSpr, oSpr, sSpr, tSpr, zSpr;
	sf::Clock clock;
	
	
};
