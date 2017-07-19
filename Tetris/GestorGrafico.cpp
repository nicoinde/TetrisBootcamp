#include "GestorGrafico.h"
#include <iostream>
#include <string.h>
using namespace std;

const float sizeX = 412.0;
const float sizeY = 600.0;
const float piezaSigOffsetX = 312.0;
const float piezaSigOffsetY = 39.0;
const float scoreOffsetX = 312.0;
const float scoreOffsetY = 198.0;
const float levelOffsetX = 312.0;
const float levelOffsetY = 238.0;
const char* title = "Tetris";
const char* dirBg= "Assets/bg.png";
const char* dirI = "Assets/i.png";
const char* dirJ = "Assets/j.png";
const char* dirL = "Assets/l.png";
const char* dirO = "Assets/o.png";
const char* dirS = "Assets/s.png";
const char* dirT = "Assets/t.png";
const char* dirZ = "Assets/z.png";
const char* dirFont = "Assets/Coffee House.ttf";
const char* dirMusic = "Assets/Tetris.ogg";


GestorGrafico::GestorGrafico() : offsetX(-19.0), offsetY(-48), squareOffset(29.0)
{
	window = new sf::RenderWindow(sf::VideoMode(sizeX, sizeY), title);
	loadFiles();
}


GestorGrafico::~GestorGrafico()
{
	//delete window;
}

bool GestorGrafico::loadFiles() {
	if (!bgTex.loadFromFile(dirBg)) {
		cout << "No se pudo cargar " << dirBg<< endl;
		window->close();
		return false;
	}
	else {
		bgSpr.setTexture(bgTex);
		bgSpr.setPosition(0.0f, 0.0f);
	}
	tetroSpr.setScale(1.04f, 1.04f);
	if (!iTex.loadFromFile(dirI)) {
		cout << "No se pudo cargar " << dirI << endl;
		window->close();
		return false;
	}
	if (!jTex.loadFromFile("Assets/j.png")) {
		cout << "No se pudo cargar " << dirJ << endl;
		window->close();
		return false;
	}
	if (!lTex.loadFromFile("Assets/l.png")) {
		cout << "No se pudo cargar " << dirL << endl;
		window->close();
		return false;
	}
	if (!oTex.loadFromFile("Assets/o.png")) {
		cout << "No se pudo cargar " << dirO << endl;
		window->close();
		return false;
	}
	if (!sTex.loadFromFile("Assets/s.png")) {
		cout << "No se pudo cargar " << dirS << endl;
		window->close();
		return false;
	}
	if (!tTex.loadFromFile("Assets/t.png")) {
		cout << "No se pudo cargar " << dirT << endl;
		window->close();
		return false;
	}
	if (!zTex.loadFromFile("Assets/z.png")) {
		cout << "No se pudo cargar " << dirZ << endl;
		window->close();
		return false;
	}

	if (!font.loadFromFile(dirFont)) {
		cout << "No se pudo cargar la fuente" << dirFont << endl;
		window->close();
		return false;
	}
	else {
		puntaje.setFont(font);
		puntaje.setPosition(scoreOffsetX, scoreOffsetY);
		/*puntaje.setCharacterSize(25);*/
		puntaje.setFillColor(sf::Color::White);
		puntaje.setColor(sf::Color::Blue);

		level.setFont(font);
		level.setPosition(levelOffsetX, levelOffsetY);
		level.setFillColor(sf::Color::White);
		level.setColor(sf::Color::Blue);
	}

	
	

	if (!tetrisSong.openFromFile(dirMusic)) {
		cout << "No se pudo cargar " << dirMusic << endl;
		window->close();
		return false;
	}
	else
	{
		tetrisSong.setLoop(true);
		tetrisSong.setVolume(50);

	}

	return true;
}

sf::Event &GestorGrafico::getEvent()
{
	return event;
}

sf::Clock &GestorGrafico::getClock()
{
	return clock;
}

void GestorGrafico::drawPieces(Board &tablero)
{
	for (int i = tablero.getSoftUpperBorder(); i < tablero.getSoftBottomBorder(); ++i)
	{
		for (int j = tablero.getSoftLeftBorder(); j < tablero.getSoftRightBorder(); ++j) {
			int aux = tablero.getCell(j, i);
			switch (aux)
			{
			case 1:
				tetroSpr.setTexture(iTex);
				tetroSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 2:
				tetroSpr.setTexture(jTex);
				tetroSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 3:
				tetroSpr.setTexture(lTex);
				tetroSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 4:
				tetroSpr.setTexture(oTex);
				tetroSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 5:
				tetroSpr.setTexture(sTex);
				tetroSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 6:
				tetroSpr.setTexture(tTex);
				tetroSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 7:
				tetroSpr.setTexture(zTex);
				tetroSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;

			default:
				break;
			}
		}

	}
}
void GestorGrafico::drawBg()
{
	window->draw(bgSpr);
}

void GestorGrafico::drawScore(int score, int lvl)
{
	std::string lev = "NIVEL ";
	std::string strScore = to_string(score);
	puntaje.setString(strScore);
	window->draw(puntaje);
	std::string strNivel = to_string(lvl);
	lev.append(strNivel);
	level.setString(lev);
	window->draw(level);
}

void GestorGrafico::drawNextPiece(Tetromino * nextPiece)
{
	for (int i = 0; i < nextPiece->getTetroHeight(); ++i)
	{
		for (int j = 1; j < nextPiece->getTetroWidth(); ++j) {
			int aux = nextPiece->getCell(j, i);
			switch (aux)
			{
			case 1:
				tetroSpr.setTexture(iTex);
				tetroSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 2:

				tetroSpr.setTexture(jTex);
				tetroSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 3:
				tetroSpr.setTexture(lTex);
				tetroSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 4:
				tetroSpr.setTexture(oTex);
				tetroSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 5:
				tetroSpr.setTexture(sTex);
				tetroSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 6:
				tetroSpr.setTexture(tTex);
				tetroSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;
			case 7:
				tetroSpr.setTexture(zTex);
				tetroSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(tetroSpr);
				break;

			default:
				break;
			}
		}

	}
	nextPiece->resetRotation();
}

sf::RenderWindow* GestorGrafico::getWindow()
{
	return window;
}


void GestorGrafico::playMusic()
{
	tetrisSong.play();
}

void GestorGrafico::stopMusic()
{

	tetrisSong.stop();
}

void GestorGrafico::pauseMusic()
{
	tetrisSong.pause();
}