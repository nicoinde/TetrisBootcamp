#include "App.h"
#include <chrono>
#include <thread>





App::App() :modified(true)
{
}


int main(int argc, char** argv) {
	App app;
	app.loop();
	return 0;
}

App::~App()
{
	
}

int App::loop() {
	sf::Clock clock;
	clock.restart();
	ges.playMusic();
	while (ges.getWindow()->isOpen()) {
		draw();
		while (ges.getWindow()->pollEvent(ges.getEvent())) {
			if (ges.getEvent().type == sf::Event::EventType::Closed) {
				ges.getWindow()->close();
			}

			if (ges.getEvent().type == sf::Event::EventType::KeyPressed) {
				//juego.tick(ges.getEvent().key.code);
				switch (ges.getEvent().key.code) {
				case sf::Keyboard::Escape:
				case sf::Keyboard::Q:
					ges.getWindow()->close();
					break; 
				case sf::Keyboard::A:
				case sf::Keyboard::Left:
					juego.moveLeft();
					break; 
				case sf::Keyboard::W:
				case sf::Keyboard::Up:
					juego.rotateTetro();
					break;
				case sf::Keyboard::D:
				case sf::Keyboard::Right:
					juego.moveRight();
					break;
				case sf::Keyboard::R:
					juego.restart();
					break;

				case sf::Keyboard::T:
					juego.stepDown();
					break;
				case sf::Keyboard::S:
				case sf::Keyboard::Down:
					juego.fastDown();
					break;

				default:break;
				}
			}
			if (ges.getEvent().type == sf::Event::EventType::KeyReleased) {
				if (ges.getEvent().key.code == sf::Keyboard::S|| ges.getEvent().key.code == sf::Keyboard::Down) {
					juego.releaseFastDown();
				}
			}

		}

		if (clock.getElapsedTime().asSeconds() > juego.getInterval()) {
			juego.stepDown();
			clock.restart();
		}
		/*draw();*/
		if (juego.getEndGame())
		{
			//a pretty lame excuse of an EndGame Sign until i found something better
			ges.pauseMusic();
			bool restart = juego.restartGame();
			if (restart) {
				ges.playMusic();
			}
			else {
				ges.getWindow()->close();
			}
		}
	}
	return 0;
}

void App::draw()
{
	ges.getWindow()->clear();
	ges.drawBg();
	ges.drawPieces(juego.getBoard());
	ges.drawScore(juego.getScore(), juego.getLevel());
	ges.drawNextPiece(juego.getNextPiece());
	ges.getWindow()->display();
}
