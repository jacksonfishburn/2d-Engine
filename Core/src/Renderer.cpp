#include "Renderer.h"


void Renderer::renderEntity(Window& windowObj, Entity& entity)
{
	Sprite* spriteComp = entity.getComponent<Sprite>();
	Transform* transformComp = entity.getComponent<Transform>(); 

	sf::RenderWindow& window = windowObj.getWindow();

	spriteComp->sprite.setPosition(transformComp->position);
	spriteComp->sprite.setScale(transformComp->scale);
	spriteComp->sprite.setRotation(transformComp->rotation);

	window.draw(spriteComp->sprite);
}


void Renderer::renderAllEntities(Window& windowObj, const std::vector<Entity*>& entities)
{

}
