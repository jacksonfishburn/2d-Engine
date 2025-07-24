#include "Game.h"

Game::Game() 
{
	
}

void Game::run()
{
	sf::CircleShape circle;
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition({ 100, 100 });
	circle.setRadius(100);

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

		win.clear();
		win.draw(circle);
		win.display();
	}
}

void Game::cleanup()
{
}



Window& Game::getGameWindow()
{
	return window;
}
