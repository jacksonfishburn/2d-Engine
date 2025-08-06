#pragma once

#include <SFML/Graphics.hpp>

#include "Component.h"

struct Control : public Component
{

	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;
	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key leftKey;

};