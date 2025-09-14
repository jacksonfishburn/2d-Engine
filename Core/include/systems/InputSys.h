#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "Event.h"
#include "Entity.h"

struct KeyPress
{
    sf::Keyboard::Key key;
    std::unique_ptr<Event> event;
};

struct MouseClick
{
    sf::Mouse::Button button;
    sf::IntRect clickArea;
    std::unique_ptr<Event> event;
};

class InputSys
{
public:
    void checkFor(sf::Event& input);

    void addKeyPress(sf::Keyboard::Key key, Event& event);
    void addMouseClick(sf::Mouse::Button button, sf::IntRect rect, Event& event);

private:
    void KeyPressEvent(sf::Event& input);
    void MouseClickEvent(sf::Event& input);

    std::vector<KeyPress> keyPresses;
    std::vector<MouseClick> mouseClicks;

};
