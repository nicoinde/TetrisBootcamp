#include "Gestor.h"



Gestor::Gestor()
{
	/*ventana.setSize(sf::Vector2u(412, 600));
	ventana.setTitle("Tetris");*/
	ventana.create(sf::VideoMode(500, 600), "tete");
}


Gestor::~Gestor()
{
}

bool Gestor::cargarImagenes() {
	if (!bgTex.loadFromFile("Assets/bg.png")) {
		return false;
	}
	else {
		bg.setTexture(bgTex);
		bg.setPosition(0.0, 0.0);
	}
	if (!iTex.loadFromFile("Assets/i.png")) {
		return false;
	}
	else {
		i.setTexture(iTex);
	}
	if (!jTex.loadFromFile("Assets/j.png")) {
		return false;
	}
	else {
		j.setTexture(jTex);
	}
	if (!lTex.loadFromFile("Assets/l.png")) {
		return false;
	}
	else {
		l.setTexture(lTex);
	}
	if (!oTex.loadFromFile("Assets/o.png")) {
		return false;
	}
	else {
		o.setTexture(oTex);
	}
	if (!sTex.loadFromFile("Assets/s.png")) {
		return false;
	}
	else {
		s.setTexture(sTex);
	}
	if (!tTex.loadFromFile("Assets/t.png")) {
		return false;
	}
	else {
		t.setTexture(tTex);
	}
	if (!zTex.loadFromFile("Assets/z.png")) {
		return false;
	}
	else {
		z.setTexture(zTex);
	}
	
	return true;
}

//sf::RenderWindow Gestor::getVentana() {
//	return 
//		;
//}