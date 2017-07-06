#include "GestorGrafico.h"


const sf::Vector2u sizeVentana(412, 600); 


GestorGrafico::GestorGrafico(): offsetX(5.0),offsetY(5.0), squareOffset(30.0)
{
	ventana = new sf::RenderWindow (sf::VideoMode(412, 600), "Tetris");
	cargarImagenes();
}


GestorGrafico::~GestorGrafico()
{
}

bool GestorGrafico::cargarImagenes() {
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
		iSpr.setScale(1.05f, 1.05f);
	}
	if (!jTex.loadFromFile("Assets/j.png")) {
		return false;
	}
	else {
		jSpr.setTexture(jTex);
		jSpr.setScale(1.05f, 1.05f);
	}
	if (!lTex.loadFromFile("Assets/l.png")) {
		return false;
	}
	else {
		lSpr.setTexture(lTex);
		lSpr.setScale(1.05f, 1.05f);
	}
	if (!oTex.loadFromFile("Assets/o.png")) {
		return false;
	}
	else {
		oSpr.setTexture(oTex);
		oSpr.setScale(1.05f, 1.05f);
	}
	if (!sTex.loadFromFile("Assets/s.png")) {
		return false;
	}
	else {
		sSpr.setTexture(sTex);
		sSpr.setScale(1.05f, 1.05f);
	}
	if (!tTex.loadFromFile("Assets/t.png")) {
		return false;
	}
	else {
		tSpr.setTexture(tTex);
		tSpr.setScale(1.05f, 1.05f);
	}
	if (!zTex.loadFromFile("Assets/z.png")) {
		return false;
	}
	else {
		zSpr.setTexture(zTex);
		zSpr.setScale(1.05f, 1.05f);
	}
	
	return true;
}

sf::Event GestorGrafico::getEvent()
{
	return event;
}

sf::Clock GestorGrafico::getClock()
{
	return clock;
}

void GestorGrafico::drawPieces(Board &tablero)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 20; ++j) {
			switch (tablero.getTablero()[i][j])
			{
			case 1:
				iSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				ventana->draw(iSpr);
				break;
			case 2:
				jSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				ventana->draw(jSpr);
				break;
			case 3:
				lSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				ventana->draw(lSpr);
				break;
			case 4:
				oSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				ventana->draw(oSpr);
				break;
			case 5:
				sSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				ventana->draw(sSpr);
				break;
			case 6:
				tSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				ventana->draw(tSpr);
				break;
			case 7:
				zSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				ventana->draw(zSpr);
				break;

			default:
				break;
			}
		}
	}
}

void GestorGrafico::drawBg()
{
	ventana->draw(bgSpr);
}

sf::RenderWindow* GestorGrafico::getVentana()
{
	return ventana;
}

void GestorGrafico::trySprites(sf::RenderWindow &vent) {
		sSpr.setPosition(75, 120);
		vent.draw(sSpr);
		zSpr.setPosition(145,265);
		vent.draw(zSpr);
		sSpr.setPosition(175, 220);
		vent.draw(sSpr);
	
}