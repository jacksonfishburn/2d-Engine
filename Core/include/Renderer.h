#pragma once

#include "SFML/Graphics.hpp"

#include "Window.h"
#include "Entity.h"


struct Renderer
{
	void renderEntity(sf::RenderWindow& window, Entity& entity);
	void renderAllEntities(sf::RenderWindow& window, const std::vector<Entity*>& entities);
};