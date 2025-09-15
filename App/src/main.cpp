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


	Event moveUp, moveDown, moveRight, moveLeft;

	moveUp.subscribe([snake]() {
		Movement* m = snake->getComponent<Movement>();
		m->direction.y = -1;
	});
	moveDown.subscribe([snake]() {
		Movement* m = snake->getComponent<Movement>();
		m->direction.y = 1;
	});
	moveLeft.subscribe([snake]() {
		Movement* m = snake->getComponent<Movement>();
		m->direction.x = -1;
	});
	moveRight.subscribe([snake]() {
		Movement* m = snake->getComponent<Movement>();
		m->direction.x = 1;
	});

	Event stopMovingY;
	stopMovingY.subscribe([snake]() {
		Movement* m = snake->getComponent<Movement>();
		m->direction.y = 0;
	});

	Event stopMovingX;
	stopMovingX.subscribe([snake]() {
		Movement* m = snake->getComponent<Movement>();
		m->direction.x = 0;
	});

	game.inputs.addKeyPress(sf::Keyboard::W, moveUp);
	game.inputs.addKeyPress(sf::Keyboard::S, moveDown);
	game.inputs.addKeyPress(sf::Keyboard::D, moveRight);
	game.inputs.addKeyPress(sf::Keyboard::A, moveLeft);

	game.inputs.addKeyRelease(sf::Keyboard::W, stopMovingY);
	game.inputs.addKeyRelease(sf::Keyboard::S, stopMovingY);
	game.inputs.addKeyRelease(sf::Keyboard::D, stopMovingX);
	game.inputs.addKeyRelease(sf::Keyboard::A, stopMovingX);

	snake->addComponent(t);
	snake->addComponent(s);
	snake->addComponent(m);

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

