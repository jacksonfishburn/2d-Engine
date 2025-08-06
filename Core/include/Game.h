#pragma once

#include "Window.h"
#include "Entity.h"
#include "Renderer.h"

#include "MovementSys.h"

#include "components/Sprite.h"
#include "components/Transform.h"
#include "components/Control.h"


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
	MovementSys movement;

private:

	Window window;

};