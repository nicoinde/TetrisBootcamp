#pragma once
#include "SFML\Graphics.hpp"

class Gestor
{
public:
	Gestor();
	~Gestor();
	sf::RenderWindow ventana;
	bool cargarImagenes();
	sf::Event getEvent();
	sf::RenderWindow getVentana();
	bool openWindow();
	sf::Sprite bg, i, j, l, o, s, t, z;

private:
	//sf::RenderWindow ventana;

	sf::Event event;
	sf::Texture bgTex, iTex, jTex, lTex, oTex, sTex, tTex, zTex;
	
};

