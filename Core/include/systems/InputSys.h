#pragma once
#include <SFML/Graphics.hpp>

#include <unordered_map>
#include "Event.h"

struct KeyPress
{
    sf::Keyboard::Key key;
    std::unique_ptr<Event> event;
};

struct MouseClick
{
    sf::Mouse::Button click;
    std::unique_ptr<Event> event;
};

class InputSys
{
public:
    void checkFor(sf::Event input);

private:
    void KeyPressEvent();
    void MouseClickEvent();

    std::vector<KeyPress> keys;
    std::vector<MouseClick> mouses;

};
