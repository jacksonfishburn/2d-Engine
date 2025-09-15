#include "systems/InputSys.h"

void InputSys::checkFor(sf::Event& input)
{
    if (input.type == sf::Event::KeyPressed) KeyPressEvent(input);
    if (input.type == sf::Event::MouseButtonPressed) MouseClickEvent(input);
    if (input.type == sf::Event::KeyReleased) KeyReleasedEvent(input);
}


void InputSys::addKeyPress(sf::Keyboard::Key key, Event& event)
{
    KeyPress newKeyPress;
    newKeyPress.key = key;
    newKeyPress.event = std::make_unique<Event>(event);
    keyPresses.push_back(std::move(newKeyPress));
}


void InputSys::addMouseClick(sf::Mouse::Button button, sf::IntRect rect, Event& event)
{
    MouseClick newMouseClick;
    newMouseClick.button = button;
    newMouseClick.clickArea = rect;
    newMouseClick.event = std::make_unique<Event>(event);
    mouseClicks.push_back(std::move(newMouseClick));
}

void InputSys::addKeyRelease(sf::Keyboard::Key key, Event& event)
{
    KeyRelease newKeyRelease;
    newKeyRelease.key = key;
    newKeyRelease.event = std::make_unique<Event>(event);
    keyReleases.push_back(std::move(newKeyRelease));
}



void InputSys::KeyPressEvent(sf::Event& input)
{
    for ( auto& keyPress : keyPresses )
    {
        if (keyPress.key == input.key.code)
        {
            keyPress.event->emit();
        }
    }
}


void InputSys::MouseClickEvent(sf::Event& input)
{
    for ( auto& mouseClick : mouseClicks)
    {
        if (mouseClick.button == input.mouseButton.button)
        {
            mouseClick.event->emit();
        }
    }
}

void InputSys::KeyReleasedEvent(sf::Event& input)
{
    for ( auto& keyRel : keyReleases )
    {
        if (keyRel.key == input.key.code)
        {
            keyRel.event->emit();
        }
    }
}
