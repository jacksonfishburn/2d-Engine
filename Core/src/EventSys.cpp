#include <SFML/Graphics.hpp>

#include "EventSys.h"

bool EventSys::checkForInput(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}
