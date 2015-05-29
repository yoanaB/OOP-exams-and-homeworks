#include <iostream>
#include <cstring>
using namespace std;

#include "RockStar.h"

RockStar::RockStar():
    name(NULL),awesomeness(0),numberOfFens(0){}

RockStar::RockStar(char* name, int awesomeness, unsigned numberOfFens):
    name(NULL),awesomeness(awesomeness),numberOfFens(numberOfFens)
{
    if(name != NULL)
    {
        size_t length = strlen(name) + 1;
        this -> name = new char [length];
        strncpy(this -> name, name, length);
    }
}

RockStar::~RockStar()
{
    delete [] name;
}

RockStar::RockStar(RockStar& other)
{
    awesomeness = other.awesomeness;
    numberOfFens = other.numberOfFens;
    if(other.name != NULL)
    {
        size_t length = strlen(other.name) + 1;
        name = new char [length];
        strncpy(name, other.name, length);
    }
    else
        name = NULL;
}
RockStar& RockStar::operator= (RockStar& other)
{
    if(this == & other)
        return *this;
    awesomeness = other.awesomeness;
    numberOfFens = other.numberOfFens;
    if(other.name != NULL)
    {
        if(name != NULL)
            delete [] name;
        size_t length = strlen(other.name) + 1;
        name = new char [length];
        strncpy(name, other.name, length);
    }
    else
        name = NULL;
        return *this;
}
// return awesomeness > other.awesomeness would work
bool RockStar::operator> (RockStar& other) const
{
    if(awesomeness > other.awesomeness)
        return 1;
    return 0;
}

bool RockStar::operator< (RockStar& other) const
{
    return !(*this > other);
}

bool RockStar::operator== (RockStar& other) const
{
    if (awesomeness == other.awesomeness)
        return 1;
    return 0;
}

void RockStar::setName (char* name)
{
    if(name != NULL)
    {
        if(this -> name != NULL)
            delete [] this -> name;
        size_t length = strlen(name) + 1;
        this -> name = new char [length];
        strncpy(this -> name, name, length);
    }
    else
        name = NULL;
}
void RockStar::setAwesomeness (int awesomeness)
{
    this -> awesomeness = awesomeness;
}

void RockStar::setNumberOfFens (unsigned numberOfFens)
{
    this -> numberOfFens = numberOfFens;
}

void RockStar::print () const
{
    cout << "Name: " << name
         << "\nAwesomeness: " << awesomeness
         << "\nNumber of fens: " << numberOfFens << endl;
}


const char* RockStar::getName () const
{
    return name;
}

int RockStar::getAwesomeness () const
{
    return awesomeness;
}

unsigned RockStar::getNumberOfFens () const
{
    return numberOfFens;
}

