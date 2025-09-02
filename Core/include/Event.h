#pragma once

#include <functional>
#include "Entity.h"

class Event
{

public:

    void subscribe(std::function<void(Entity&)> func);
    void emit(Entity& entity);

    std::function<bool()> condition;

private:

    std::vector<std::function<void(Entity&)>> callbacks;

};
