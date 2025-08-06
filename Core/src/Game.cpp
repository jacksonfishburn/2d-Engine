#include "Game.h"
#include <iostream>

void Game::initGame()
{

}


void Game::update()
{
	movement.update(*entity);
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

		update();

		win.clear();
		render(win);

	}
	cleanup();
}

void Game::cleanup()
{
	delete entity;
}



Window& Game::getGameWindow()
{
	return window;
}
