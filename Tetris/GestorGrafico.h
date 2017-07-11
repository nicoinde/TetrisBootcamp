#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Board.h"

class GestorGrafico
{
public:
	GestorGrafico();
	~GestorGrafico();
	sf::Event event;
	void trySprites(sf::RenderWindow &vent);
	void playMusic();
	void stopMusic();
	void pauseMusic();
	sf::Event &getEvent();
	sf::RenderWindow * getVentana();
	//void setVentana(sf::RenderWindow &vent);
	sf::Clock getClock();
	void drawPieces(Board &tablero);
	void drawBg();
	void drawScore(int score, int nivel);
	void drawPiezaSig(Tetromino *piezaSig);
	

private:
	bool cargarArchivos();
	float offsetX = 5.0;
	float offsetY = 5.0;
	float squareOffset = 30.0;
	sf::RenderWindow * ventana;
	sf::Texture bgTex, iTex, jTex, lTex, oTex, sTex, tTex, zTex;
	sf::Sprite bgSpr, iSpr, jSpr, lSpr, oSpr, sSpr, tSpr, zSpr;
	sf::Clock clock;
	sf::Font font;
	sf::Text puntaje;
	sf::Text nivel;
	sf::Music tetrisSong;
	
};

