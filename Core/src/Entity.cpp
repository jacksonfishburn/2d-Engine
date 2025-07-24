#include "Entity.h"

void Entity::setTransform(
	sf::Vector2f newPosition = {-99999.f, -99999.f},
	float newRotation = 181.f,
	float newScale = -1.f )
{
	if (newPosition.x == -99999.f) newPosition = position;
	else if (newRotation == -181.f) newRotation = rotation;
	else if (newScale == -1.f) newScale = scale;

	else
	{
		position = newPosition;
		rotation = newRotation;
		scale = newScale;
	}
	
}

void Entity::setSprite(sf::Texture texture)
{
	sprite.setTexture(texture);
	sprite.setScale(scale, scale);
	sprite.setPosition(position);
}

void Entity::setSpriteFromSheet(const sf::Texture& texture, const sf::Vector2f& gridDimension, const sf::Vector2f& tile)
{
	sprite.setTexture(texture);
	sprite.setScale(scale, scale);
	sprite.setPosition(position);

	sf::Vector2f tileSize{ texture.getSize().x / gridDimension.x, texture.getSize().y / gridDimension.y };

	sprite.setTextureRect(sf::IntRect(tile.x * tileSize.x, tile.y * tileSize.y, tileSize.x, tileSize.y));
}



sf::Vector2f Entity::getPosition()
{
	return position;
}

float Entity::getRotation()
{
	return rotation;
}

float Entity::getScale()
{
	return scale;
}


