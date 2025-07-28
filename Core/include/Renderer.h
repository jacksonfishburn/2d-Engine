#pragma once

#include "SFML/Graphics.hpp"

#include "Window.h"
#include "Entity.h"


struct Renderer
{
	void renderEntity(Window& window, Entity& entity);
	void renderAllEntities(Window& window, const std::vector<Entity*>& entities);
};