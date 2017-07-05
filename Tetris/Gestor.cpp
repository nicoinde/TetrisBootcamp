#include "Gestor.h"


const sf::Vector2u sizeVentana(412, 600);

Gestor::Gestor()
{
	/*ventana.setSize(sf::Vector2u(412, 600));
	ventana.setTitle("Tetris");*/
	
		//ventana.create(sf::VideoMode(500, 600), "tete");
	//ventana.setSize(sizeVentana);
	//ventana.setTitle("Tetris");
	cargarImagenes();
}


Gestor::~Gestor()
{
}

bool Gestor::cargarImagenes() {
	if (!bgTex.loadFromFile("Assets/bg.png")) {
		return false;
	}
	else {
		bgSpr.setTexture(bgTex);
		bgSpr.setPosition(0.0, 0.0);
	}
	if (!iTex.loadFromFile("Assets/i.png")) {
		return false;
	}
	else {
		iSpr.setTexture(iTex);
		iSpr.setScale(1.05, 1.05);
	}
	if (!jTex.loadFromFile("Assets/j.png")) {
		return false;
	}
	else {
		jSpr.setTexture(jTex);
		jSpr.setScale(1.05, 1.05);
	}
	if (!lTex.loadFromFile("Assets/l.png")) {
		return false;
	}
	else {
		lSpr.setTexture(lTex);
		lSpr.setScale(1.05, 1.05);
	}
	if (!oTex.loadFromFile("Assets/o.png")) {
		return false;
	}
	else {
		oSpr.setTexture(oTex);
		oSpr.setScale(1.05, 1.05);
	}
	if (!sTex.loadFromFile("Assets/s.png")) {
		return false;
	}
	else {
		sSpr.setTexture(sTex);
		sSpr.setScale(1.05, 1.05);
	}
	if (!tTex.loadFromFile("Assets/t.png")) {
		return false;
	}
	else {
		tSpr.setTexture(tTex);
		tSpr.setScale(1.05, 1.05);
	}
	if (!zTex.loadFromFile("Assets/z.png")) {
		return false;
	}
	else {
		zSpr.setTexture(zTex);
		zSpr.setScale(1.05, 1.05);
	}
	
	return true;
}

void Gestor::drawPieces(sf::RenderWindow & vent, int ** tablero)
{
	for (short i = 0; i < 10; ++i)
	{
		for (short j = 0; j < 20; ++j) {
			switch (tablero[i][j])
			{
			case 1:
				iSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				vent.draw(iSpr);
				break;
			case 2:
				jSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				vent.draw(jSpr);
				break;
			case 3:
				lSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				vent.draw(lSpr);
				break;
			case 4:
				oSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				vent.draw(oSpr);
				break;
			case 5:
				sSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				vent.draw(sSpr);
				break;
			case 6:
				tSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				vent.draw(tSpr);
				break;
			case 7:
				zSpr.setPosition(offsetX + i*squareOffset, offsetY + j*squareOffset);
				vent.draw(zSpr);
				break;

			default:
				break;
			}
		}
	}
}

//sf::RenderWindow* Gestor::getVentana()
//{
//	return ventana;
//}
//
//void Gestor::setVentana(sf::RenderWindow vent)
//{
//	ventana = &vent;
//}

//void Gestor::drawTablero(int tablero[22][13])
//{
//	
//}



//sf::RenderWindow Gestor::getVentana() {
//	return 
//		;
//}

void Gestor::trySprites(sf::RenderWindow &vent) {
	/*for (float i = 0; i < 190; 15+i)
	{*/
		sSpr.setPosition(75, 120);
		vent.draw(sSpr);
		zSpr.setPosition(145,265);
		vent.draw(zSpr);
		sSpr.setPosition(175, 220);
		vent.draw(sSpr);
	//}
}