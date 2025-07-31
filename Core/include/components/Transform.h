#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

struct Transform : public Component
{

	sf::Vector2f position = { 0.f, 0.f };
	sf::Vector2f scale = { 1.f, 1.f };
	float rotation = 0.f;

};