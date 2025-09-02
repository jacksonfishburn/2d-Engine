#pragma once

#include "Event.h"

class EventManager
{
    
public:

    void update();
    
    void addEvent(const Event& event);
    void removeEvent(Event& event);

private:

    std::vector<std::unique_ptr<Event>> events;

};
