#include "SFML/Graphics.hpp"

class Entity
{
public:

	void setTransform(sf::Vector2f position, float rotation, float scale);
	void setSprite(sf::Texture texture);
	void setSpriteFromSheet(const sf::Texture& texture, const sf::Vector2f& gridDimension, const sf::Vector2f& tile);

	sf::Vector2f getPosition();
	float getRotation();
	float getScale();

private:
	sf::Vector2f position;
	sf::Sprite sprite;
	float rotation;
	float scale;
};