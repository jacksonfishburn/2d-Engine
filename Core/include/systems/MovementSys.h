#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "components/Movement.h"
#include "components/Control.h"

class MovementSys
{
public:


	void update(std::vector<std::unique_ptr<Entity>>& entities);

private:

	void move(std::unique_ptr<Entity>& entity);

	void controller(std::unique_ptr<Entity>& entity);

	void normalize(sf::Vector2f& vec);

};