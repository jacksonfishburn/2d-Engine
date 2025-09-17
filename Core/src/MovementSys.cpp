#include "systems/MovementSys.h"
#include <iostream>
#include <cmath>

void MovementSys::move(std::unique_ptr<Entity>& entity)
{
	Transform* t = entity->getComponent<Transform>();
	Movement* m = entity->getComponent<Movement>();

	normalize(m->direction);

	t->position.x += m->direction.x * m->speed;
	t->position.y += m->direction.y * m->speed;

}



void MovementSys::update(std::vector<std::unique_ptr<Entity>>& entities)
{
	for (auto& entity : entities)
	{
		if (entity->hasComponent<Movement>()) move(entity);
	}
}


void MovementSys::normalize(sf::Vector2f& vec)
{
	float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);
	if (length != 0)
		vec = sf::Vector2f(vec.x / length, vec.y / length);
	else
		vec = sf::Vector2f(0.f, 0.f);
}
