#include <iostream>
#include <cstring>
using namespace std;
#include "Targaryen_Stark.h"

Targaryen_Stark::Targaryen_Stark():Human(),Stark(),Targaryen()
{}


int Targaryen_Stark::getLoyalnost() const
{
    return loyalnost + size + Targaryen::getAge();
}

const char* Targaryen_Stark::getSpecialSkill() const
{
    // well :D
    // ok fine
    return "I am the son of fire and ice!";
}

int Targaryen_Stark::getOcenkaOtmashtenie() const
{
    return Stark::getOcenkaOtmashtenie();
}

char* Targaryen_Stark::getType() const
{
    return "I am the son of fire and ice!";
}

void Targaryen_Stark::setLoyalnost(int loyalnost)
{
    Human::setLoyalnost(loyalnost - size - Targaryen::getAge());
}

void Targaryen_Stark::setName(const char* name)
{
    size_t length = strlen(name);
    char* newName = new char [length + 6];
    strncpy(newName, name, length);
    // ahahahahhahaha niceee
    // ... :D
    newName[length] =
    newName[length + 1] = ' ';
    newName[length + 2] = 'S';
    newName[length + 3] = 'n';
    newName[length + 4] = 'o';
    newName[length + 5] = 'w';
    newName[length + 6] = '\n';
    Human::setName(newName);
}

void Targaryen_Stark::addFriend(Human* newFriend)
{
    if(size == capacity)
        cout << "Maksimumat priqteli e dostignat\n";
    else
    {
        priqteli[size++] = newFriend;
    }
}

