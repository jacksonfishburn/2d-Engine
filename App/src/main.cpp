#include "Game.h"

int main()
{
	Game game;

#pragma region snake


	Entity* snake = new Entity;

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

	snake->addComponent(t);
	snake->addComponent(s);
	snake->addComponent(m);
	snake->addComponent(c);

	game.addEntity(snake);
	
	
#pragma endregion

#pragma region planet


	Entity* planet = new Entity;

	Transform* tp = new Transform;
	tp->rotation = 0;
	tp->position = { 100,100 };
	tp->scale = { 10.f,10.f };

	Sprite* sp = new Sprite;
	sp->setSprite(RESOURCES_PATH "ShatteredMoon.png");

	planet->addComponent(tp);
	planet->addComponent(sp);

	game.addEntity(planet);


#pragma endregion

	game.run();
}

