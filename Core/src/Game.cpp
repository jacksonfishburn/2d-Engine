#include "Game.h"
#include <iostream>


void Game::initGame()
{

}


void Game::update()
{
	movement.update(entities);
}


void Game::render(sf::RenderWindow& window)
{
	Renderer r;
	r.renderAllEntities(window, entities);
}


void Game::cleanup()
{

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
			inputs.checkFor(event);
		}

		update();

		win.clear();
		render(win);
	}
	cleanup();
}


void Game::addEntity(Entity*& entity)
{
	entities.push_back(std::unique_ptr<Entity>(entity));
}


Window& Game::getGameWindow()
{
	return window;
}
