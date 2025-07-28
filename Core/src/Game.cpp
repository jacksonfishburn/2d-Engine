#include "Game.h"
#include <iostream>

void Game::initGame()
{

}

void Game::update()
{

}

void Game::render()
{

}

void Game::run()
{
	Entity snake;

	Transform t;
	t.position = { 100,100 };
	t.rotation = 0;
	t.scale = { 1,1 };

	std::cout << RESOURCES_PATH << "snake.png\n";

	Sprite s;
	s.setSprite(RESOURCES_PATH "snake.png");


	Renderer r;

	sf::RenderWindow& win = window.getWindow();

	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
			window.resize(event);
		}

		r.renderEntity(window, snake);
	}
}

void Game::cleanup()
{
}



Window& Game::getGameWindow()
{
	return window;
}
