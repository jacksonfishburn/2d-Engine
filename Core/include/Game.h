#pragma once
#include "Window.h"
#include "Entity.h"
#include "Renderer.h"

#include "components/Sprite.h"
#include "components/Transform.h"


class Game
{
public:

	void initGame();
	void update();
	void render();
	void run();
	void cleanup();

	Window& getGameWindow();

private:
	Window window;

};