#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Window
{
public:
	Window();
	Window(const sf::Vector2u& size, const std::string& title);

	void setTitle(const std::string& newTitle);
	void setSize(const sf::Vector2u& newSize);
	void resize(sf::Event& event);

	sf::Vector2u getSize();
	sf::RenderWindow& getWindow();
	sf::View& getView();

private:
	sf::RenderWindow window;
	std::string title;
	sf::Vector2u size;
	sf::View view;

	void create();

};