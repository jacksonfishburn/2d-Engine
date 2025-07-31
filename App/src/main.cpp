#include "Game.h"

int main()
{
	Game game;

	game.entity = new Entity;

	Transform* t = new Transform;
	t->position = { 100,100 };
	t->rotation = 0;
	t->scale = { 1.f,1.f };

	Sprite* s = new Sprite;
	s->setSprite(RESOURCES_PATH "Snake.png");

	game.entity->addComponent(t);
	game.entity->addComponent(s);

	EventSys es;
	Movement mvmt;

	game.eventSys = es;
	game.movement = mvmt;

	game.run();
}

