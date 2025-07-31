#include "Game.h"
#include <iostream>

void Game::initGame()
{

}


void Game::update()
{
	movement.move(*entity);
	movement.direction = { 0,0 };

}


void Game::render(sf::RenderWindow& window)
{
	Renderer r;
	r.renderEntity(window, *entity);
}


void Game::run()
{
	sf::RenderWindow& win = window.getWindow();

	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
			if (event.type == sf::Event::Resized)
				window.resize(event);
		}

		if (eventSys.checkForInput(sf::Keyboard::W)) movement.direction.y = -1;
		if (eventSys.checkForInput(sf::Keyboard::S)) movement.direction.y = 1;
		if (eventSys.checkForInput(sf::Keyboard::A)) movement.direction.x = -1;
		if (eventSys.checkForInput(sf::Keyboard::D)) movement.direction.x = 1;
		update();

		win.clear();
		render(win);

	}
}

void Game::cleanup()
{
}



Window& Game::getGameWindow()
{
	return window;
}
