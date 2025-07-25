#pragma once
#include "Window.h"


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