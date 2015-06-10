#include <iostream>
#include "Army.h"

Army::Army():
    lider(NULL),count(0)
{}

Army::Army(Army& other)
{
    for(int i = 0; i < other.count; i++)
        voinici[i] = other.voinici[i];
    count = other.count;
    lider = other.lider;
}

Army& Army::operator=(Army& other)
{
    if(this == &other)
        return *this;
    // not exactly
    for(int i = 0; i < other.count; i++)
        voinici[i] = other.voinici[i];
    count = other.count;
    lider = other.lider;
    return *this;
}
