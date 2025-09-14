#include "Event.h"

void Event::subscribe(std::function<void()> func)
{
    callbacks.push_back(func);
}

void Event::emit()
{
    for (auto& cb : callbacks)
    {
        cb();
    }
}
