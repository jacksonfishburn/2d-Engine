#include "Movement.h"

void Movement::move(Entity& entity)
{
	Transform* t = entity.getComponent<Transform>();

	normalize(direction);

	t->position.x += direction.x * speed;
	t->position.y += direction.y * speed;
}

void Movement::normalize(sf::Vector2f& vec)
{
	float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);
	if (length != 0)
		vec = sf::Vector2f(vec.x / length, vec.y / length);
	else
		vec = sf::Vector2f(0.f, 0.f);
}
