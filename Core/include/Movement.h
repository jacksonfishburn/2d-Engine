#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"

class Movement
{
public:

	void move(Entity& entity);
	sf::Vector2f direction{ 0,0 };


private:

	float speed = 10;
	void normalize(sf::Vector2f& vec);
};