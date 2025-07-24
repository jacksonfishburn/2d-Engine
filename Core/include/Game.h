#pragma once
#include "Window.h"


class Game
{
public:
	Game();

	void run();
	void cleanup();

	Window& getGameWindow();

private:
	Window window;

};