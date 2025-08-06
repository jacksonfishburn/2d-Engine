#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "components/Movement.h"
#include "components/Control.h"

class MovementSys
{
public:


	void update(Entity& entity);

private:

	void move(Entity& entity);

	void controller(Entity& entity);

	void normalize(sf::Vector2f& vec);

};