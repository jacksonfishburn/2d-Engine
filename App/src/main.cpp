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
	s->setSprite(RESOURCES_PATH "snake.png");


	Movement* m = new Movement;
	m->speed = 10;


	Control* c = new Control;
	c->upKey = sf::Keyboard::W;
	c->downKey = sf::Keyboard::S;
	c->leftKey = sf::Keyboard::A;
	c->rightKey = sf::Keyboard::D;

	game.entity->addComponent(t);
	game.entity->addComponent(s);
	game.entity->addComponent(m);
	game.entity->addComponent(c);


	MovementSys mvmt;


	game.movement = mvmt;

	game.run();
}

