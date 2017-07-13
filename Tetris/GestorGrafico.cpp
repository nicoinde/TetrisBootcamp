#include "GestorGrafico.h"
#include <string.h>
using namespace std;

const sf::Vector2u sizeVentana(412, 600);
const float piezaSigOffsetX = 312.0;
const float piezaSigOffsetY = 39.0;


GestorGrafico::GestorGrafico() : offsetX(-19.0), offsetY(-48), squareOffset(29.0)
{
	window = new sf::RenderWindow(sf::VideoMode(412, 600), "Tetris");
	loadFiles();
}


GestorGrafico::~GestorGrafico()
{
	//delete window;
}

bool GestorGrafico::loadFiles() {
	if (!bgTex.loadFromFile("Assets/bg.png")) {
		return false;
	}
	else {
		bgSpr.setTexture(bgTex);
		bgSpr.setPosition(0.0f, 0.0f);
	}
	if (!iTex.loadFromFile("Assets/i.png")) {
		return false;
	}
	else {
		iSpr.setTexture(iTex);
		iSpr.setScale(1.04f, 1.04f);
	}
	if (!jTex.loadFromFile("Assets/j.png")) {
		return false;
	}
	else {
		jSpr.setTexture(jTex);
		jSpr.setScale(1.04f, 1.04f);

	}
	if (!lTex.loadFromFile("Assets/l.png")) {
		return false;
	}
	else {
		lSpr.setTexture(lTex);
		lSpr.setScale(1.04f, 1.04f);

	}
	if (!oTex.loadFromFile("Assets/o.png")) {
		return false;
	}
	else {
		oSpr.setTexture(oTex);
		oSpr.setScale(1.04f, 1.04f);
	}
	if (!sTex.loadFromFile("Assets/s.png")) {
		return false;
	}
	else {
		sSpr.setTexture(sTex);
		sSpr.setScale(1.04f, 1.04f);
	}
	if (!tTex.loadFromFile("Assets/t.png")) {
		return false;
	}
	else {
		tSpr.setTexture(tTex);
		tSpr.setScale(1.04f, 1.04f);
	}
	if (!zTex.loadFromFile("Assets/z.png")) {
		return false;
	}
	else {
		zSpr.setTexture(zTex);
		zSpr.setScale(1.04f, 1.04f);
	}

	if (!font.loadFromFile("Assets/Coffee House.ttf")) {
		return false;
	}
	else {
		puntaje.setFont(font);
		puntaje.setPosition(312.0, 198.0);
		/*puntaje.setCharacterSize(25);*/
		puntaje.setFillColor(sf::Color::White);
		puntaje.setColor(sf::Color::Blue);

		nivel.setFont(font);
		nivel.setPosition(312.0, 238.0);
		nivel.setFillColor(sf::Color::White);
		nivel.setColor(sf::Color::Blue);
	}

	
	

	if (!tetrisSong.openFromFile("Assets/Tetris.ogg")) {
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
	for (int i = tablero.softUpperBorder; i < tablero.softBottomBorder; ++i)
	{
		for (int j = tablero.softLeftBorder; j < tablero.softRightBorder; ++j) {
			int aux = tablero.getCell(j, i);
			switch (aux)
			{
			case 1:
				iSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(iSpr);
				break;
			case 2:
				jSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(jSpr);
				break;
			case 3:
				lSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(lSpr);
				break;
			case 4:
				oSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(oSpr);
				break;
			case 5:
				sSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(sSpr);
				break;
			case 6:
				tSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(tSpr);
				break;
			case 7:
				zSpr.setPosition(offsetX + j*squareOffset, offsetY + i*squareOffset);
				window->draw(zSpr);
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
	std::string strScore = to_string(score);
	puntaje.setString(strScore);
	window->draw(puntaje);
	std::string strNivel = to_string(lvl);
	nivel.setString(strNivel);
	window->draw(nivel);
}

void GestorGrafico::drawPiezaSig(Tetromino * piezaSig)
{
	for (int i = 0; i < piezaSig->getTetroHeight(); ++i)
	{
		for (int j = 1; j < piezaSig->getTetroWidth(); ++j) {
			int aux = piezaSig->getCell(j, i);
			switch (aux)
			{
			case 1:
				iSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(iSpr);
				break;
			case 2:
				jSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(jSpr);
				break;
			case 3:
				lSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(lSpr);
				break;
			case 4:
				oSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(oSpr);
				break;
			case 5:
				sSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(sSpr);
				break;
			case 6:
				tSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(tSpr);
				break;
			case 7:
				zSpr.setPosition(piezaSigOffsetX + (j - 1)*squareOffset, piezaSigOffsetY + i*squareOffset);
				window->draw(zSpr);
				break;

			default:
				break;
			}
		}

	}
	piezaSig->resetRotation();
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