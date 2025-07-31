#include "Renderer.h"
#include <iostream>


void Renderer::renderEntity(sf::RenderWindow& window, Entity& entity)
{
	Sprite* spriteComp = entity.getComponent<Sprite>();
	Transform* transformComp = entity.getComponent<Transform>();

	spriteComp->sprite.setPosition(transformComp->position);
	spriteComp->sprite.setScale(transformComp->scale);
	spriteComp->sprite.setRotation(transformComp->rotation);

	window.draw(spriteComp->sprite);
	window.display();
}


void Renderer::renderAllEntities(sf::RenderWindow& window, const std::vector<Entity*>& entities)
{

}
