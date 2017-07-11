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
	while (ges.getVentana()->isOpen()) {
		draw();
		while (ges.getVentana()->pollEvent(ges.event)) {
			if (ges.event.type == sf::Event::EventType::Closed) {
				ges.getVentana()->close();
			}

			if (ges.event.type == sf::Event::EventType::KeyPressed) {
				//juego.tick(ges.getEvent().key.code);
				switch (ges.event.key.code) {
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
			if (ges.event.type == sf::Event::EventType::KeyReleased) {
				if (ges.event.key.code == sf::Keyboard::S|| ges.event.key.code == sf::Keyboard::Down) {
					juego.releaseFastDown();
				}
			}
			//std::this_thread::sleep_for(std::chrono::milliseconds(100));

		}

		if (clock.getElapsedTime().asSeconds() > juego.getIntervalo()) {
			juego.stepDown();
			clock.restart();
		}
		/*draw();*/
		if (juego.getEndGame())
		{
			//a pretty lame excuse of an EndGame Sign until i found something better
			juego.showEndGame();
			ges.pauseMusic();
			juego.stop();
		}
	}
	return 0;
}

void App::draw()
{
	ges.getVentana()->clear();
	ges.drawBg();
	ges.drawPieces(juego.tablero);
	ges.drawScore(juego.getScore(), juego.getNivel());
	ges.drawPiezaSig(juego.getPiezaSig());
	ges.getVentana()->display();
}
