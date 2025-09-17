#pragma once

#include "Window.h"
#include "Entity.h"
#include "Renderer.h"
#include "EventManager.h"

#include "systems/MovementSys.h"
#include "systems/InputSys.h"



class Game
{
	void initGame();
	void update();
	void render(sf::RenderWindow& window);
	void cleanup();

public:

	void run();

	void addEntity(Entity*& entity);
	Window& getGameWindow();
	InputSys inputs;

private:

	MovementSys movement;
	Window window;
	std::vector<std::unique_ptr<Entity>> entities;
	EventManager events;


};
