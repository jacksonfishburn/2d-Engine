#include "Window.h"
#include <iostream>
#include <string>

Window::Window() :
	size(1280, 720),
	title("My Game"),
	view(window.getDefaultView())
{
	create();
	window.setFramerateLimit(120);
	window.setView(view);
}

Window::Window(const sf::Vector2u& size, const std::string& title) :
	size(size),
	title(title),
	view(window.getDefaultView()) 
{
	create();
	window.setFramerateLimit(120);
	window.setView(view);
}

void Window::setTitle(const std::string& newTitle)
{
	title = newTitle;
	create();
}


void Window::setSize(const sf::Vector2u& newSize)
{
	const size_t MIN_X = 100;
	const size_t MIN_Y = 100;
	const size_t MAX_X = 3840;
	const size_t MAX_Y = 2160;

	if (newSize.x < MIN_X || newSize.y < MIN_Y)
	{
		std::cerr << "Size input too small, using minimum size instead.\n";
		size.x = MIN_X;
		size.y = MIN_Y;
	}

	else if (newSize.x > MAX_X || newSize.y > MAX_Y)
	{
		std::cerr << "Size input too large, using maximum size instead.\n";
		size.x = MAX_X;
		size.y = MAX_Y;
	}
	else
	{
		size = newSize;
	}

	create();
}

void Window::resize(const sf::Event& event)
{
	size.x = event.size.width;
	size.y = event.size.height;
	view.setSize(size.x, size.y);
	view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
	window.setView(view);
}


sf::Vector2u Window::getSize()
{
	return size;
}

sf::RenderWindow& Window::getWindow()
{
	return window;
}

sf::View& Window::getView()
{
	return view;
}


void Window::create()
{
	view.setSize(size.x, size.y);
	view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
	window.create(sf::VideoMode(size.x, size.y), title);
}