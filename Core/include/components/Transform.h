#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

struct Transform : public Component
{

	sf::Vector2f position;
	sf::Vector2f scale;
	float rotation;
	
};