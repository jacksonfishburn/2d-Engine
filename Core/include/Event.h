#pragma once

#include <functional>
#include "Entity.h"

class Event
{

public:

    void subscribe(std::function<void()> func);
    void emit();

    std::function<bool()> condition;

private:

    std::vector<std::function<void()>> callbacks;

};
