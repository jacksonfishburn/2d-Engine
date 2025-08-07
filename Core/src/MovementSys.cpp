#include "MovementSys.h"
#include <iostream>
#include <cmath>

void MovementSys::move(Entity& entity)
{
	Transform* t = entity.getComponent<Transform>();
	Movement* m = entity.getComponent<Movement>();

	normalize(m->direction);

	t->position.x += m->direction.x * m->speed;
	t->position.y += m->direction.y * m->speed;
	m->direction = { 0,0 };
}

void MovementSys::controller(Entity& entity)
{
	Control* c = entity.getComponent<Control>();
	Movement* m = entity.getComponent<Movement>();

	if (sf::Keyboard::isKeyPressed(c->upKey)) m->direction.y = -1;
	if (sf::Keyboard::isKeyPressed(c->downKey)) m->direction.y = 1;
	if (sf::Keyboard::isKeyPressed(c->leftKey)) m->direction.x = -1;
	if (sf::Keyboard::isKeyPressed(c->rightKey)) m->direction.x = 1;
}


void MovementSys::update(Entity& entity)
{
	if (entity.hasComponent<Control>()) controller(entity);

	move(entity);
}


void MovementSys::normalize(sf::Vector2f& vec)
{
	float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);
	if (length != 0)
		vec = sf::Vector2f(vec.x / length, vec.y / length);
	else
		vec = sf::Vector2f(0.f, 0.f);
}
