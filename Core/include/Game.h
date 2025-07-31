#pragma once

#include "Window.h"
#include "Entity.h"
#include "Renderer.h"

#include "EventSys.h"
#include "Movement.h"

#include "components/Sprite.h"
#include "components/Transform.h"


class Game
{
public:

	void initGame();
	void update();
	void render(sf::RenderWindow& window);
	void run();
	void cleanup();

	Window& getGameWindow();

	Entity* entity;
	EventSys eventSys;
	Movement movement;

private:

	Window window;

};