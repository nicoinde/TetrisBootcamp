#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "Board.h"

class GestorGrafico
{
public:
	GestorGrafico();
	~GestorGrafico();
	void playMusic();
	void stopMusic();
	void pauseMusic();
	sf::Event &getEvent();
	sf::RenderWindow * getWindow();
	sf::Clock &getClock();
	void drawPieces(Board &tablero);
	void drawBg();
	void drawScore(int score, int level);
	void drawNextPiece(Tetromino *nextPiece);
	

private:
	sf::Event event;
	bool loadFiles();
	float offsetX;
	float offsetY;
	float squareOffset = 30.0;
	sf::RenderWindow * window;
	sf::Texture bgTex, iTex, jTex, lTex, oTex, sTex, tTex, zTex;
	sf::Sprite bgSpr, tetroSpr;
	sf::Clock clock;
	sf::Font font;
	sf::Text puntaje;
	sf::Text level;
	sf::Music tetrisSong;
	
};

