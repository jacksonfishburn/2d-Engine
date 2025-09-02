#include "Event.h"



void Event::subscribe(std::function<void(Entity&)> func)
{
    callbacks.push_back(func);
}

void Event::emit(Entity& entity)
{
    for (auto& cb : callbacks)
    {
        cb(entity);
    }
}
